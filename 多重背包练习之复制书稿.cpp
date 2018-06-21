/* 
    Name: 复制书稿 
    Copyright:  
    Author:  
    Date: 09-06-18 22:53 
    Description:复制书稿 
Problem Description 
现在要把m本有顺序的书分给k个人复制(抄写)，每一个人的抄写速度都一样，一本书不允许给两个(或以上)的人抄写，分给每一个人的书，必须是连续的，比如不能把第一、第三和第四本书给同一个人抄写。 
现在请你设计一种方案，使得复制时间最短。复制时间为抄写页数最多的人用去的时间。 
Input 
输入有多组数据，每组数据第1行两个整数m,k(k<=m<=500)； 
第2行m个整数，第i个整数表示第i本书的页数。 
Output 
对于每组数据输出k行，每行两个整数，第i行表示第i个人抄写的书的起始编号和终止编号。k行的起始编号应该从小到大排列，如果有多解，则尽可能让前面的人少抄写。 
Sample Input 
9 3 
1 2 3 4 5 6 7 8 9 
Sample Output 
1 5 
6 7 
8 9 
 
Hint 
如果m=k=0，则输出空行 
 
算法分析：  
算法1：典型的多重背包问题，用B[i][j]来表示给定i个人和j本书的最优解。  
状态转移方程： 
B[i][j] = min(max(B[i-1][k] + S[j]-S[k]))  ( i-1<=k<j) 
S[j]代表前j本书的总页数。 
还可以对算法1进行各种降维优化。 
还有备忘录算法也是基于算法1的思想。  
输出具体方案时可以使用递归和非递归的方法，可以顺序或者逆序分配页码， 
无论顺序还是逆序分配，都使用贪心策略，尽可能让先分配的人多抄。  
*/   
#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
const int INF = 1000000; //自定义的最大值   
const int MAXC = 500; //人的数量   
const int MAXM = 500; //书本数量   
int V[MAXM+1];//V[i]表示第i本书的页数   
int S[MAXM+1];//S[i]表示前i本书的总页数   
int B1[MAXC+1][MAXM+1]; //记录给定i个人和j本书的最优解  
int B2[MAXC+1][MAXM+1]; //记录给定给定i个人和j本书的最优解  
int pre[MAXM+1]; //pre[j]相当于B1[i-1][j]   
int cur[MAXM+1]; //cur[j]相当于B1[i][j]  
int F1[MAXM+1]; //记录最优解   
  
int Best_1(int n, int m);//动态规划:二维数组存储结果   
int Best_2(int n, int m);//优化的动态规划算法，用2个一维数组代替二维数组   
int Best_3(int n, int m);//进一步优化的动态规划算法，用1个一维数组代替二维数组   
void Show(int minTime, int i, int j); //递归输出抄写书本的方案   
void Show_2(int minTime, int n, int m);//非递归逆序输出抄写书本的方案   
void Show_3(int minTime, int n, int m);//非递归顺序输出抄写书本的方案   
int DFS(int i, int j); //回溯算法  
int MDFS(int i, int j); //备忘录算法   
void Show_3(int n, int m);//根据算法2得到的动态规划解法   
  
int main()   
{  
    int n, m;  
    cin >> m >> n;//m本书n个人   
      
    for (int i=0; i<=MAXC; i++)//不计下标为0的元素   
    {  
        for (int j=0; j<=MAXM; j++)//不计下标为0的元素   
        {  
            B2[i][j] = B1[i][j] = INF;  
        }  
    }  
      
    for (int j=1; j<=m; j++)//不计下标为0的元素   
    {  
        cin >> V[j];  
        S[j] = S[j-1] + V[j];  
    }  
      
    cout << Best_1(n, m) << endl;  
    Show(B1[n][m], n, m);  
    Show_2(B1[n][m], n, m);  
    Show_3(B1[n][m], n, m);  
      
    cout << Best_2(n, m) << endl;  
    cout << Best_3(n, m) << endl;  
    cout << DFS(n, m) << endl;  
    cout << MDFS(n, m) << endl;  
  
   // system("pause");  
    return 0;  
}  
  
int Best_1(int n, int m)//动态规划:二维数组存储结果  
{  
    for (int j=1; j<=m; j++)  
    {  
        B1[1][j] = S[j]; //1个人抄写前j本书所需时间   
    }  
    for (int i=2; i<=n; i++) //给定i个人   
    {  
        for (int j=i; j<=m-n+i; j++) //给定前j本书，j不取到m的原因是给后面的每人至少留1本书   
        {//朴素的穷举思想，计算第i人抄第k+1到第j本书时，团队需要的最少时间是多少，存储最优解到B1[i][j]   
            int bestP = INF;  
            for (int k=i-1; k<j; k++)  
            {  
                if (bestP > max(B1[i-1][k], S[j]-S[k]))//从前i-1个人的最大用时和第i个人的用时中取出较大值   
                    bestP = max(B1[i-1][k], S[j]-S[k]);  
            }  
            B1[i][j] = bestP;  
        }  
    }  
      
    return B1[n][m];  
}  
  
void Show(int minTime, int i, int j)//递归输出抄写书本的方案   
{  
    if (i == 0 || j == 0)  
        return;  
    if (i == 1) //第1个人抄写1到j本书  
    {  
        cout << 1 << " " << j << endl;  
        return;  
    }   
    int t = j, x = V[j]; //第i个人抄书的页数为x    
    while (t>1 && x+V[t-1] <= minTime)//从第j本书开始逆序分配给第i个人抄写，使用贪心策略，尽可能让先分配的人多抄   
    {    
        x += V[t-1];  
        t--;  
    }  
    Show(minTime, i-1, t-1);//还剩i-1个人和t-1本书  
    cout << t << " " << j << endl;  
}  
  
void Show_2(int minTime, int n, int m)//非递归逆序输出抄写书本的方案   
{  
    int i, j, t, x;  
      
    for (i=n,j=m; i>0 && j>0; i--,j=t-1)  
    {  
        t = j, x = V[j]; //第i个人抄书的页数为x    
        while (t>1 && x+V[t-1] <= minTime)//从第j本书开始逆序分配给第i个人抄写，使用贪心策略，尽可能让先分配的人多抄   
        {    
            x += V[t-1];  
            t--;  
        }  
        cout << t << " " << j << endl;  
    }  
}  
  
void Show_3(int minTime, int n, int m)//非递归顺序输出抄写书本的方案   
{  
    int i, j, t, x;  
      
    for (i=1,j=1; i<=n && j<=m; i++,j=t+1)  
    {  
        t = j, x = V[j]; //第i个人抄书的页数为x    
        while (t<m && x+V[t+1] <= minTime)//从第j本书开始顺序分配给第i个人抄写，使用贪心策略，尽可能让先分配的人多抄   
        {    
            x += V[t+1];  
            t++;  
        }  
        cout << j << " " << t << endl;  
    }  
}  
  
int Best_2(int n, int m)//优化的动态规划算法，用2个一维数组代替二维数组   
{//pre[j]相当于B1[i-1][j]，cur[j]相当于B1[i][j]   
    for (int j=1; j<=m; j++)  
    {  
        pre[j] = S[j]; //1个人抄写前j本书所需时间   
    }  
    for (int i=2; i<=n; i++) //给定i个人   
    {  
        for (int j=i; j<=m-n+i; j++) //给定前j本书，j不取到m的原因是给后面的每人至少留1本书   
        {//朴素的穷举思想，计算第i人抄第k到j本书时，团队需要的最少时间是多少，存储最优解到B1[i][j]   
            int bestP = INF;  
            for (int k=i-1; k<j; k++)  
            {  
                if (bestP > max(pre[k], S[j]-S[k]))//从前i-1个人的最大用时和第i个人的用时中取出较大值   
                    bestP = max(pre[k], S[j]-S[k]);  
            }  
            cur[j] = bestP;  
        }  
        for (int j=i; j<=m-n+i; j++)  
        {  
            pre[j] = cur[j];   
        }  
    }  
    return pre[m];  
}  
  
int Best_3(int n, int m)//进一步优化的动态规划算法，用1个一维数组代替二维数组   
{  
    for (int j=1; j<=m; j++)  
    {  
        F1[j] = S[j]; //1个人抄写前j本书所需时间   
    }  
    for (int i=2; i<=n; i++) //实际上就是一个多重背包问题   
    {  
        for (int j=m-n+i; j>=i; j--) //类似于0-1背包问题，j只能递减  
        {  
            int bestP = INF;  
            for (int k=i-1; k<j; k++)  
            {  
                if (bestP > max(F1[k], S[j]-S[k]))//从前i-1个人的最大用时和第i个人的用时中取出较大值   
                    bestP = max(F1[k], S[j]-S[k]);  
            }  
            F1[j] = bestP;  
        }  
    }  
      
    return F1[m];  
}  
  
int DFS(int i, int j) //回溯算法  
{  
    if (i == 1) //1个人抄写前j本书所需时间   
    {  
        return S[j];  
    }  
    int bestP = INF;  
    for (int k=i-1; k<j; k++)  
    {  
        if (bestP > max(DFS(i-1, k), S[j]-S[k]))//从前i-1个人的最大用时和第i个人的用时中取出较大值   
            bestP = max(DFS(i-1, k), S[j]-S[k]);  
    }  
      
    return bestP;   
}   
  
int MDFS(int i, int j)//备忘录算法   
{  
    if (B2[i][j] != INF)  
        return B2[i][j];  
    if (i == 1) //1个人抄写前j本书所需时间   
    {  
        return B2[i][j] = S[j];  
    }  
          
    int bestP = INF;  
    for (int k=i-1; k<j; k++)  
    {  
        if (bestP > max(MDFS(i-1, k), S[j]-S[k]))//从前i-1个人的最大用时和第i个人的用时中取出较大值   
            bestP = max(MDFS(i-1, k), S[j]-S[k]);  
    }  
      
    return B2[i][j] = bestP;   
} 
