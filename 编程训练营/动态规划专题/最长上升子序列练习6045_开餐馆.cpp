/*
	Name: 6045_开餐馆
	Copyright: 
	Author: 
	Date: 24-06-18 13:39
	Description:
描述
北大信息学院的同学小明毕业之后打算创业开餐馆.现在共有n 个地点可供选择。小明打算从中选择合适的位置开设一些餐馆。这 n 个地点排列在同一条直线上。我们用一个整数序列m1, m2, ... mn 来表示他们的相对位置。由于地段关系,开餐馆的利润会有所不同。我们用pi 表示在mi 处开餐馆的利润。为了避免自己的餐馆的内部竞争,餐馆之间的距离必须大于k。请你帮助小明选择一个总利润最大的方案。

输入
标准的输入包含若干组测试数据。输入第一行是整数T (1 <= T <= 1000) ，表明有T组测试数据。紧接着有T组连续的测试。每组测试数据有3行,
第1行:地点总数 n (n < 100), 距离限制 k (k > 0 && k < 1000).
第2行:n 个地点的位置m1 , m2, ... mn ( 1000000 > mi > 0 且为整数,升序排列)
第3行:n 个地点的餐馆利润p1 , p2, ... pn ( 1000 > pi > 0 且为整数)
输出
对于每组测试数据可能的最大利润
样例输入
2
3 11
1 2 15
10 2 30
3 16
1 2 15
10 2 30
样例输出
40
30
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAX = 1000; 
long long A[MAX+1]; //各点位置坐标 
long long P[MAX+1]; //各点餐馆利润 
long long B[MAX+1]; //给定n个点开餐馆的最大利润 

long long DP(int n, int d);
long long DP_2(int n, int d); //动态规划：类似最长上升子序列算法 

int main() 
{
	int d, n, t;
	cin >> t;
	for (int i=0; i<t; i++)
	{
		cin >> n >> d;
		for (int j=1; j<=n; j++)
		{
			cin >> A[j];
		}
		for (int j=1; j<=n; j++)
		{
			cin >> P[j];
		}
		memset(B, 0, sizeof(B));
		cout << DP(n, d) << endl;
	}
	
    return 0;
}

long long DP(int n, int d) //动态规划：类似最长上升子序列算法 
{
	B[1] = P[1]; //只在位置1开餐馆 
	for (int i=2; i<=n; i++)
	{
		B[i] = max(B[i-1], P[i]); //比较不在位置i开餐馆和只在位置i开餐馆的大小  
		for (int j=i-1; j>0; j--)//寻求利润最大的开餐馆方法 
		{
			if (A[i] - A[j] > d && B[i] < B[j]+P[i])//找到第一个满足条件的就可以跳出循环了 
			{
				B[i] = B[j]+P[i];
				break;
			}
		}
	}
	
	return B[n];
}

long long DP_2(int n, int d) //动态规划：类似最长上升子序列算法 
{
	for (int i=1; i<=n; i++)
	{ 
		int j = i - 1;
		while (j>0 && A[i]-A[j]<=d)//找到第一个满足条件的就可以跳出循环了 
			j--;
		B[i] = max(B[i-1], B[j]+P[i]);
	}
	
	return B[n];
}
