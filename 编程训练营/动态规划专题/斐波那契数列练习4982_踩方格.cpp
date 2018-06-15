/*
	Name: 4982_踩方格
	Copyright: 
	Author: 
	Date: 15-06-18 14:47
	Description: 4982_踩方格
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有一个方格矩阵，矩阵边界在无穷远处。我们做如下假设：
a.    每走一步时，只能从当前方格移动一格，走到某个相邻的方格上；
b.    走过的格子立即塌陷无法再走第二次；
c.    只能向北、东、西三个方向走；
请问：如果允许在方格矩阵上走n步，共有多少种不同的方案。2种走法只要有一步不一样，即被认为是不同的方案。

输入
允许在方格上行走的步数n(n <= 20)
输出
计算出的方案数量
样例输入
2
样例输出
7

算法分析：
状态转移方程推导如下——
设E[i],W[i],N[i]分别为第 i 步向东，西，北的方案数，F[i]为总方案数。
若上一步是向东走的，则下一步只能向东或北走，反之亦然；只有上一步是向北走的，下一步才可以选择3个方向。
则有： E[i]=E[i-1]+N[i-1], W[i]=W[i-1]+N[i-1], N[i]=E[i-1]+W[i-1]+N[i-1]
F[i]=E[i]+W[i]+N[i]
    =2*E[i-1]+2*W[i-1]+3*N[i-1]
    =2*F[i-1]+N[i-1]
    =2*F[i-1]+F[i-2] 
边界条件为：F[0]=1,  F[1]=3
另一种理解思路：若第n-1步是从东方或西方来的，则第n步只有2种选择，即F[i]=2*F[i-1]；
若第n-1步是从北方来的，则第n步的方案数与第n-2步相同，即F[i]=F[i-2]；
综合起来就是：F[i] = 2*F[i-1]+F[i-2]
*/
#include<iostream>  
#include<cmath>  
  
using namespace std;  
  
const int MAXN = 21;  
long long F1[MAXN];//存储总方案数量 
long long F2[MAXN] = {1, 3};//存储总方案数量 
  
long long Fun_1(int n); //备忘录：自顶而下  
long long Fun_2(int n);//动态规划：自底而上  
  
int main()   
{  
    int n;  
	
	Fun_2(MAXN); //动态规划，先记录所有子问题的解 

	while (cin >> n)  
    {  
      //  cout << Fun_1(n) << endl;
        cout << F2[n] << endl;
    }  
      
    return 0;  
}  

long long Fun_1(int n) //备忘录：自顶而下  
{  
    if (F1[n] > 0)  //如果这个问题曾经计算过，直接返回   
    {  
        return F1[n];  
    }
    if (n == 0)  //递归出口 
    {  
        F1[n] = 1;  
    }   
	else if (n == 1)  //递归出口 
    {  
        F1[n] = 3;  
    }   
    else
    {
		F1[n] = 2 * Fun_1(n-1) + Fun_1(n-2);  
	}
    
    return F1[n];
}  
  
long long Fun_2(int n)//动态规划：自底而上  
{  
    for (int i=2; i<=n; i++)  
    {  
        F2[i] = 2 * F2[i-1] + F2[i-2];  
    }  
      
    return F2[n];  
}  
