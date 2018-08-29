/*
	Name: 20_删除单词后缀
	Copyright: 
	Author: 
	Date: 02-09-17 15:56
	Description: 20_删除单词后缀
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个单词，如果该单词以er、ly或者ing后缀结尾， 则删除该后缀（题目保证删除后缀后的单词长度不为0），否则不进行任何操作。
输入
输入一行，包含一个单词（单词中间没有空格，每个单词最大长度为32）。
输出
输出按照题目要求处理后的单词。
样例输入
referer
样例输出
refer
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 33;
char S[N];

int main() 
{
	gets(S);
	int n = strlen(S);
	if ((S[n-2]=='e' && S[n-1]=='r') || (S[n-2]=='l' && S[n-1]=='y'))
	{
		for (int i=0; i<n-2; i++)
			cout << S[i];
		cout << endl;
	}
	else if (S[n-3]=='i' && S[n-2]=='n' && S[n-1]=='g')
	{
		for (int i=0; i<n-3; i++)
			cout << S[i];
		cout << endl;
	}
	else
		cout << S << endl;
			
	return 0;	
} 
