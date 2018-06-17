/*
	Name: 3532_最大上升子序列和
	Author: 巧若拙 
	Description: 3532_最大上升子序列和
描述
一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。对于给定的一个序列(a1, a2, ...,aN)，我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，这里1 <= i1 < i2 < ... < iK <= N。比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。这些子序列中序列和最大为18，为子序列(1, 3, 5, 9)的和.

你的任务，就是对于给定的序列，求出最大上升子序列和。注意，最长的上升子序列的和不一定是最大的，比如序列(100, 1, 2, 3)的最大上升子序列和为100，而最长上升子序列为(1, 2, 3)

输入
输入的第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000（可能重复）。
输出
最大上升子序列和
样例输入
7
1 7 3 5 9 4 8
样例输出
18
*/
#include<iostream>

using namespace std;

const int MAX = 1001; 
int A[MAX];
int S1[MAX]; //记录到元素i为止的最大上升子序列和
int S2[MAX]; //记录到元素i为止的最大上升子序列和

int DP_1(int n); //逆序处理 
int DP_2(int n); //顺序处理 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
	}
	
	cout << DP_1(n) << endl;//顺序处理，需要用到全局变量A[MAX]，另有S1[MAX]初始化为0。
	cout << DP_2(n) << endl;//顺序处理，需要用到全局变量A[MAX]，另有S2[MAX]初始化为0。
	
    return 0;
}

int DP_1(int n) //逆序搜索 
{
	int m = S1[n-1] = A[n-1]; //最大上升子序列和
	
	for (int i=n-2; i>=0; i--)
	{ 
		for (int j=i+1; j<n; j++) 
		{
			if (A[i] < A[j] && S1[i] < S1[j])
				S1[i] = S1[j];
		}
		S1[i] += A[i];  
		if (m < S1[i]) 
			m = S1[i];
	}
	
	return m;
}

int DP_2(int n) //顺序搜索 
{
	int m = S2[0] = A[0]; //最大上升子序列和
	
	for (int i=1; i<n; i++)
	{ 
		for (int j=i-1; j>=0; j--) 
		{
			if (A[i] > A[j] && S2[j] > S2[i])
				S2[i] = S2[j];
		}
		S2[i] += A[i];  
		if (m < S2[i]) 
			m = S2[i];
	}
	
	return m;
}
