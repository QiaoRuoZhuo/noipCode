/*
	Name: 11_连续出现的字符
	Copyright: 
	Author: 
	Date: 16-08-17 14:56
	Description: 11_连续出现的字符
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符串，在字符串中找到第一个连续出现至少k次的字符。
输入
第一行包含一个正整数k，表示至少需要连续出现的次数。1 <= k <= 1000。
第二行包含需要查找的字符串。字符串长度在1到1000之间，且不包含任何空白符。
输出
若存在连续出现至少k次的字符，输出该字符；否则输出No。
样例输入
3
abcccaaab
样例输出
c
*/
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string A;
	int k;
	cin >> k;
	cin >> A;
	int n = A.length();
	
	if (k == 1)//单独处理k==1的情形
	{
		cout << A[0] << endl;
		return 0;
	} 
	
	int s = 1;
	for (int i=1; i<n; i++)
	{
		if (A[i] == A[i-1])
		{
			if (++s == k)
			{
				cout << A[i] << endl;
				return 0;
			} 
		}
		else //还原 
		{
			s = 1;
		}
	}
	cout << "No" << endl;
	
	return 0;	
} 
