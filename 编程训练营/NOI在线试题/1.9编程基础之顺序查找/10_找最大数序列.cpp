/*
	Name: 10_找最大数序列
	Copyright: 
	Author: 
	Date: 16-08-17 11:50
	Description: 10_找最大数序列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入n行，每行不超过100个无符号整数，无符号数不超过4位。请输出最大整数以及最大整数所在的行号（行号从1开始）。
如果该数据在多个行中出现，则按从小到大输出相应行号，行号之间以一个逗号分开。
输入
一行输入一个正整数n（n <= 30）。
之后的n行，每行包含不超过100个无符号整数，整数之间以一个逗号分开。
输出
第一行：最大整数；
第二行：最大整数所在的行编号，逗号间隔。
样例输入
6
1,3,5,23,6,8,14
20,22,13,4,16
23,12,17,22
2,6,10,9,3,6
22,21,20,8,10
22,1,23,6,8,19,23
样例输出
23
1,3,6
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int M = 30;
int A[M];

int main() 
{
	int n, a, m=0, t=0;
	
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		do
		{
			cin >> a;
			if (m < a)
			{
				m = a;
				t = 0;
				A[t++] = i;
			}
			else if (m == a && A[t-1] != i)//注意最大值重复的情形 
			{
				A[t++] = i;
			}
		} while (getchar() != '\n');
	}
	
	cout << m << endl << A[0];
	for (int i=1; i<t; i++)
	{
		cout << ',' << A[i];
	}
	cout << endl;
	
	return 0;	
} 
