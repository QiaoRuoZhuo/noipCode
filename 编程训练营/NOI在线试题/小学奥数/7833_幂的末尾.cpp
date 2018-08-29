/*
	Name: 7833_幂的末尾
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 7833_幂的末尾
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
幂ab的末3位数是多少？

输入
两个正整数a，b。1 <= a <= 100，1 <= b <= 10000。
输出
从高位到低位输出幂的末三位数字，中间无分隔符。若幂本身不足三位，在前面补零。
样例输入
7 2011
样例输出
743
来源
2011年我爱数学少年夏令营数学竞赛 第4题
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a, b, d, m=1;
    
    cin >> a >> b;
    
    for (int i=0; i<b; i++)  
    {
	 	m = (m * a )% 1000;
	}
    
    printf("%03d", m);
	  
    return 0;
}
