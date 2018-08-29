/*
	Name: 7826_分苹果
	Copyright: 
	Author: 巧若拙 
	Date: 01-07-17 20:18
	Description: 7826_分苹果
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
把一堆苹果分给n个小朋友，要使每个人都能拿到苹果，而且每个人拿到的苹果数都不同的话，这堆苹果至少应该有多少个？

输入
一个不大于1000的正整数n，代表小朋友人数。
输出
一个整数，表示满足条件的最少苹果个数。
样例输入
8
样例输出
36
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n, s=0;
    
    cin >> n;
    
    for (int i=1; i<=n; i++)  
    {
	 	s += i;
	}
    
    cout << s;
			  
    return 0;
}
