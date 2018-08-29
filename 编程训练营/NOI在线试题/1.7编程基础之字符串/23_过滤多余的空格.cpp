/*
	Name: 23_过滤多余的空格
	Copyright: 
	Author: 
	Date: 03-09-17 07:53
	Description: 23_过滤多余的空格
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一个句子中也许有多个连续空格，过滤掉多余的空格，只留下一个空格。

输入
一行，一个字符串（长度不超过200），句子的头和尾都没有空格。
输出
过滤之后的句子。
样例输入
Hello      world.This is    c language.
样例输出
Hello world.This is c language.
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
char A[N];

int main() 
{
	gets(A); 
	int s = 0;
	for (int i=0; A[i]!='\0'; i++)
	{
		if (A[i] == ' ')
		{
			if (s == 0) //只输出1个空格 
				cout << ' ';
			s = 1;
		}
		else
		{
			cout << A[i];
			s = 0;
		}
	}
	cout << endl;
			
	return 0;	
} 
