/*
	Name: 素数环问题
	Copyright: 
	Author: 巧若拙 
	Date: 14/12/18 22:17
	Description: 
素数环问题：把整数1~n填写到一个环中，要求每个整数只能填写一次，并且相邻两个数的和为素数。
易知n为偶数。
因为所有的数字地位相同，为避免重复，可确定第一个数字为1，从第二个数字开始递归处理。 
利用回溯思想枚举每个位置所有的可能值，根据条件找出所有可能的排列。
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
int lib[N+N] = {1,1,0};//筛法求素数 
int a[N+1];
int b[N+1];//当前数字是否被用过
int s = 0;

void Prime(int n);//筛法求素数
bool IsOk(int n, int key); //判断key的值是否已经出现过 
void Print();
void dfs(int t); //框架1 
void dfs1(int t); //框架2 
void dfs2(int t); //框架2 
void dfs3(); //非递归算法 

int main()
{
	int i;
	
	Prime(N+N-1);

	a[1]=1;
	b[1]=1;
	
	dfs(2);
	dfs1(2);
	//dfs2(2);
//	dfs3();
	
	return 0;
}

void Prime(int n) //筛法求素数
{
	for (int i=2; i<=n; i++)
	{
		if (lib[i])
		   continue;
		for (int j=i+i; j<=n; j+=i)
			lib[j] = 1;
	}
	for (int i=2; i<=n; i++)
	{
		if (lib[i] == 0)
		   cout << i << " ";
	}
	cout << endl; 
}

bool IsOk(int n, int key) //判断key的值是否已经出现过 
{
	for (int i=1; i<n; i++)
	{
		if (a[i] == key)
			return false;
	}
	return true;
} 

void dfs(int t) //框架1，不记录标记，直接判断 
{
	if (t == N+1) //到达终点，输出结果 
	{
		if (lib[a[1] + a[t-1]] == 0)
		   Print(); 
	}
	else
	{
		for (int i=2; i<=N; i++) //枚举各种可能值 
		{
			if (IsOk(t, i) && lib[i + a[t-1]] == 0) //满足条件 
			{
				a[t] = i;
				dfs(t+1); //搜索下一层 
			}
		}
	}
}

void dfs1(int t) //框架1，记录标记，以空间换时间 
{
	if (t == N+1) //到达终点，输出结果 
	{
		if (lib[a[1] + a[t-1]] == 0)
		   Print(); 
	}
	else
	{
		for (int i=2; i<=N; i++) //枚举各种可能值 
		{
			if (b[i] == 0 && lib[i + a[t-1]] == 0) //满足条件 
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
	for (int i=2; i<=N; i++) //枚举各种可能值 
	{
		if (b[i] == 0 && lib[i + a[t-1]] == 0) //满足条件 
		{
			a[t] = i;
			b[i] = 1;  //修改标记 
			if (t == N) //到达终点，输出结果 
			{
				if (lib[a[1] + a[t]] == 0)
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
	int t = 2;
	while (t >= 2)
	{
		while (++a[t] <= N) //枚举各种可能值，a[t]初始化为0 
		{
			if (b[a[t]] == 0 && lib[a[t] + a[t-1]] == 0)  //满足条件 
			{
				b[a[t]] = 1;  //修改标记  
				if (t == N)  //到达终点，输出结果 
				{
					b[a[t]] = 0;  //恢复标记 
					if (lib[a[1] + a[t]] == 0)
					{
						Print(); 
						break;
					}
				}
				else
					t++;  //搜索下一层 
			}
		}
		a[t--] = 0; //回溯 
		b[a[t]] = 0; //恢复标记 
	}
}

void Print()
{
	cout << ++s << ": ";
	for (int i=1; i<=N; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl; 
}

