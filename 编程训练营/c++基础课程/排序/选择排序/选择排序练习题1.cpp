/*
	Name: 选择排序练习题1 
	Copyright: 
	Author: 
	Date: 09-09-18 22:18
	Description: 
	for (int i=1; i<=2; i++)
	{
		int k = i;
		for (int j=i+1; j<=5; j++)
		{
			if (A[k] < A[j])
				k = j;
		}
		if (k != i)
			swap(A[k], A[i]);
	}
经过该程序段“加工”后，数组元素 A[1]到 A[5]的值依次为"44,35,30,11,7"，则数组元素 A[1]到 A[5]的原始数据依次为（  D）
A.30,44,7,11,35   B.30,11,44,7,35   C.44,30,11,7,35   D.30,7,44,11,35
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	int A[6] = {0,30,7,44,11,35};
	 
	for (int i=1; i<=2; i++)
	{
		int k = i;
		for (int j=i+1; j<=5; j++)
		{
			if (A[k] < A[j])
				k = j;
		}
		if (k != i)
			swap(A[k], A[i]);
	}
	
	for (int i=1; i<=5; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 
