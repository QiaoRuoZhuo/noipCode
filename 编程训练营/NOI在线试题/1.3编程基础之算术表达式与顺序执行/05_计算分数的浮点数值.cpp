/*
	Name: 05:计算分数的浮点数值
	Copyright: 
	Author: 
	Date: 10-07-16 10:52
	Description: 
	05:计算分数的浮点数值
总时间限制: 1000ms 内存限制: 65536kB
描述
两个整数a和b分别作为分子和分母，既分数 a/b ，求它的浮点数值（双精度浮点数，保留小数点后9位）

输入
输入仅一行，包括两个整数a和b
输出
输出也仅一行，分数 a/b 的浮点数值（双精度浮点数，保留小数点后9位）
样例输入
5 7
样例输出
0.714285714
提示
使用printf("%.9lf", ...)实现保留小数点后9位

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	256kB	0ms	    164 B    	G++      10-07-16 10:58
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	int a, b;
	
	cin >> a >> b;
	
	printf("%.9lf", double(a) / double(b));
	
    return 0;
}
