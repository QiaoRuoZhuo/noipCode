/*
	Name: 33_计算分数加减表达式的值
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 33_计算分数加减表达式的值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
编写程序，输入n的值，求 1/1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + 1/7 - 1/8 + ... + (-1)n-1·1/n 的值。

输入
输入一个正整数n。1 <= n <= 1000。
输出
输出一个实数，为表达式的值，保留到小数点后四位。
样例输入
2
样例输出
0.5000
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n,f=1;
	double s=0;
    
    cin >> n;
    
    for (int i=1; i<=n; i++)  
    {
	 	s += 1.0 * f / i;
	 	f = -f;
	}
    
    printf("%0.4f", s);
			  
    return 0;
}
