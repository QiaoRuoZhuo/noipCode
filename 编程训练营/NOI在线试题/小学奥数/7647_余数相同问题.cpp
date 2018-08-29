/*
	Name: 7647_余数相同问题
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 7647_余数相同问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知三个正整数 a，b，c。

现有一个大于1的整数x，将其作为除数分别除a，b，c，得到的余数相同。

请问满足上述条件的x的最小值是多少？

数据保证x有解。

输入
一行，三个不大于1000000的正整数a，b，c，两个整数之间用一个空格隔开。
输出
一个整数，即满足条件的x的最小值。
样例输入
300 262 205
样例输出
19
来源
《奥数典型题举一反三（小学六年级）》 (ISBN 978-7-5445-2883-2) 第一章 第一讲 例1
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a, b, c, x;
    
    cin >> a >> b >> c;
    
    for (x=2; ; x++) //跳出死循环的技巧 
    {
	 	if (a%x == b%x && a%x == c%x)
	 	   break;
	}
    
    cout << x;
			  
    return 0;
}
