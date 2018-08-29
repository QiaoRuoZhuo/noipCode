/*
	Name: 02:计算(a+b)*c的值
	Copyright: 
	Author: 
	Date: 10-07-16 10:44
	Description: 
	02:计算(a+b)*c的值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定3个整数a、b、c，计算表达式(a+b)*c的值。

输入
输入仅一行，包括三个整数a、b、c, 数与数之间以一个空格分开。
(－10,000 < a,b,c < 10,000)
输出
输出一行，即表达式的值
样例输入
2 3 5
样例输出
25

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	256kB	0ms	    143 B    	G++      10-07-16 10:46
*/
#include <iostream>

using namespace std;

int main( )
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
	cout << (a + b) * c << endl;
	
    return 0;
}
