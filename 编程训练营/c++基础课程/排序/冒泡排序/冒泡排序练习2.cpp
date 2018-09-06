/*
	Name: 冒泡排序练习2
	Copyright: 
	Author: 
	Date: 04\09\18 10:40
	Description:
	有如下代码段：
	for (int i=1; i<=9; i++)
	{
		for (int j=10; j>=i+2; j--)
		{
			if (A[j] < A[j-2])
				swap(A[j], A[j-2]);
		}
	}
	 数组元素A[1]到A[10]的值依次为{10,9,8,7,6,5,4,3,2,1}，
	经过该程序段加工后，数组元素A[8]的值为( A  )
	A 7   B 8    C 9    D 10
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 11;
int A[M] = {0,10,9,8,7,6,5,4,3,2,1};

int main() 
{
	for (int i=1; i<=9; i++)
	{
		for (int j=10; j>=i+2; j--)
		{
			if (A[j] < A[j-2])
				swap(A[j], A[j-2]);
		}
	}
	for (int i=0; i<M; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 
