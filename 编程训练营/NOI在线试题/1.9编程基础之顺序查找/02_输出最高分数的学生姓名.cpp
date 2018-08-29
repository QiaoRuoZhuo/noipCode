/*
	Name: 02_输出最高分数的学生姓名
	Copyright: 
	Author: 
	Date: 15-08-17 21:00
	Description: 02_输出最高分数的学生姓名
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入学生的人数，然后再输入每位学生的分数和姓名，求获得最高分数的学生的姓名。

输入
第一行输入一个正整数N（N <= 100），表示学生人数。接着输入N行，每行格式如下：
分数 姓名
分数是一个非负整数，且小于等于100；
姓名为一个连续的字符串，中间没有空格，长度不超过20。
数据保证最高分只有一位同学。
输出
获得最高分数同学的姓名。
样例输入
5
87 lilei
99 hanmeimei
97 lily
96 lucy
77 jim
样例输出
hanmeimei
*/
#include <iostream>
#include <string>

using namespace std;

const int M = 100;
int A[M];
string B[M];

int main() 
{
	int n;
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
		cin >> B[i];
	}
	
	int p = 0;	
	for (int i=0; i<n; i++)
	{
		if (A[i] > A[p])
			p = i;
	}
	cout << B[p] << endl;
	
	return 0;	
} 
