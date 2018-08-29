/*
	Name: 09:字符菱形
	Copyright: 
	Author: 
	Date: 10-07-16 07:42
	Description: 
	09:字符菱形
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符，用它构造一个对角线长5个字符，倾斜放置的菱形。

输入
输入只有一行， 包含一个字符。
输出
该字符构成的菱形。
样例输入
*
样例输出
  *
 ***
*****
 ***
  *
  
提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	256kB	0ms	    534 B    	G++      10-07-16 07:46
*/

#include <iostream>

using namespace std;

int main( )
{
	const int n = 3;
	char c;
	
	cin >> c;
	
	
	for (int i=0; i<n; i++)  //顺序输出 
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
	
	for (int i=n-2; i>=0; i--)  //逆序输出 
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

