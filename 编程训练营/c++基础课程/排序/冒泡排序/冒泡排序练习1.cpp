/*
	Name: 冒泡排序练习1 
	Copyright: 
	Author: 
	Date: 04\09\18 10:40
	Description: 数组元素A[1]到A[6]的值依次为{52,6,39,47,15,21}，
	经过该程序段加工后，数组元素A[1]到A[6]的值依次为多少？ 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M] = {0,52,6,39,47,15,21};

int main() 
{
	for (int i=1; i<=2; i++)
	{
		for (int j=1; j<=6-i; j++)
		{
			if (A[j] > A[j+1])
				swap(A[j], A[j+1]);
		}
	}
	for (int i=0; i<M; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 
