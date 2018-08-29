/*
	Name: 18_验证子串
	Copyright: 
	Author: 
	Date: 01-09-17 22:06
	Description: 18_验证子串
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入两个字符串，验证其中一个串是否为另一个串的子串。
输入
输入两个字符串，每个字符串占一行，长度不超过200且不含空格。
输出
若第一个串s1是第二个串s2的子串，则输出(s1) is substring of (s2) 
否则，若第二个串s2是第一个串s1的子串，输出(s2) is substring of (s1) 
否则，输出 No substring。
样例输入
abc
dddncabca
样例输出
abc is substring of dddncabca
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 201;
char S1[N],S2[N];

int main() 
{
	gets(S1); gets(S2);
	if (strlen(S1) >= strlen(S2))
	{
		if (strstr(S1, S2) != NULL)
			cout << S2 << " is substring of " << S1 << endl;
		else
			cout << "No substring" << endl;
	}
	else
	{
		if (strstr(S2, S1) != NULL)
			cout << S1 << " is substring of " << S2 << endl;
		else
			cout << "No substring" << endl;
	}
	return 0;	
} 
