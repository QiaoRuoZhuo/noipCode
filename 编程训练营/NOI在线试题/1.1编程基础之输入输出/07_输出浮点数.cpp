/*
	Name: 07:输出浮点数
	Copyright: 
	Author: 
	Date: 10-07-16 07:21
	Description: 
	07:输出浮点数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入一个双精度浮点数，分别按输出格式“%f”，“%f”保留5位小数，“%e”和“%g”的形式输出这个浮点数，每次在单独一行上输出。

输入
一个双精度浮点数。
输出
输出有四行：
第一行是按“%f”输出的双精度浮点数；
第二行是按“%f”保留5位小数输出的双精度浮点数；
第三行是按“%e”输出的双精度浮点数；
第四行是按“%g”输出的双精度浮点数。
样例输入
12.3456789
样例输出
12.345679
12.34568
1.234568e+001
12.3457

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	516kB	0ms	    203 B    	G++      10-07-16 07:40
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	double a;
	
	cin >> a;
	
	printf("%f\n", a);
	printf("%.5f\n", a);
	printf("%e\n", a);
	printf("%g\n", a);
    
    return 0;
}

