/*
	Name: 相邻元素差值最大值 
	Copyright: 
	Author: 
	Date: 04\09\18 15:49
	Description: 
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 20;
int A[M];

int Fun(const int A[], int n);//相邻元素差值最大值 

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun(A, n) << endl;
	
	return 0;	
} 

int Fun(const int A[], int n)//相邻元素差值最大值 
{
	int m = 0;
	for (int i=1; i<n; i++)
	{
		if (abs(A[i]-A[i-1]) > m)
			m = abs(A[i]-A[i-1]);
	}
	return m;
}
