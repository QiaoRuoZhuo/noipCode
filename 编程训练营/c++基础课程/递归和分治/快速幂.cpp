/*
	Name: 快速幂 
	Copyright: 
	Author: 
	Date: 16-10-17 13:24
	Description: 
使用二分法求x^n mod m 的值。
输入：3个不超过10000的正整数x,p,m
输出：x^n mod m 的值
*/

#include<iostream>

using namespace std;

int FunPow(int x, int p, int m);

int main() 
{
 	int x, p, m, result;
 	
 	cin >> x >> p >> m;
 	cout << FunPow(x, p, m)<< endl;
 	
 	result = 1;
 	while (p > 0)
 	{
		if (p % 2 == 1)
		{
			result = result * x % m;
		}
		p /= 2;
		x = x * x % m;
	}
	cout << result<< endl;
	
    return 0;
}

int FunPow(int x, int p, int m)
{
	if (p == 0)
		return 1;
	if (p == 1)
		return x % m;
	int result = FunPow(x, p/2, m);
	result = result * result % m;
	if (p % 2 == 1)
		result = result * x % m;
	
	return result;
}
