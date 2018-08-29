/*
	Name: 10_大整数加法
	Copyright: 
	Author: 
	Date: 15-08-17 10:06
	Description:10_大整数加法
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
求两个不超过200位的非负整数的和。

输入
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。
输出
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
样例输入
22222222222222222222
33333333333333333333
样例输出
55555555555555555555 
*/
#include <iostream>
#include <string>

using namespace std;

const int M = 302;
int C[M];

int main() 
{
	string A, B;
	cin >> A >> B;
	
	int pA=A.length()-1, pB=B.length()-1, pC=0;
	while (pA>=0 && pB>=0)
	{
		C[pC++] += A[pA--] - '0' + B[pB--] - '0'; 
		if (C[pC-1] > 9) //进位 
		{
			C[pC-1] -= 10;
			C[pC] += 1;
		}
	}
	while (pA>=0)
	{
		C[pC++] += A[pA--] - '0';
		if (C[pC-1] > 9) //进位 
		{
			C[pC-1] -= 10;
			C[pC] += 1;
		}
	}
	while (pB>=0)
	{
		C[pC++] += B[pB--] - '0';
		if (C[pC-1] > 9) //进位 
		{
			C[pC-1] -= 10;
			C[pC] += 1;
		}
	}
	while (pC>=0 && C[pC]==0)//去掉多余前导0 
	{
		pC--;
	}
	if (pC < 0)//答案 为0
		cout << 0;
	while (pC>=0)
	{
		cout << C[pC--];
	}
	cout << endl;
	
	return 0;	
} 

