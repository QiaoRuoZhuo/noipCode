/* 
    Name: 666_放苹果 
    Copyright:  
    Author:  
    Date: 12-07-17 21:29 
    Description: 666_放苹果 
查看 提交 统计 提问 
总时间限制: 1000ms 内存限制: 65536kB 
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
*/  
#include<iostream>  
#include<cstdio>  
  
using namespace std;  
  
const int MAX = 10;   
int A[MAX+1];  
int M, N, s;  
  
void DFS(int m, int n); //m表示共m个苹果，n表示第n个盘子   
  
int main()   
{  
    int t;  
    cin >> t;  
    for (int k=0; k<t; k++)  
    {  
        cin >> M >> N;  
        s = 0; 
        int minNum = M/N + (M%N!=0); 
        for (int i=M; i>=minNum; i--)//第一个盘中放i个苹果 
        {
			A[1] = i;  
			DFS(M-i, 2);  
		}
        cout << s << endl;  
    }  
      
    return 0;  
}  
void DFS(int m, int n) //m表示共m个苹果，n表示第n个盘子   
{  
    if (m == 0 || n == N)  //没有苹果或者没有盘子了 
    {  
		//A[n] = m;
//        cout << s << " : ";  
//        for (int i=1; i<=n; i++) 
//            cout << A[i] << " "; 
//        for (int i=n+1; i<=N; i++) //后面的盘中为空 
//            cout << 0 << " "; 
//        cout << endl;  
        s++;  
    }  
    else  
    {  
		int maxNum = min(m, A[n-1]);//确保后面的盘子中苹果不比前面的多
		int minNum = m/(N-n+1) + (m%(N-n+1)!=0);
        for (int i=maxNum; i>=minNum; i--)   
        {  
            A[n] = i;  
            DFS(m-i, n+1);  
       }  
    }     
}  
