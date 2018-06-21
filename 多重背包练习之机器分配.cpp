/* 
    Name: 机器分配 
    Copyright:  
    Author:  
    Date: 29-07-17 16:12 
    Description: 机器分配  
总公司拥有高效设备M台，准备分给下属的N个分公司。各分公司若获得这些设备，可以为国家提供一定的盈利。问：如何分配这M台设备才能使国家得到的盈利最大？求出最大盈利值。其中M≤15，N≤10。分配原则：每个公司有权获得任意数目的设备，但总台数不超过设备数M。  
Input 
输入数据文件格式为：第一行有两个数，第一个数是分公司数N，第二个数是设备台数M。  
接下来是一个N*M的矩阵，表明了第 I个公司分配 J台机器的盈利。 
Output 
输出第一行为最大盈利值；  
接下来有n行，分别为各分公司分配的机器数。 
Sample Input 
3 3  {三个分公司分3台机器}   
30 40 50 
20 30 50 
20 25 30 
Sample Output 
70   {最大盈利值为70} 
1 1  {第一分公司分1台} 
2 1  {第二分公司分1台} 
3 1  {第三分公司分1台} 
 
算法分析：  
状态转移方程： 
F[i][j] = max(F[i-1][j-k] + V[i][k])  ( 0<=k<=j) 
F[i][j]代表j台机子分给前i个公司的最大收益，V[i][k]表示第i个公司分配k台的收益 
仔细分析题目，这很像一个多重背包问题！但因为给第i个公司分配k台机器，不是简单的做k次0-1选择， 
而是做0-k选择，所以只能用朴素的穷举思想解，而不能用相对简单的对第i公司进行k次0-1选择的算法。  
*/  
#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
const int MAXC = 10; //子公司数量   
const int MAXM = 15; //机器数量   
int V[MAXC+1][MAXM+1];//盈利矩阵   
int B1[MAXC+1][MAXM+1]; //记录给定n个子公司分配m台机器的最大盈利   
int B2[MAXC+1][MAXM+1]; //记录给定n个子公司分配m台机器的最大盈利   
int pre[MAXM+1]; //pre[j]相当于B1[i-1][j]   
int cur[MAXM+1]; //cur[j]相当于B1[i][j]  
int F1[MAXM+1]; //记录最优解   
int X[MAXC+1]; //记录各分公司分配的机器数  
int BX[MAXC+1]; //记录各分公司分配的机器数  
int bestValue; //用回溯算法解时用来记录最大盈利   
  
int Best_1(int n, int m);//动态规划:二维数组存储结果   
int Best_2(int n, int m);//优化的动态规划算法，用2个一维数组代替二维数组   
int Best_3(int n, int m);//进一步优化的动态规划算法，用1个一维数组代替二维数组   
void Show(int i, int j); //递归输出各分公司分配的机器数   
int Show_2(int n, int m); //利用数组B1[][]，输出各分公司分配的机器数，X[i]初始化为0   
void DFS(int n, int i, int j); //回溯算法  
int MDFS(int i, int j); //备忘录算法   
  
int main()   
{  
    int n, m;  
    cin >> n >> m;  
      
    for (int i=1; i<=n; i++)//不计下标为0的元素   
    {  
        for (int j=1; j<=m; j++)//不计下标为0的元素   
        {  
            cin >> V[i][j];  
        }  
    }  
      
    cout << Best_1(n, m) << endl;  
    cout << Best_2(n, m) << endl;  
    cout << Best_3(n, m) << endl;  
      
    Show(n, m);  
    cout << Show_2(n, m) << endl;  
      
    DFS(n, n, m);  
    cout << bestValue << endl;  
    for (int i=1; i<=n; i++)  
    {  
        cout << i << " " << BX[i] << endl;  
    }     
      
    cout << MDFS(n, m) << endl;  
  
   // system("pause");  
    return 0;  
}  
  
int Best_1(int n, int m)//动态规划:二维数组存储结果  
{  
    for (int i=1; i<=n; i++) //给定前i个公司   
    {  
        for (int j=1; j<=m; j++) //给定j台机器，j递增或递减均可   
        {//朴素的穷举思想，计算分k台机器给i公司时，获得多少价值，存储最大价值到B1[i][j]   
            int bestP = 0;  
            for (int k=0; k<=j; k++)  
            {  
                if (bestP < B1[i-1][j-k] + V[i][k])//分k台机器给i公司   
                    bestP = B1[i-1][j-k] + V[i][k];  
            }  
            B1[i][j] = bestP;  
        }  
    }  
      
    return B1[n][m];  
}  
  
int Best_2(int n, int m)//优化的动态规划算法，用2个一维数组代替二维数组   
{  
    //pre[j]相当于B1[i-1][j]，cur[j]相当于B1[i][j]   
    for (int j=1; j<=m; j++) //只有1个公司的情形  
        pre[j] = V[1][j];  
       
    for (int i=2; i<=n; i++) //给定前i个公司   
    {  
        for (int j=1; j<=m; j++) //给定j台机器，j递增或递减均可    
        {  
            int bestP = 0;  
            for (int k=0; k<=j; k++)  
            {  
                if (bestP < pre[j-k] + V[i][k])  
                    bestP = pre[j-k] + V[i][k];  
            }  
            cur[j] = bestP;  
        }  
        for (int j=1; j<=m; j++)  
        {  
            pre[j] = cur[j];   
        }  
    }  
      
    return pre[m];  
}  
  
int Best_3(int n, int m)//进一步优化的动态规划算法，用1个一维数组代替二维数组   
{  
    for (int i=1; i<=n; i++) //实际上就是一个多重背包问题   
    {  
        for (int j=m; j>0; j--) //类似于0-1背包问题，j只能递减  
        {  
            //朴素的穷举思想，计算分k台机器给i公司时，获得多少价值，存储最大价值到F1[j]   
            int bestP = 0;  
            for (int k=0; k<=j; k++)  
            {  
                if (bestP < F1[j-k] + V[i][k])  
                    bestP = F1[j-k] + V[i][k];  
            }  
            F1[j] = bestP;  
        }  
    }  
      
    return F1[m];  
}  
  
void Show(int i, int j)//递归输出各分公司分配的机器数    
{  
    if (i == 0 || j == 0)  
        return;  
    for (int k=0; k<=j; k++)  
    {    
        if (B1[i][j] == B1[i-1][j-k] + V[i][k])//分k台机器给i公司时，获得最大价值  
        {  
            Show(i-1, j-k);  
            cout << i << " " << k << endl;  
            break;  
        }  
    }  
}  
  
int Show_2(int n, int m) //利用数组B1[][]，输出各分公司分配的机器数，X[i]初始化为0   
{  
    for (int i=n,j=m; i>0; i--)  
    {  
        for (int k=0; k<=j; k++)  
        {  
            if (B1[i][j] == B1[i-1][j-k] + V[i][k])//分k台机器给i公司时，获得最大价值  
            {  
                X[i] = k;  
                j -= k; //更新j的值   
                break;  
            }  
        }  
    }  
      
    int s = 0;  
    for (int i=1; i<=n; i++)  
    {  
        cout << i << " " << X[i] << endl;  
        s += V[i][X[i]];  
    }     
    return s;  
}   
  
void DFS(int n, int i, int j) //回溯算法  
{  
    if (i==0 || j==0) //没有公司或没有机器了  
    {  
        int s = 0;  
        for (int k=1; k<=n; k++)  
        {  
            s += V[k][X[k]];  
        }  
        if (bestValue < s) //记录最优解   
        {  
            bestValue = s;  
            for (int k=1; k<=n; k++)  
            {  
                BX[k] = X[k];  
            }  
        }  
        return;  
    }   
    for (int k=0; k<=j; k++)  
    {  
        X[i] == k;  
        DFS(n, i-1, j-k);  
    }  
}   
  
int MDFS(int i, int j)//备忘录算法   
{  
    if (B2[i][j] != 0)  
        return B2[i][j];  
    if (i==0 || j==0) //没有公司或没有机器了  
        return 0;  
    int bestP = 0;  
    for (int k=0; k<=j; k++)  
    {  
        if (bestP < MDFS(i-1, j-k) + V[i][k])  
            bestP = MDFS(i-1, j-k) + V[i][k];  
    }  
    return B2[i][j] = bestP;      
}  
