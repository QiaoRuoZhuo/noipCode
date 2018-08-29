/*
	Name: 10:计算并联电阻的阻值
	Copyright: 
	Author: 
	Date: 10-07-16 11:15
	Description: 
	10:计算并联电阻的阻值
总时间限制: 1000ms 内存限制: 65536kB
描述
对于阻值为r1和r2的电阻，其并联电阻阻值公式计算如下：

R = 1/(1/r1 + 1/r2)

输入
两个电阻阻抗大小，浮点型，以一个空格分开。
输出
并联之后的阻抗大小，结果保留小数点后2位
样例输入
1 2
样例输出
0.67
提示
计算过程使用float类型

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	516kB	0ms	    164 B    	G++    10-07-16 11:18
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	float r1, r2;
	
	cin >> r1 >> r2;
	
	printf("%.2f", 1/(1/r1 + 1/r2));
	
    return 0;
}



