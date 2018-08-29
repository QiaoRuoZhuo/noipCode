/*
	Name: 10:Hello, World!的大小
	Copyright: 
	Author: 
	Date: 10-07-16 09:37
	Description: 
	10:Hello, World!的大小
总时间限制: 1000ms 内存限制: 65536kB
描述
还记得在上一章里，我们曾经输出过的“Hello, World!”吗？

它虽然不是本章所涉及的基本数据类型的数据，但我们同样可以用sizeof函数获得它所占用的空间大小。

请编程求出它的大小，看看跟你设想的是否一样？

输入
无。
输出
一个整数，即“Hello, World!”的大小。
样例输入
（无）
样例输出
（不提供）
提示
“Hello, World!”实际上是字符串类型，将在1.7章中详细介绍。

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	252kB	0ms	   139 B    	G++      10-07-16 10:24
*/
#include <iostream>

using namespace std;

int main( )
{
	const char s[] = "Hello, World!";
	
	cout << sizeof(s) << endl;
	
    return 0;
}

