/*  
    Name: 666_放苹果  
    Author: 巧若拙  
描述  
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。  
输入  
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。  
输出  
对输入的每组数据M和N，用一行输出相应的K。  
样例输入  
1  
7 3  
样例输出  
8  
 
算法分析： 
有2种思路，一种是确保后面的盘子中苹果不比前面的少，另一种是确保后面的盘子中苹果不比前面的多。 
第2种思路递归深度较少，但代码复杂些，特别要注意第n个盘子能放苹果的数量范围。  
基本上递归问题都可以转化为记忆化搜索，然后转换为动态规划问题。
回溯算法相当于穷举，不但可以获得组合的数量，还可以存储具体的解空间。 
*/    
#include<iostream>    
#include<cstdio>    
    
using namespace std;    
    
const int MAX = 100;     
int A1[MAX+1], A2[MAX+1];    
int A[MAX+1][MAX+1], F[MAX+1][MAX+1];  
int M, N, s1, s2;    
    
void DFS_1(int m, int n); //m表示共m个苹果，n表示第n个盘子     
void DFS_2(int m, int n); //m表示共m个苹果，n表示第n个盘子   
int DG(int m, int n); //m表示共m个苹果，n表示第n个盘子 
int JYHSS(int m, int n); //记忆化搜索   
int DTGH(int m, int n); //动态规划 
    
int main()     
{    
    int t;    
    cin >> t;    
    for (int k=0; k<t; k++)    
    {    
        cin >> M >> N;    
          
        s1 = 0;   
        DFS_1(M, 1);    
        cout << s1 << endl;    
          
        s2 = 0;   
        int minNum = M/N + (M%N!=0);   
        for (A2[1]=M; A2[1]>=minNum; A2[1]--)//第一个盘中放A2[1]个苹果   
        {    
            DFS_2(M-A2[1], 2);    
        }  
        cout << s2 << endl;    
        
        cout << DG(M, N) << endl;    
        cout << JYHSS(M, N) << endl;    
        cout << DTGH(M, N) << endl;    
    }    
        
    return 0;    
}    
  
void DFS_1(int m, int n) //m表示共m个苹果，n表示第n个盘子     
{    
    if (n == N)    
    {    
        A1[n] = m;    
        cout << s1 << " : ";    
        for (int i=1; i<=N; i++)    
            cout << A1[i] << " ";    
        cout << endl;    
        s1++;    
    }    
    else    
    {    
        for (A1[n]=A1[n-1]; A1[n]+A1[n]<=m; A1[n]++)    
        {   //确保剩下的苹果不比当前盘子中的少     
            DFS_1(m-A1[n], n+1); 
       }    
    }       
}   
  
void DFS_2(int m, int n) //m表示共m个苹果，n表示第n个盘子     
{    
    if (m == 0 || n == N)  //没有苹果或者没有盘子了   
    {    
        A2[n] = m;  
        cout << s2 << " : ";    
        for (int i=1; i<=n; i++)   
            cout << A2[i] << " ";   
        for (int i=n+1; i<=N; i++) //后面的盘中为空   
            cout << 0 << " ";   
        cout << endl;    
        s2++;    
    }    
    else    
    {    
        int maxNum = min(m, A2[n-1]);//确保后面的盘子中苹果不比前面的多  
        int minNum = m/(N-n+1) + (m%(N-n+1)!=0);  
        for (A2[n]=maxNum; A2[n]>=minNum; A2[n]--)     
        {        
            DFS_2(m-A2[n], n+1);    
       }    
    }       
}    

int DG(int m, int n) //m表示共m个苹果，n表示第n个盘子     
{    
    if (m == 0 || n == 1)  
	    return 1;
    else if (m < n) //当盘子多于苹果时，相当于把m个苹果放到m个盘子里 
	    return DG(m, m);  
    else //每个盘子至少放1各苹果的组合加上至少有1个空盘的组合 
		return DG(m-n, n) + DG(m, n-1); 
}  

int JYHSS(int m, int n) //记忆化搜索  
{    
	if (A[m][n] != 0)
		return A[m][n];
    if (m == 0 || n == 1)  
	    A[m][n] = 1;
    else if (m < n) //当盘子多于苹果时，相当于把m个苹果放到m个盘子里 
	    A[m][n] = JYHSS(m, m);  
    else //每个盘子至少放1各苹果的组合加上至少有1个空盘的组合 
		A[m][n] = JYHSS(m-n, n) + JYHSS(m, n-1); 
	return A[m][n];
}  

int DTGH(int m, int n) //动态规划 
{    
	for (int i=1; i<=m; i++) 
    {  
        F[i][1] = 1;  
    }  
	for (int j=1; j<=n; j++) 
    {  
        F[0][j] = 1;  
    }  
	//为实现自底向上，必须要保证j在外层循环，
	//然后按照0<=i<j和j<=i<=m的顺序在内层循环，分别计算m<n和m>=n的f(m, n)值
    for (int j=1; j<=n; j++)
    {
	 	//f(m, n)=f(m, m); ( m < n ) 
	 	for (int i=1; i<j; i++) 
	 	{
		 	F[i][j] = F[i][j-1];
		}
		//f(m, n)=f(m - n, n) + f(m, n - 1); ( m >= n )
	 	for (int i=j; i<=m; i++)
	 	{
		 	F[i][j] = F[i-j][j] + F[i][j-1];
		}
	}
	return F[m][n];
}  

