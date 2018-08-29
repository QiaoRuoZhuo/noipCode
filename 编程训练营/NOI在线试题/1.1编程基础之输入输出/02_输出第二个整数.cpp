/*
	Name: 02:输出第二个整数
	Copyright: 
	Author: 
	Date: 09-07-16 22:44
	Description: 
	02:输出第二个整数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入三个整数，把第二个输入的整数输出。

输入
只有一行，共三个整数，整数之间由一个空格分隔。整数是32位有符号整数。
输出
只有一行，一个整数，即输入的第二个整数。
样例输入
123 456 789
样例输出
456

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	256kB	0ms	    138 B       G++	   09-07-16 22:48
*/


#include <iostream>
using namespace std;

int main( )
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
    cout << b << endl;
    
    return 0;
}
