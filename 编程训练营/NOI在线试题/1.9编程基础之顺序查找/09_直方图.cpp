/*
	Name: 09_直方图
	Copyright: 
	Author: 
	Date: 16-08-17 11:26
	Description: 09_直方图
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个非负整数数组，统计里面每一个数的出现次数。我们只统计到数组里最大的数。
假设 Fmax （Fmax < 10000）是数组里最大的数，那么我们只统计 {0,1,2.....Fmax} 里每个数出现的次数。
输入
第一行n是数组的大小。1 <= n <= 10000。
紧接着一行是数组的n个元素。
输出
按顺序输出每个数的出现次数，一行一个数。如果没有出现过，则输出0。
对于例子中的数组，最大的数是3，因此我们只统计{0,1,2,3}的出现频数。
样例输入
5
1 1 2 3 1
样例输出
0
3
1 
1

算法分析：桶排序 
*/
#include <iostream>

using namespace std;

const int M = 10000;
int A[M+1];

int main() 
{
	int n, p;
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> p;
		A[p]++;
	}
	
	for (p=M; p>0; p--)
	{
		if (A[p] > 0)
			break;
	}
	for (int i=0; i<=p; i++)
	{
		cout << A[i] << endl;
	}
	
	return 0;	
} 
