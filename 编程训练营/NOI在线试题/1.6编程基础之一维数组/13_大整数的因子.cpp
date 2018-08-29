/*
	Name: 13_大整数的因子
	Copyright: 
	Author: 
	Date: 15-08-17 11:01
	Description: 13_大整数的因子
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知正整数k满足2<=k<=9，现给出长度最大为30位的十进制非负整数c，求所有能整除c的k。

输入
一个非负整数c，c的位数<=30。
输出
若存在满足 c%k == 0 的k，从小到大输出所有这样的k，相邻两个数之间用单个空格隔开；若没有这样的k，则输出"none"。
样例输入
30
样例输出
2 3 5 6 

算法分析：因为数据量很小，不需要各种优化，直接判断即可。 
*/
#include <iostream>
#include <string>

using namespace std;

const int M = 32;

int main() 
{
	string C;
	cin >> C;
	
	int n = C.length()-1;
	int A[M] = {0};
	int B[M] = {0};
	
	for (int i=0; i<=n; i++)
		A[i] = C[i] - '0';
	
	int s = 0;
	for(int k=2; k<=9; k++)
	{
		for (int i=0; i<=n; i++)
			B[i] = A[i];
		for (int i=0; i<n; i++)//核心算法 
			B[i+1] += (B[i] % k) * 10;
			
		if (B[n] % k == 0)	
		{
			s++;
			cout << k << " ";
		}
	}
	if (s == 0)
		cout << "none";
	
	return 0;	
} 
