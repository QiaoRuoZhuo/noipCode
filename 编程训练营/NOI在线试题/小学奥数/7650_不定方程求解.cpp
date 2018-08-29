/*
	Name: 7650_不定方程求解
	Copyright: 
	Author: 巧若拙 
	Date: 03-07-17 21:14
	Description: 7650_不定方程求解
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定正整数a，b，c。求不定方程 ax+by=c 关于未知数x和y的所有非负整数解组数。

输入
一行，包含三个正整数a，b，c，两个整数之间用单个空格隔开。每个数均不大于1000。
输出
一个整数，即不定方程的非负整数解组数。
样例输入
2 3 18
样例输出
4
*/
//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//    int a, b, c, s = 0;
//    
//    cin >> a >> b >> c;
//    
//	for (int x=0; x<=c/a; x++) 
//	{
//	 	for (int y=0; y<=c/b; y++)
//	 	{
//		 	s += (a*x + b*y == c);
//	    }
//	} 
//	
//	cout << s << endl;
//			  
//    return 0;
//}

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int a,b,c;
	int x,y,s=0;
	
	cin>>a>>b>>c;
	
	for(x=0;x<=c/a;x++)
	{
		y=(c-a*x)/b;
		if(a*x+b*y==c)
			s++;
	}
	cout<<s;
	
	return 0;
}

