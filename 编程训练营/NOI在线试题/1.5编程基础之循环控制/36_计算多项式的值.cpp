/*
	Name: 36_计算多项式的值
	Copyright: 
	Author: 巧若拙 
	Date: 03-07-17 21:14
	Description: 36_计算多项式的值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
假定多项式的形式为xn+xn-1+…+x2+x+1，请计算给定单精度浮点数x和正整数n值的情况下这个多项式的值。

输入
输入仅一行，包括x和n，用单个空格隔开。x在float范围内，n <= 1000000。
输出
输出一个实数，即多项式的值，精确到小数点后两位。保证最终结果在float范围内。
样例输入
2.0 4
样例输出
31.00
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    float x, s=1, m=1;
    
    cin >> x >> n;
    
	for (int i=1; i<=n; i++) 
	{
	 	m *= x;  
	 	s += m;
	} 
	
	printf("%.2f", s);
			  
    return 0;
}
