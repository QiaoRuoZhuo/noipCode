/*
	Name: 拆分自然数
	Copyright: 
	Author:  巧若拙 
	Date: 15/12/18 13:25
	Description: 拆分自然数
Problem Description
任何一个大于1的自然数n，总可以拆分成若干个小于n的自然数之和。
Input
输入有多组数据，对于每组数据就一个数n。
Output
对于每组输入输出n的拆分方法。
Sample Input
4
Sample Output
1+1+1+1
1+1+2
1+3
2+2
	 
算法1：回溯算法框架1：先处理递归出口（即终点），再枚举各种可能值，递归搜索下一层。 
算法2：回溯算法框架2：先枚举各种可能值，再判断是否到达终点，若到达终点则输出结果，否则递归搜索下一层。 
算法2的搜索深度比算法1要少一层，但是不如算法1结构清晰。
算法3：非递归算法：自定义栈模拟算法2的递归过程。
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 10; //整数n范围 
int a[N+1] = {1}; //确保a[1]不小于1 
int n;

void Print(int t);
void dfs1(int s, int t); //框架1 
void dfs2(int s, int t); //框架2 
void dfs3(); //非递归算法 

int main()
{
	while (cin >> n)
	{
		dfs1(n, 1);
	//	dfs2(n, 1);
	//	dfs3();
	}
	
	return 0;
}

void Print(int t)
{
	for (int i=1; i<t; i++)
	{
		cout << a[i] << "+";
	}
	cout << a[t] << endl; 
}

void dfs1(int s, int t) //框架1 
{
	if (s == 0) //到达终点，输出结果 
	{
		Print(t-1); 
	}
	else
	{
		for (int i=a[t-1]; i<=s; i++) //枚举各种可能值，生成一个非递减序列 
		{
			if (i < n) //满足条件:拆分成若干个小于n的自然数 
			{
				a[t] = i;
				dfs1(s-i, t+1); //搜索下一层 
			}
		}
	}
}

void dfs2(int s, int t)//框架2 
{
	for (int i=a[t-1]; i<=s; i++) //枚举各种可能值，生成一个非递减序列 
	{
		if (i < n) //满足条件:拆分成若干个小于n的自然数 
		{
			a[t] = i;
			if (s == i) //到达终点，输出结果 
			{
				Print(t); 
			}
			else
				dfs2(s-i, t+1); //搜索下一层 
		}
	}
}

void dfs3() //非递归算法 
{
	int s = n;
	int t = 1;
	while (t >= 1)
	{
		while (++a[t] <= s) //枚举各种可能值，生成一个非递减序列 
		{
			if (a[t] >= a[t-1] && a[t] < n)   //满足条件 
			{
				if (s == a[t])  //到达终点，输出结果 
				{
					Print(t); 
					break;
				}
				else
				{
					s -= a[t];  //修改标记  
					t++;  //搜索下一层 
				}
			}
		}
		a[t] = 0; //回溯 
		s += a[--t]; //恢复标记 
	}
}
