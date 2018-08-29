/*
	Name: 16_忽略大小写的字符串比较
	Copyright: 
	Author: 
	Date: 01-09-17 21:04
	Description: 16_忽略大小写的字符串比较
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一般我们用strcmp可比较两个字符串的大小，比较方法为对两个字符串从前往后逐个字符相比较（按ASCII码值大小比较），直到出现不同的字符或遇到'\0'为止。
如果全部字符都相同，则认为相同；如果出现不相同的字符，则以第一个不相同的字符的比较结果为准
（注意：如果某个字符串遇到'\0'而另一个字符串还未遇到'\0'，则前者小于后者）。
但在有些时候，我们比较字符串的大小时，希望忽略字母的大小，例如"Hello"和"hello"在忽略字母大小写时是相等的。
请写一个程序，实现对两个字符串进行忽略字母大小写的大小比较。
输入
输入为两行，每行一个字符串，共两个字符串。（每个字符串长度都小于80）
输出
如果第一个字符串比第二个字符串小，输出一个字符"<"；
如果第一个字符串比第二个字符串大，输出一个字符">"；
如果两个字符串相等，输出一个字符"="。
样例输入
Hello, how are you?
hello, How are you?
样例输出
=
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 81;
char S1[N],S2[N];

int main() 
{
	gets(S1); gets(S2);
	for (int i=0; S1[i]!='\0'; i++)
	{
		if (S1[i]>='A' && S1[i]<='Z')
			S1[i] += 32;
	}
	for (int i=0; S2[i]!='\0'; i++)
	{
		if (S2[i]>='A' && S2[i]<='Z')
			S2[i] += 32;
	}
	int a = strcmp(S1, S2);
	if (a < 0)
		cout << "<" << endl;
	else if(a > 0)
		cout << ">" << endl;
	else
		cout << "=" << endl;
		
	return 0;	
} 
