/*
	Name: 13:反向输出一个三位数
	Copyright: 
	Author: 
	Date: 11-07-16 16:01
	Description: 
	13:反向输出一个三位数
总时间限制: 1000ms 内存限制: 65536kB
描述
将一个三位数反向输出。

输入
一个三位数n。
输出
反向输出n。
样例输入
100
样例输出
001
提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	200kB	1ms	    166 B    	G++    2016-07-11 15:48:07
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	int r;
	
	cin >> r;
	
	cout << r%10 << (r%100) / 10 << r / 100 << endl;
	
    return 0;
}

