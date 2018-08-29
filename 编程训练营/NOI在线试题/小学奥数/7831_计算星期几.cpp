/*
	Name: 7831_计算星期几
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 7831_计算星期几
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
假设今天是星期日，那么过ab天之后是星期几？

输入
两个正整数a，b，中间用单个空格隔开。0 < a <= 100, 0 < b <= 10000。
输出
一个字符串，代表过ab?天之后是星期几。
其中，Monday是星期一，Tuesday是星期二，Wednesday是星期三，Thursday是星期四，Friday是星期五，Saturday是星期六，Sunday是星期日。
样例输入
3 2000
样例输出
Tuesday
来源
《奥数典型题举一反三（小学六年级）》 (ISBN 978-7-5445-2883-2) 模拟试题二 第16题
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
	 	m = (m * a )% 7;
	}
    
    switch(m)
	{
		case 1: cout << "Monday";break;
		case 2: cout << "Tuesday";break;
		case 3: cout << "Wednesday";break;
		case 4: cout << "Thursday";break;
		case 5: cout << "Friday";break;
		case 6: cout << "Saturday";break;
		case 0: cout << "Sunday";break;
	} 
	  
    return 0;
}
