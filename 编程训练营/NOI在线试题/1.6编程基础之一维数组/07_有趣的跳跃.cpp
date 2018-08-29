/*
	Name: 07_有趣的跳跃
	Copyright: 
	Author: 
	Date: 15-08-17 08:19
	Description: 07_有趣的跳跃
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
一个长度为n（n>0）的序列中存在“有趣的跳跃”当前仅当相邻元素的差的绝对值经过排序后正好是从1到(n-1)。
例如，1 4 2 3存在“有趣的跳跃”，因为差的绝对值分别为3,2,1。当然，任何只包含单个元素的序列一定存在“有趣的跳跃”。
你需要写一个程序判定给定序列是否存在“有趣的跳跃”。

输入
一行，第一个数是n（0 < n < 3000），为序列长度，接下来有n个整数，依次为序列中各元素，各元素的绝对值均不超过1,000,000,000。
输出
一行，若该序列存在“有趣的跳跃”，输出"Jolly"，否则输出"Not jolly"。
样例输入
4 1 4 2 3
样例输出
Jolly

算法分析： 类似桶排序思想 
*/
#include <iostream>

using namespace std;

const int M = 3000;

bool Jolly(int A[], int n);

int main() 
{
	int A[M] = {0};
	int n;
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	if (Jolly(A, n))
		cout << "Jolly" << endl;
	else
		cout << "Not jolly" << endl;
	
	return 0;	
} 

bool Jolly(int A[], int n)
{
	if (n == 1)
		return 1;
		
	int B[M] = {0};
	int s;
	//相邻元素的差的绝对值经过排序后正好是从1到(n-1)
	for (int i=1; i<n; i++)
	{
		s = (A[i]>A[i-1]) ? A[i]-A[i-1] : A[i-1]-A[i];
		if (s<n && B[s]==0)//类似桶排序 
			B[s] = 1;
		else
			return 0;
	}
	
	return 1;
}
