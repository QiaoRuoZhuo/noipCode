/*
	Name: 08:打印字符
	Copyright: 
	Author: 
	Date: 10-07-16 10:11
	Description: 
	08:打印字符
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个ASCII码，输出对应的字符。

输入
一个整数，即字符的ASCII码，保证存在对应的可见字符。
输出
一行，包含相应的字符。
样例输入
65
样例输出
A

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	252kB	0ms	    113 B    	G++      10-07-16 10:12
*/
#include <iostream>

using namespace std;

int main( )
{
	int a;
	
	cin >> a;
	cout << char(a);
	
	int b=89.43;
	cout <<endl<< a%b << endl;
	
    return 0;
}
