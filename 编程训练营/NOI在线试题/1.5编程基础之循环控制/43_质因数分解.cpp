/*
	Name:  43_质因数分解
	Copyright: 
	Author: 
	Date: 02-07-17 13:36
	Description: 43_质因数分解
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知正整数 n 是两个不同的质数的乘积，试求出较大的那个质数。

输入
输入只有一行，包含一个正整数 n。

对于60%的数据，6 ≤ n ≤ 1000。
对于100%的数据，6 ≤ n ≤ 2*10^9。
输出
输出只有一行，包含一个正整数 p，即较大的那个质数。
样例输入
21
样例输出
7
*/
#include<iostream>
#include<cmath>

using namespace std;

bool IsPrim(int n);

int main()
{
    int n, p;
    
    cin >> n;
    
    for (p=floor(sqrt(n)); p>1; p--)
    {
	 	if (n % p == 0 && IsPrim(p) && IsPrim(n/p))
	 	{
            cout << n / p;
            break;
	    }
	}
			  
    return 0;
}

bool IsPrim(int n)
{
    for (int i=floor(sqrt(n)); i>1; i--)
    {
	 	if (n % i == 0)
	 	   return false;
    }
    return true;
}
