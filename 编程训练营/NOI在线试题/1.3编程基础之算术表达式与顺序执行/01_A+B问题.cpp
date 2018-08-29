/*
	Name: 01:A+B问题
	Copyright: 
	Author: 
	Date: 10-07-16 10:41
	Description: 
	01:A+B问题
总时间限制: 1000ms 内存限制: 65536kB
描述
在大部分的在线题库中，都会将A+B问题作为第一题，以帮助新手熟悉平台的使用方法。

A+B问题的题目描述如下：给定两个整数A和B，输出A+B的值。保证A、B及结果均在整型范围内。

现在请你解决这一问题。

输入
一行，包含两个整数A，B，中间用单个空格隔开。A和B均在整型范围内。
输出
一个整数，即A+B的值。保证结果在整型范围内。
样例输入
1 2
样例输出
3

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	256kB	0ms	    129 B    	G++      10-07-16 10:42
*/
#include <iostream>

using namespace std;

int main( )
{
	int a, b;
	
	cin >> a >> b;
	
	cout << a + b << endl;
	
    return 0;
}
