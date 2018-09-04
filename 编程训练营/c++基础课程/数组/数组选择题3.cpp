/*
	Name: 数组选择题3
	Copyright: 
	Author: 
	Date: 04\09\18 15:49
	Description: 
	有如下代码段：
	int A[6] = {0};
	int s = 0;  
	for (int i=2; i<=5; i++)
	{
		for (int j=i; j<=5; j++)
		{
			if (j % i == 0)
				A[j] = 1 - A[j];
		}
	}
	for (int i=1; i<=5; i++)
		if (A[i] == 1)
			s += i;
	cout << s;
	执行上述代码段后，程序输出（ A  ）
	A 10   B 14   C 15   D 12 
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	int A[6] = {0};
	int s = 0;  
	for (int i=2; i<=5; i++)
	{
		for (int j=i; j<=5; j++)
		{
			if (j % i == 0)
				A[j] = 1 - A[j];
		}
	}
	for (int i=1; i<=5; i++)
		if (A[i] == 1)
			s += i;
	cout << s;
	
	return 0;	
} 
