/*
	Name: 17_字符串判等
	Copyright: 
	Author: 
	Date: 01-09-17 21:35
	Description: 17_字符串判等
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
判断两个由大小写字母和空格组成的字符串在忽略大小写，且忽略空格后是否相等。
输入
两行，每行包含一个字符串。
输出
若两个字符串相等，输出YES，否则输出NO。
样例输入
a A bb BB ccc CCC
Aa BBbb CCCccc
样例输出
YES
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
char S1[N],S2[N];

void Fun(char *S);//去掉空格并将大写字母转换为小写字母

int main() 
{
	gets(S1); gets(S2);
	Fun(S1); Fun(S2);
	if (strcmp(S1, S2) == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
		
	return 0;	
} 
void Fun(char *S)//去掉空格并将大写字母转换为小写字母 
{
	int i, j;
	for (i=0,j=0; S[i]!='\0'; i++)
	{
		if (S[i] == ' ')
			continue;
		if (S[i]>='A' && S[i]<='Z')
			S[j++] = S[i] + 32;
		else
			S[j++] = S[i];
	}
	S[j] = '\0';
}
