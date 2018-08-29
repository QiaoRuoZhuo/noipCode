/*
	Name: 06:浮点数向零舍入
	Copyright: 
	Author: 
	Date: 10-07-16 10:05
	Description: 
	06:浮点数向零舍入
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个单精度浮点数，将其向零舍入到整数。

说明：向零舍入的含义是，正数向下舍入，负数向上舍入。

提示：可以使用强制类型转换来实现。

输入
一个单精度浮点数。
输出
一个整数，即向零舍入到整数的结果。
样例输入
2.3
样例输出
2

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	252kB	0ms	    114 B    	G++      10-07-16 10:06
*/
#include <iostream>

using namespace std;

int main( )
{
	float a;
	
	cin >> a;
	cout << int(a);
	
    return 0;
}

