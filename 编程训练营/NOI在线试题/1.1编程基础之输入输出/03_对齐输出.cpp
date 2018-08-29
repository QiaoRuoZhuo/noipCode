/*
	Name: 03:对齐输出
	Copyright: 
	Author: 巧若拙 
	Date: 09-07-16 21:32
	Description: 
	03:对齐输出
总时间限制: 1000ms 内存限制: 65536kB
描述
读入三个整数，按每个整数占8个字符的宽度，右对齐输出它们。

输入
只有一行，包含三个整数，整数之间以一个空格分开。
输出
只有一行，按照格式要求依次输出三个整数，之间以一个空格分开。
样例输入
123456789 0 -1
样例输出
123456789        0       -1

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	252kB	0ms	     256 B   	G++	   09-07-16 22:38
巧若拙  Accepted	10	252kB	0ms	     236 B   	G++	   09-07-16 22:41
*/
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main( )
//{
//	int a, b, c;
//	
//	cin >> a >> b >> c;
//	
//    cout << setw(8) << right << a << ' '; 
//	cout << setw(8) << right << b << ' ';
//	cout << setw(8) << right << c << endl;
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
using namespace std;

int main( )
{
	int a, b, c;
	
	cin >> a >> b >> c;
	
	cout.width(8);
    cout << a << ' ';
    cout.width(8);
    cout << b << ' ';
    cout.width(8);
    cout << c << endl;
    
    printf("%8d %8d %8d", a, b, c);
    
    return 0;
}
