/*
	Name: 11:计算浮点数相除的余数
	Copyright: 
	Author: 
	Date: 11-07-16 15:38
	Description: 
	11:计算浮点数相除的余数
总时间限制: 1000ms 内存限制: 65536kB
描述
计算两个双精度浮点数a和b的相除的余数，a和b都是正数的。这里余数（r）的定义是：a = k * b + r，其中 k是整数， 0 <= r < b。

输入
输入仅一行，包括两个双精度浮点数a和b。
输出
输出也仅一行，a÷b的余数
样例输入
73.263 0.9973
样例输出
0.4601
提示
注意：输出时小数尾部没有多余的0，可以用下面这种格式：
double x;
x = 1.33;
printf("%g", x);

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	200kB	6ms	    178 B   	G++    2016-07-11 15:29:03
巧若拙	Accepted	10	200kB	0ms	    158 B   	G++    2016-07-11 15:35:22
*/
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int main( )
//{
//	double a, b;
//	
//	cin >> a >> b;
//	
//	while (a >= b)
//	{
//		a -= b;
//	}
//	
//	printf("%g", a);
//	
//    return 0;
//}

#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	double a, b;
	
	cin >> a >> b;

	printf("%g", a - b * int(a/b));
	
    return 0;
}

