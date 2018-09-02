/*
	Name: 开关灯问题 
	Copyright: 
	Author: 
	Date: 02-09-18 12:49
	Description: 有N个灯放在一排,全部处于关闭状态，从1到N依次顺序编号。
有N个人也从1到N依次编号。1号将灯全部打开, 2号将凡是2的倍数的灯关闭; 
3号则对所有3的倍数的灯进行操作......一直到第n个人为止。 
那么n个人操作结束后，有几盏灯是开着的？ 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

const int M = 40;
int A[M];

int Fun(int n);//返回经过n个人操作后，亮着的灯的数量 
int Fun2(int n);//返回经过n个人操作后，亮着的灯的数量 

int main() 
{
	int n  = M;
	cout << Fun(n) << endl;
	cout << Fun2(n) << endl;
	
	return 0;	
} 

int Fun(int n)//返回经过n个人操作后，亮着的灯的数量 
{
	int F[M] = {0};//0表示关，1表示开 
    for (int i=1; i<=n; i++)
    {
		for (int j=i; j<=n; j+=i)
		{
			F[j] = 1- F[j];
		}
	}
	int s = 0;
	for (int i=1; i<=n; i++)
    {
		if (F[i] == 1)
		{
			cout << i << " ";
			s++;
		}
	}
	cout << endl;
	return s;
}

int Fun2(int n)//返回经过n个人操作后，亮着的灯的数量 
{
	int s = 0;
	for (int i=1; i<=n; i++)
    {
		int q = sqrt(i);
		if (i == q*q)
		{
			cout << i << " ";
			s++;
		}
	}
	cout << endl;
	return s;
}
