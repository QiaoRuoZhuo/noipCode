/*
	Name: 冒泡排序练习3
	Copyright: 
	Author: 
	Date: 04\09\18 10:40
	Description:
	有如下代码段：
	int i, j, s = 0;
	for (i=1; i<=6; i++)
	{
		j = 7;
		while (j > i)
		{
			if (A[j] > A[j-1])
			{
				A[j] = A[j] + A[j-1];
				A[j-1] = A[j] - A[j-1];
				A[j] = A[j] - A[j-1];
			}
			j--;
		}
	}
	for (i=3; i<=6; i++)
		s += A[i];
	 数组元素A[1]到A[7]的值依次为{8,2,3,7,10,6,5}，
	经过该程序段加工后，变量s的值为( A  )
	A 21   B 26    C 41    D 18
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 8;
int A[M] = {0,8,2,3,7,10,6,5};

int main() 
{
	int i, j, s = 0;
	for (i=1; i<=6; i++)
	{
		j = 7;
		while (j > i)
		{
			if (A[j] > A[j-1])
			{
				A[j] = A[j] + A[j-1];
				A[j-1] = A[j] - A[j-1];
				A[j] = A[j] - A[j-1];
			}
			j--;
		}
	}
	for (i=3; i<=6; i++)
		s += A[i];
	
	for (int i=0; i<M; i++)
		cout << A[i] << " ";
	cout << endl;
	cout << s << endl;
	
	return 0;	
} 
