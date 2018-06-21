/* 
    Name: 花店橱窗布置 
    Copyright:  
    Author: 巧若拙 
    Date: 09-06-18 22:53 
    Description: 花店橱窗布置(flower.cpp) 
【问题描述】 
假设以最美观的方式布置花店的橱窗，有F束花，每束花的品种都不一样，同时，至少有 
同样数量的花瓶，被按顺序摆成一行，花瓶的位置是固定的，并从左到右，从1到V顺序编 
号，V 是花瓶的数目，编号为1的花瓶在最左边，编号为V的花瓶在最右边，花束可以移动， 
并且每束花用1到F 的整数惟一标识，标识花束的整数决定了花束在花瓶中列的顺序即如果 
i < j，则花束i 必须放在花束j左边的花瓶中。 
例如，假设杜鹃花的标识数为1，秋海棠的标识数为2，康乃馨的标识数为3，所有的花束在 
放入花瓶时必须保持其标识数的顺序，即：杜鹃花必须放在秋海棠左边的花瓶中，秋海棠 
必须放在康乃馨左边的花瓶中。如果花瓶的数目大于花束的数目，则多余的花瓶必须空， 
即每个花瓶中只能放一束花。 
每一个花瓶的形状和颜色也不相同，因此，当各个花瓶中放入不同的花束时会产生不同的美学 
效果，并以美学值(一个整数)来表示，空置花瓶的美学值为0。在上述例子中，花瓶与花束的不 
同搭配所具有的美学值，可以用如下表格表示。 
花瓶 
1 2 3 4 5 
0B Bunches 1 (杜鹃花) 7 23 -5 -24 16 
2 (秋海棠) 5 21 -4 10 23 
3 (carnations) -21 5 -4 -20 20 
根据表格，杜鹃花放在花瓶2中，会显得非常好看，但若放在花瓶4中则显得很难看。 
为取得最佳美学效果，必须在保持花束顺序的前提下，使花的摆放取得最大的美学值，如果具 
有最大美学值的摆放方式不止一种，则输出任何一种方案即可。 
题中数据满足下面条件：1≤F≤100，F≤V≤100，－50≤Aij≤50，其中Aij是花束i摆放在花瓶j 
中的美学值。输入整数F，V 和矩阵(Aij)，输出最大美学值和每束花摆放在各个花瓶中的花瓶编号。 
【输入文件】 
第一行包含两个数：F，V。 随后的F行中，每行包含V个整数，Aij 即为输入文件中第（i+1） 
行中的第j个数 
【输出文件】 
包含两行:第一行是程序所产生摆放方式的美学值。第二行必须用F个数表示摆放方式，即该行的 
第K个数表示花束K所在的花瓶的编号。 
输入样例 输出样例 
3 5  
7 23 -5 -24 16 
5 21 -4 10 23 
-21 5 -4 -20 20 
 
53  
2 4 5 
 
算法分析：  
算法1：典型的多重背包问题，用B[i][j]来表示给定i束花和j个瓶的最优解。  
状态转移方程： 
B[i][j] = max(B[i-1][k-1] + V[i][k])  ( i<=k<=j) 
B[i][j]代表给定i束花和j个瓶的最优解，V[i][k]表示花束i摆放在花瓶j中的美学值 
还可以对算法1进行各种降维优化。 
还有回溯和备忘录算法也是基于算法1的思想。  
 
算法2：与算法1相似，唯一的区别就是，B[i][j]来表示给定i束花和j个瓶的情况下，花束i放在花瓶j中的最优解。  
因为B[i][j]的意义发生变化，所以状态转移方程也要发生相应变化。 
状态转移方程： 
B[i][j] = max(B[i-1][k] + V[i][j])  ( i-1<=k<=j-1) 
B[i][j]代表花束i放在花瓶j中的最优解，V[i][j]表示花束i摆放在花瓶j中的美学值 
*/   
#include<iostream>  
#include<cstring>  
  
using namespace std;  
  
const int INF = -5000; //自定义的最小值   
const int MAXC = 100; //花束数量   
const int MAXM = 100; //花瓶数量   
int V[MAXC+1][MAXM+1];//美学值矩阵   
int B1[MAXC+1][MAXM+1]; //记录给定i束花和j个瓶的最优解。  
int B2[MAXC+1][MAXM+1]; //记录给定i束花和j个瓶的最优解。  
int B3[MAXC+1][MAXM+1]; //记录给定i束花和j个瓶的最优解。  
int pre[MAXM+1]; //pre[j]相当于B1[i-1][j]   
int cur[MAXM+1]; //cur[j]相当于B1[i][j]  
int F1[MAXM+1]; //记录最优解   
int X[MAXC+1]; //记录各花束所在花瓶编号  
int BX[MAXC+1]; //记录各花束所在花瓶编号  
int bestValue = INF; //用回溯算法解时用来记录最大美学值  
int C[MAXC+1][MAXM+1]; //C[i][j]记录当花束i放在花瓶j时，花束i-1的位置   
  
int Best_1(int n, int m);//动态规划:二维数组存储结果   
int Best_2(int n, int m);//优化的动态规划算法，用2个一维数组代替二维数组   
int Best_3(int n, int m);//进一步优化的动态规划算法，用1个一维数组代替二维数组   
void Show(int i, int j); //递归输出各花束所在花瓶编号   
int Show_2(int n, int m); //利用数组B1[][]，输出各花束所在花瓶编号，X[i]初始化为0   
void DFS(int n, int i, int j); //回溯算法  
int MDFS(int i, int j); //备忘录算法   
void Show_3(int n, int m);//根据算法2得到的动态规划解法   
  
int main()   
{  
    int n, m;  
    cin >> n >> m;//花束和花瓶的数量   
      
    for (int i=1; i<=n; i++)//不计下标为0的元素   
    {  
        for (int j=1; j<=m; j++)//不计下标为0的元素   
        {  
            cin >> V[i][j];  
        }  
    }  
      
    cout << Best_1(n, m) << endl;  
    Show(n, m);  
    cout << Show_2(n, m) << endl;  
    cout << Best_2(n, m) << endl;  
    cout << Best_3(n, m) << endl;  
      
    DFS(n, n, m);  
    cout << bestValue << endl;  
    for (int i=1; i<=n; i++)  
    {  
        cout  << BX[i] << " ";  
    }     
    cout << endl;  
      
    for (int i=1; i<=MAXC; i++)//不计下标为0的元素   
    {  
        for (int j=1; j<=MAXM; j++)//不计下标为0的元素   
        {  
            B2[i][j] = INF;  
        }  
    }  
    cout << MDFS(n, m) << endl;  
      
    Show_3(n, m);  
  
   // system("pause");  
    return 0;  
}  
  
int Best_1(int n, int m)//动态规划:二维数组存储结果  
{  
    for (int i=1; i<=n; i++) //给定前i个花束   
    {  
        for (int j=i; j<=m-n+i; j++) //给定j个花瓶，j不取到m的原因是给后面的花束留位置   
        {//朴素的穷举思想，计算花束i放在花瓶k时，总的美学值是多少，存储最优解到B1[i][j]   
            int bestP = INF;//因为美学值有可能为负值，故初始化为最小值   
            for (int k=i; k<=j; k++)  
            {  
                if (bestP < B1[i-1][k-1] + V[i][k])//花束i放在花瓶k，则前i-1个花束可放在前k-1个花瓶中   
                    bestP = B1[i-1][k-1] + V[i][k];  
            }  
            B1[i][j] = bestP;  
        }  
    }  
      
    return B1[n][m];  
}  
  
void Show(int i, int j)//递归输出各花束所在花瓶编号   
{  
    if (i == 0 || j == 0)  
        return;  
    for (int k=j; k>=i; k--)//k递增或递减均可     
    {    
        if (B1[i][j] == B1[i-1][k-1] + V[i][k])//花束i放在花瓶k，则前i-1个花束可放在前k-1个花瓶中   
        {  
            Show(i-1, k-1);  
            cout << k << " ";  
            break;  
        }  
    }  
}  
  
int Show_2(int n, int m) //利用数组B1[][]，输出各花束所在花瓶编号，X[i]初始化为0   
{  
    for (int i=n,j=m; i>0; i--)  
    {  
        for (int k=i; k<=j; k++)  
        {  
            if (B1[i][j] == B1[i-1][k-1] + V[i][k])//花束i放在花瓶k，则前i-1个花束可放在前k-1个花瓶中   
            {  
                X[i] = k;  
                j = k - 1; //更新j的值   
                break;  
            }  
        }  
    }  
      
    int s = 0;  
    for (int i=1; i<=n; i++)  
    {  
        cout << X[i] << " ";  
        s += V[i][X[i]];  
    }  
    cout << endl;   
    return s;  
}   
  
int Best_2(int n, int m)//优化的动态规划算法，用2个一维数组代替二维数组   
{  
    //pre[j]相当于B1[i-1][j]，cur[j]相当于B1[i][j]   
    for (int i=1; i<=n; i++) //给定前i个花束   
    {  
        for (int j=i; j<=m-n+i; j++) //给定j个花瓶，j递增或递减均可    
        {  
            int bestP = INF;  
            for (int k=i; k<=j; k++)//花束i放在花瓶k，则前i-1个花束可放在前k-1个花瓶中   
            {  
                if (bestP < pre[k-1] + V[i][k])  
                    bestP = pre[k-1] + V[i][k];  
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
    for (int i=1; i<=n; i++) //实际上就是一个多重背包问题   
    {  
        for (int j=m-n+i; j>=i; j--) //类似于0-1背包问题，j只能递减  
        {  
            //朴素的穷举思想，计算花束i放在花瓶k时，总的美学值是多少，存储最大价值到F1[j]   
            int bestP = INF;  
            for (int k=i; k<=j; k++)  
            {  
                if (bestP < F1[k-1] + V[i][k])  
                    bestP = F1[k-1] + V[i][k];  
            }  
            F1[j] = bestP;  
        }  
    }  
      
    return F1[m];  
}  
  
void DFS(int n, int i, int j) //回溯算法  
{  
    if (i==0 || j==0) //没有花束或没有花瓶了  
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
    for (int k=i; k<=j; k++)  
    {  
        X[i] == k;  
        DFS(n, i-1, k-1);  
    }  
}   
  
int MDFS(int i, int j)//备忘录算法   
{  
    if (B2[i][j] != INF)  
        return B2[i][j];  
    if (i==0 || j==0) //没有公司或没有机器了  
        return 0;  
    int bestP = INF;  
    for (int k=i; k<=j; k++)  
    {  
        if (bestP < MDFS(i-1, k-1) + V[i][k])  
            bestP = MDFS(i-1, k-1) + V[i][k];  
    }  
      
    return B2[i][j] = bestP;   
}  
  
void Show_3(int n, int m)//根据算法2得到的动态规划解法   
{  
    int bestP, pos;//因为美学值有可能为负值，故初始化为最小值   
    for (int i=1; i<=n; i++) //给定前i个花束   
    {  
        for (int j=i; j<=m-n+i; j++) //给定j个花瓶，j不取到m的原因是给后面的花束留位置   
        {  
            bestP = INF;//因为美学值有可能为负值，故初始化为最小值   
            for (int k=i-1; k<j; k++) //在花束i放在花瓶j的情况下，枚举花束i-1的位置   
            {  
                if (bestP < B3[i-1][k] + V[i][j])  
                {  
                    bestP = B3[i-1][k] + V[i][j];  
                    C[i][j] = k; //花束i-1放在花瓶k中   
                }  
            }  
            B3[i][j] = bestP;  
        }  
    }  
      
    bestP = INF;//因为美学值有可能为负值，故初始化为最小值   
    for (int j=n; j<=m; j++) //寻找最后一束花的位置  
    {  
        if (bestP < B3[n][j])  
        {  
            bestP = B3[n][j];  
            pos = j; //最后一束花放在花瓶pos   
        }  
    }   
    cout << bestP << endl;  
      
    for (int i=n; i>0; i--)  
    {  
        X[i] = pos;     //记录花束i的位置   
        pos = C[i][pos];//获取前一束花的位置   
    }  
    for (int i=1; i<=n; i++)//输出各个花束的位置   
    {  
        cout  << X[i] << " ";  
    }  
    cout << endl;  
}  
