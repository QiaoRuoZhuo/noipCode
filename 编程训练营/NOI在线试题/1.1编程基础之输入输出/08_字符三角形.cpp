/*
	Name: 08:字符三角形
	Copyright: 
	Author: 
	Date: 10-07-16 06:48
	Description: 
	08:字符三角形
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符，用它构造一个底边长5个字符，高3个字符的等腰字符三角形。

输入
输入只有一行， 包含一个字符。
输出
该字符构成的等腰三角形，底边长5个字符，高3个字符。
样例输入
*
样例输出
  *
 ***
*****

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	252kB	0ms	     309 B	    G++	    10-07-16 07:08
*/
#include <iostream>

using namespace std;

int main( )
{
	const int n = 3;
	char c;
	
	cin >> c;
	
	
	for (int i=0; i<n; i++)
	{
		for (int j=n-i; j>1; j--) //输出空格 
		{
			cout << ' ';
		}
		
		for (int j=0; j<i+i+1; j++)//输出符号 
		{
			cout << c;
		}
		cout <<  endl;
	}
	
    
    return 0;
}
