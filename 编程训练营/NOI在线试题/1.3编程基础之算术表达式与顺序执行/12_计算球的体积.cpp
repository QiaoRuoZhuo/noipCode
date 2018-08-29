/*
	Name: 12:计算球的体积
	Copyright: 
	Author: 
	Date: 11-07-16 15:48
	Description: 
	12:计算球的体积
总时间限制: 1000ms 内存限制: 65536kB
描述
对于半径为r的球，其体积的计算公式为V=4/3*πr3，这里取π= 3.14。

现给定r，求V。

输入
输入为一个不超过100的非负实数，即球半径，类型为double。
输出
输出一个实数，即球的体积，保留到小数点后2位。
样例输入
4
样例输出
267.95
提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	200kB	2ms	    186 B    	G++    2016-07-11 15:42:22
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	const double pi = 3.14; 
	double r;
	
	cin >> r;
	
	printf("%.2lf", pi * r * r * r * 4 / 3);
	
    return 0;
}


