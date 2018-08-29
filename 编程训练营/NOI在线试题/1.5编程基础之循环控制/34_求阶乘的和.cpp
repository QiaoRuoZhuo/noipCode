/*
	Name: 34_求阶乘的和
	Copyright: 
	Author: 巧若拙 
	Date: 03-07-17 21:14
	Description: 34_求阶乘的和
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定正整数n，求不大于n的正整数的阶乘的和（即求1!+2!+3!+...+n!）

输入
输入有一行，包含一个正整数n（1 < n < 12）。
输出
输出有一行：阶乘的和。
样例输入
5
样例输出
153
*/
#include<iostream>

using namespace std;

int main()
{
    int n, s=0, f=1;
    cin >> n;
    
	for (int i=1; i<=n; i++) 
	{
	 	f *= i; // f = i!
	 	s += f;
	} 
	
	cout << s;
			  
    return 0;
}
