/*
	Name: 14:大象喝水
	Copyright: 
	Author: 
	Date: 11-07-16 16:07
	Description: 
	14:大象喝水
总时间限制: 1000ms 内存限制: 65536kB
描述
一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴。

输入
输入有一行：包行两个整数，以一个空格分开，分别表示小圆桶的深h和底面半径r，单位都是厘米。
输出
输出一行，包含一个整数，表示大象至少要喝水的桶数。
样例输入
23 11
样例输出
3
提示
如果一个圆桶的深为h厘米，底面半径为r厘米，那么它最多能装Pi * r * r * h立方厘米的水。(设Pi=3.14159) 
1升 = 1000毫升
1毫升 = 1 立方厘米

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	200kB	1ms	    259 B    	G++    2016-07-11 15:59:36
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	const double pi = 3.14159; 
	int r, h;
	
	cin >> h >> r;
	
	double v = pi * r * r * h; 
	int n = 20000 / v; 
	
	if (n * v < 20000)
	{
		n++;
	}
	
	cout << n << endl;
	
    return 0;
}

