/*
	Name: 1788_Pell数列
	Copyright: 
	Author: 
	Date: 14-06-18 11:38
	Description: 1788_Pell数列
查看 提交 统计 提问
总时间限制: 3000ms 内存限制: 65536kB
描述
Pell数列a1, a2, a3, ...的定义是这样的，a1 = 1, a2 = 2, ... , an = 2 * an - 1 + an - 2 (n > 2)。
给出一个正整数k，要求Pell数列的第k项模上32767是多少。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1 ≤ k < 1000000)。
输出
n行，每行输出对应一个输入。输出应是一个非负整数。
样例输入
2
1
8
样例输出
1
408
*/
#include<iostream>  
#include<cmath>  
  
using namespace std;  

const int MOD = 32767; 
const int MAXN = 1000000;  
long long F2[MAXN] = {0, 1, 2};//Pell数列
  
long long Fun_2(int n);//动态规划：自底而上  
long long Fun_3(int n);//动态规划：降维优化
  
int main()   
{  
    int n, a;  
	
	Fun_2(MAXN); //动态规划，先记录所有子问题的解 
	cin >> n;
	for (int i=0; i<n; i++)  
    {  
		cin >> a;
        cout << F2[a] << endl;
    	//cout << Fun_3(a) << endl;
    }  
      
    return 0;  
}  
  
long long Fun_2(int n)//动态规划：自底而上  
{  
    for (int i=3; i<=n; i++)  
    {  
        F2[i] = (2*F2[i-1] + F2[i-2]) % MOD;  
    }  
      
    return F2[n];  
}  

long long Fun_3(int n)//动态规划：降维优化 
{  
	long long cur, pre1, pre2;
	
	if (n == 1 || n == 2)
		cur = n;  
	pre1 = 1, pre2 = 2; //初始化 	
    for (int i=3; i<=n; i++) //自底向上，迭代更新变量值 
    {  
		cur = (2 * pre2 + pre1) % MOD;  
        pre1 = pre2;
        pre2 = cur;
    }  
      
    return cur;  
}  
