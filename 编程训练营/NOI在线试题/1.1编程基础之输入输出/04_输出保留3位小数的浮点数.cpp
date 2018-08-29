/*
	Name: 04:输出保留3位小数的浮点数
	Copyright: 
	Author: 
	Date: 09-07-16 22:56
	Description: 
	04:输出保留3位小数的浮点数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入一个单精度浮点数，保留3位小数输出这个浮点数。

输入
只有一行，一个单精度浮点数。
输出
也只有一行，读入的单精度浮点数。
样例输入
12.34521
样例输出
12.345

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	516kB	0ms	    168 B   	G++	    09-07-16 23:02

*/



#include <iostream>
using namespace std;

int main( )
{
	float a;
	
	cin >> a;
	
	cout.setf(ios::fixed);
	cout.precision(3);
    cout << a << endl;
    
    return 0;
}
