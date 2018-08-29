/*
	Name: 06:甲流疫情死亡率
	Copyright: 
	Author: 
	Date: 10-07-16 10:59
	Description: 
	06:甲流疫情死亡率
总时间限制: 1000ms 内存限制: 65536kB
描述
甲流并不可怕，在中国，它的死亡率并不是很高。请根据截止2009年12月22日各省报告的甲流确诊数和死亡数，计算甲流在各省的死亡率。

输入
输入仅一行，有两个整数，第一个为确诊数，第二个为死亡数。
输出
输出仅一行，甲流死亡率，以百分数形式输出，精确到小数点后3位。
样例输入
10433 60
样例输出
0.575%
提示
输出%可以使用printf(“%%”);

提交人	 结果	   分数	内存	时间	代码长度	语言	提交时间
巧若拙	Accepted	10	256kB	0ms	    172 B    	G++      10-07-16 11:02
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main( )
{
	int a, b;
	
	cin >> a >> b;
	
	printf("%.3lf%%", double(b) / double(a) * 100);
	
    return 0;
}
