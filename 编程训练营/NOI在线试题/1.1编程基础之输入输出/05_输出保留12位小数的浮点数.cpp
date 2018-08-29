/*
	Name: 05:输出保留12位小数的浮点数
	Copyright: 
	Author: 
	Date: 10-07-16 07:08
	Description: 
	05:输出保留12位小数的浮点数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入一个双精度浮点数，保留12位小数，输出这个浮点数。

输入
只有一行，一个双精度浮点数。
输出
也只有一行，保留12位小数的浮点数。
样例输入
3.1415926535798932
样例输出
3.141592653580

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	516kB	0ms	    170 B   	G++	   10-07-16 07:14
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main( )
{
	double a;
	
	cin >> a;
	
	cout << fixed << setprecision(12) << a << endl;
	printf("%.12lf", a);
    
    return 0;
}
