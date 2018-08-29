/*
	Name: 02_找第一个只出现一次的字符
	Copyright: 
	Author: 
	Date: 31-08-17 16:43
	Description: 02_找第一个只出现一次的字符
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

输入
一个字符串，长度小于100000。
输出
输出第一个仅出现一次的字符，若没有则输出no。
样例输入
abcabd
样例输出
c
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100001;
char A[N];

int main() 
{
	gets(A);
	char *q, *r, *p=A;
	while (*p != '\0')
	{
		q = strchr(A, *p);//查找指定字符在字符串中第一次出现的位置 
		r = strrchr(A, *p);//查找指定字符在字符串中最后一次出现的位置 
		if (q == r)
			break;
		p++;
	}
	if (*p != '\0')
		cout << *p << endl;
	else
		cout << "no" << endl;
		
	return 0;	
} 
