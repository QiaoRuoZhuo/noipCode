/*
	Name: 13_整数去重
	Copyright: 
	Author: 
	Date: 16-08-17 15:22
	Description: 13_整数去重
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定含有n个整数的序列，要求对这个序列进行去重操作。所谓去重，是指对这个序列中每个重复出现的数，只保留该数第一次出现的位置，删除其余位置。
输入
输入包含两行：
第一行包含一个正整数n（1 <= n <= 20000），表示第二行序列中数字的个数；
第二行包含n个整数，整数之间以一个空格分开。每个整数大于等于10、小于等于100。
输出
输出只有一行，按照输入的顺序输出其中不重复的数字，整数之间用一个空格分开。
样例输入
5
10 12 93 12 75
样例输出
10 12 93 75
*/
#include <iostream>

using namespace std;

const int M = 20000;
int A[M];

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	for (int i=0; i<n; i++)
	{
		if (A[i] == 0)
			continue;
		 
		cout << A[i] << " "; //输出不重复的数 
		for (int j=i+1; j<n; j++)
		{
			if (A[j] == 0)
				continue;
			if (A[j] == A[i])//标记重复元素 
				A[j] = 0;
		}
	}
	return 0;	
} 
