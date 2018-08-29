/*
	Name: 01_与指定数字相同的数的个数
	Copyright: 
	Author: 
	Date: 14-08-17 21:14
	Description: 01_与指定数字相同的数的个数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输出一个整数序列中与指定数字相同的数的个数。

输入
输入包含三行：
第一行为N，表示整数序列的长度(N <= 100)；
第二行为N个整数，整数之间以一个空格分开；
第三行包含一个整数，为指定的整数m。
输出
输出为N个数中与m相同的数的个数。
样例输入
3
2 3 2
2
样例输出
2
*/
#include <iostream>

using namespace std;

const int M = 100;
int NumOfValue(const int A[], int n, int x);

int main() 
{
	int A[M] = {0};
	int n, m;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	cin >> m;
	cout << NumOfValue(A, n, m) << endl; //语句3
	
	return 0;	
} 

//统计数组A中值为x的元素的数量 
int NumOfValue(const int A[], int n, int x)
{
	int s = 0;
	for (int i=0; i<n; i++)
	{
		s += (A[i] == x); 
	}
	return s;
}
