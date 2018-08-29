/*
	Name: 21_单词替换
	Copyright: 
	Author: 
	Date: 02-09-17 16:22
	Description: 21_单词替换
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。
现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
输入
输入包括3行，
第1行是包含多个单词的字符串 s;
第2行是待替换的单词a(长度 <= 100);
第3行是a将被替换的单词b(长度 <= 100).
s, a, b 最前面和最后面都没有空格.
输出
输出只有 1 行，将s中所有单词a替换成b之后的字符串。
样例输入
You want someone to help you
You
I
样例输出
I want someone to help you
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 101;
char s[N],a[N],b[N];

int main() 
{
	gets(s); gets(a); gets(b);
	int n = strlen(a);
	char *q, *r, *p = s;
	while (*p != '\0')//遍历字符串s
	{
		q = strstr(p, a);
		if (q != NULL)
		{
			for (r=p; r<q; r++)
			{
				cout << *r;
			}
			if ((q==p || *(q-1)==' ') && (*(q+n)=='\0' || *(q+n)==' '))	//全单词匹配 
				cout << b;
			else //单词部分匹配 
				cout << a;
			p = q + n; 
		}
		else
		{
			cout << p;
			break;
		}
	} 
	cout << endl;
			
	return 0;	
} 
