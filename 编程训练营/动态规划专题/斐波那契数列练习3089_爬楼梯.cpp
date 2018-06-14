/*
	Name: 3089_爬楼梯
	Copyright: 
	Author: 巧若拙 
	Date: 18-01-18 09:21
	Description: 
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数
例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级
也可以第一次走两级，第二次走一级，一共3种方法。

输入
输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <= N <= 30
输出
不同的走法数，每一行输入对应一行输出
样例输入
5
8
10
样例输出
8
34
89
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int dg(int n);

int main()
{
	int n;
	while(cin >> n)
	{
		cout << dg(n) << endl;
	}
	
	return 0;
}

int dg(int n)
{
	if (n == 1 || n == 2)
		return n;
	int a = 1, b = 2, c = 3;
	for (int i=3; i<=n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

