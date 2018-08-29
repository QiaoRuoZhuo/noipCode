/*
	Name: 7830_求小数的某一位
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 7830_求小数的某一位
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
分数a/b化为小数后，小数点后第n位的数字是多少？

输入
三个正整数a，b，n，相邻两个数之间用单个空格隔开。0 < a < b < 100，1 <= n <= 10000。
输出
一个数字。
样例输入
1 2 1
样例输出
5
来源
《奥数典型题举一反三（小学五年级）》 (ISBN 978-7-5445-2882-5) 模拟试卷二 第3题
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a, b, n;
    int factor, remainder;
    
    cin >> a >> b >> n;
    
    a *= 10;
    for (int i=0; i<n; i++)  
    {
	 	factor = a / b;
	 	remainder = a % b;
	 	a = remainder * 10;
	}
    
    cout << factor;
			  
    return 0;
}
