/*
	Name: 排列数问题 
	Copyright: 
	Author:  巧若拙 
	Date: 15/12/18 13:25
	Description: 排列数问题 
设有n个整数的集合{1,2,3，。。。，n}，从中任意取出r个数进行排列（r<=n），试列举所有的排列。
算法分析：从n个数中选取m（m<=n）个数按照一定的顺序进行排成一个列，叫作从n个元素中取m个元素的一个排列。
由排列的定义，显然不同的顺序是一个不同的排列。从n个元素中取m个元素的所有排列的个数，称为排列数。
从n个元素取出n个元素的一个排列，称为一个全排列。全排列的排列数公式为n!，通过乘法原理可以得到。
算法0：回溯算法框架1：先处理递归出口（即终点），再枚举各种可能值，递归搜索下一层。调用函数直接判断是否满足条件，这样无需记录和恢复标记值。	 
算法1：回溯算法框架1：以空间换时间，定义数组b用来设置标记，再搜索下一层前后记录和恢复标记值。 
算法2：回溯算法框架2：先枚举各种可能值，再判断是否到达终点，若到达终点则输出结果，否则递归搜索下一层。 
算法2的搜索深度比算法1要少一层，但是不如算法1结构清晰。
算法3：非递归算法：自定义栈模拟算法2的递归过程，注意最后一个位置要单独恢复b[a[t]] = 0。
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 10; //整数个数
int a[N+1];
int b[N+1];//当前数字是否被用过
int s = 0;
int n, r;

bool IsOk(int t, int key); //判断key的值是否已经出现过 
void Print();
void dfs(int t); //框架1 
void dfs1(int t); //框架2 
void dfs2(int t); //框架2 
void dfs3(); //非递归算法 

int main()
{
	cin >> n >> r;

//	dfs(1);
//	dfs1(1);
//	dfs2(1);
	dfs3();
	
	return 0;
}

void Print()
{
	cout << ++s << ": ";
	for (int i=1; i<=r; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl; 
}

bool IsOk(int t, int key) //判断key的值是否已经出现过 
{
	for (int i=1; i<t; i++)
	{
		if (a[i] == key)
			return false;
	}
	return true;
} 

void dfs(int t) //框架1，不记录标记，直接判断 
{
	if (t == r+1) //到达终点，输出结果 
	{
		Print(); 
	}
	else
	{
		for (int i=1; i<=n; i++) //枚举各种可能值 
		{
			if (IsOk(t, i)) //满足条件 
			{
				a[t] = i;
				dfs(t+1); //搜索下一层 
			}
		}
	}
}

void dfs1(int t) //框架1，记录标记，以空间换时间 
{
	if (t == r+1) //到达终点，输出结果 
	{
		Print(); 
	}
	else
	{
		for (int i=1; i<=n; i++) //枚举各种可能值 
		{
			if (b[i] == 0) //满足条件 
			{
				a[t] = i;
				b[i] = 1; //修改标记 
				dfs1(t+1); //搜索下一层 
				b[i] = 0; //恢复标记 
			}
		}
	}
}

void dfs2(int t) //框架2 ，记录标记，以空间换时间  
{
	for (int i=1; i<=n; i++) //枚举各种可能值 
	{
		if (b[i] == 0) //满足条件 
		{
			a[t] = i;
			b[i] = 1;  //修改标记 
			if (t == r) //到达终点，输出结果 
			{
				Print(); 
			}
			else
				dfs2(t+1); //搜索下一层 
			b[i] = 0;   //恢复标记 
		}
	}
}

void dfs3() //非递归算法 
{
	int t = 1;
	while (t >= 1)
	{
		while (++a[t] <= n) //枚举各种可能值，a[t]初始化为0 
		{
			if (b[a[t]] == 0)  //满足条件 
			{
				b[a[t]] = 1;  //修改标记  
				if (t == r)  //到达终点，输出结果 
				{
					b[a[t]] = 0;  //恢复标记 
					Print(); 
				}
				else
					t++;  //搜索下一层 
			}
		}
		a[t--] = 0; //回溯 
		b[a[t]] = 0; //恢复标记 
	}
}



