/*
	Name: 07:打印ASCII码
	Copyright: 
	Author: 
	Date: 10-07-16 10:09
	Description: 
	07:打印ASCII码
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个除空格以外的可见字符（保证在函数scanf中可使用格式说明符%c读入），输出其ASCII码。

输入
一个除空格以外的可见字符。
输出
一个十进制整数，即该字符的ASCII码。
样例输入
A
样例输出
65

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	252kB	0ms	    113 B    	G++      10-07-16 10:10
*/
#include <iostream>

using namespace std;

int main( )
{
	char a;
	
	cin >> a;
	cout << int(a);
	
    return 0;
}
