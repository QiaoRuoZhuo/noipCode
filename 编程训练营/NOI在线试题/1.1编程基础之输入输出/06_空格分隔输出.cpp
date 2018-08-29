/*
	Name: 06:空格分隔输出
	Copyright: 
	Author: 
	Date: 10-07-16 07:13
	Description: 
	06:空格分隔输出
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入一个字符，一个整数，一个单精度浮点数，一个双精度浮点数，然后按顺序输出它们，并且要求在他们之间用一个空格分隔。输出浮点数时保留6位小数。

输入
共有四行：
第一行是一个字符；
第二行是一个整数；
第三行是一个单精度浮点数；
第四行是一个双精度浮点数。
输出
输出字符、整数、单精度浮点数和双精度浮点数，之间用空格分隔。
样例输入
a
12
2.3
3.2
样例输出
a 12 2.300000 3.200000

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	516kB	0ms	    296 B    	G++      10-07-16 07:20
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main( )
{
	char a;
	int b;
	float c;
	double d;
	
	cin >> a >> b >> c >> d;
	
	cout << a << ' ';
	cout << b << ' ';
	cout << fixed << setprecision(6) << c << ' ';
	cout << fixed << setprecision(6) << d << endl;
	
	printf("%c %d %.6f %.6lf", a,b,c,d);
    
    return 0;
}
