/*
	Name: 06_整数奇偶排序
	Copyright: 
	Author: 
	Date: 18-08-17 16:32
	Description: 06_整数奇偶排序
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定10个整数的序列，要求对其重新排序。排序要求:
1.奇数在前，偶数在后；
2.奇数按从大到小排序；
3.偶数按从小到大排序。
输入
输入一行，包含10个整数，彼此以一个空格分开，每个整数的范围是大于等于0，小于等于100。
输出
按照要求排序后输出一行，包含排序后的10个整数，数与数之间以一个空格分开。
样例输入
4 7 3 13 11 12 0 47 34 98
样例输出
47 13 11 7 3 0 4 12 34 98
*/
#include <iostream>

using namespace std;

const int M = 10;
const int N = 100;
int A[M];
int T[N+1];//桶排序专用数组（元素值为0-N的整数） 

int main()
{
	int n = 10;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
		T[A[i]]++; //考虑有相同元素值的情况 
	}
	for (int i=N-1; i>0; i-=2) //从高到低输出奇数
	{
		for (int j=T[i]; j>0; j--)
			cout << i << " ";
	}
	for (int i=0; i<=N; i+=2) //从低到高输出偶数 
	{
		for (int j=T[i]; j>0; j--)
			cout << i << " ";
	}
	
	return 0;
}


