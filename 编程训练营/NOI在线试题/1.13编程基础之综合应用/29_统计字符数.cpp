/*
	Name: 29_统计字符数
	Copyright: 
	Author: 
	Date: 18-08-17 15:31
	Description: 29_统计字符数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个由a-z这26个字符组成的字符串，统计其中哪个字符出现的次数最多。
输入
输入包含一行，一个字符串，长度不超过1000。
输出
输出一行，包括出现次数最多的字符和该字符出现的次数，中间以一个空格分开。如果有多个字符出现的次数相同且最多，那么输出ascii码最小的那一个字符。
样例输入
abbccc
样例输出
c 3
*/
#include<iostream>
#include<string>

using namespace std;

int T[26];

int main()
{
	string A;
	cin >> A;
	int n = A.length();
	
	for (int i=0; i<n; i++)//将元素装入桶中 
	{
		T[A[i]-'a']++;
	}
	int m = 0;
	for (int i=1; i<26; i++)  
	{
		if (T[i] > T[m])
			m = i;
	}
	cout << char(m+'a') << " " << T[m] << endl;
	
    return 0;
}
