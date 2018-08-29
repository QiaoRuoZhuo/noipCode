/*
	Name: 05_最大值和最小值的差
	Copyright: 
	Author: 
	Date: 15-08-17 21:07
	Description: 05_最大值和最小值的差
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输出一个整数序列中最大的数和最小的数的差。

输入
第一行为M，表示整数个数，整数个数不会大于10000；
第二行为M个整数，以空格隔开，每个整数的绝对值不会大于10000。
输出
输出M个数中最大值和最小值的差。
样例输入
5
2 5 7 4 2
样例输出
5
*/
#include <iostream>

using namespace std;

const int M = 10000;
int A[M];

int main() 
{
	int n;
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	int min=A[0], max=A[0];
	for (int i=1; i<n; i++)
	{
		if (A[i] > max)
			max = A[i];
		else if (A[i] < min)
			min = A[i];
	}
	
	cout << max-min << endl;
	
	return 0;	
} 
