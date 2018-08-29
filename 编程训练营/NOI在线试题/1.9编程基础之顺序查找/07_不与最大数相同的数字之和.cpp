/*
	Name: 07_不与最大数相同的数字之和
	Copyright: 
	Author: 
	Date: 16-08-17 10:56
	Description: 07_不与最大数相同的数字之和
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输出一个整数数列中不与最大数相同的数字之和。

输入
输入分为两行：
第一行为N(N为接下来数的个数，N <= 100)；
第二行为N个整数，数与数之间以一个空格分开，每个整数的范围是-1000,000到1000,000。
输出
输出为N个数中除去最大数其余数字之和。
样例输入
3
1 2 3 
样例输出
3
*/
#include <iostream>

using namespace std;

const int M = 100;

int main() 
{
	int A[M] = {0};
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	int m = A[0];
	for (int i=1; i<n; i++)
	{
		if (A[i] > m)
			m = A[i];
	}
	
	int s = 0;
	for (int i=0; i<n; i++)
	{
		if (A[i] != m)
			s += A[i];
	}
	cout << s << endl;
	
	return 0;	
} 
