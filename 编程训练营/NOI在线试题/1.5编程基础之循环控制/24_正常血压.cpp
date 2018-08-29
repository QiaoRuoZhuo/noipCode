/*
	Name:24_正常血压
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 24_正常血压
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
监护室每小时测量一次病人的血压，若收缩压在90 - 140之间并且舒张压在60 - 90之间（包含端点值）则称之为正常，
现给出某病人若干次测量的血压值，计算病人保持正常血压的最长小时数。

输入
第一行为一个正整数n，n < 100
其后有n行，每行2个正整数，分别为一次测量的收缩压和舒张压，中间以一个空格分隔。
输出
输出仅一行，血压连续正常的最长小时数。
样例输入
4
100 80
90 50
120 60
140 90
样例输出
2
来源
习题(5-6) 医学部 2010 期末试题 周恺
*/
#include<iostream>

using namespace std;

int main()
{
    int n, low, high;
	int time=0, maxTime=0;
    
    cin >> n;
    
    for (int i=0; i<n; i++)
    {
	 	cin >> high >> low;
	 	if (high >= 90 && high <= 140 && low >=60 && low <= 90)
	 	{
    	    time++;
	    }
	    else
	    {
		 	time = 0;
	 	}
	 	
	 	maxTime = (time > maxTime) ? time : maxTime;
	}
    
    cout << maxTime << endl;
			  
    return 0;
}
