/*
	Name: 数组中所有大于key的元素的最小值 
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

int Fun(const int A[], int n, int key);//数组中所有大于key的元素的最小值

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun(A, n, 15) << endl;
	
	return 0;	
} 

int Fun(const int A[], int n, int key)//数组中所有大于key的元素的最小值
{
	bool flag = false; //是否已找到满足条件的元素 
	int m = key;
	for (int i=0; i<n; i++)
	{
		if (A[i] > key)
		{
			if (!flag || A[i] < m)
			{
				flag = true;
				m = A[i];
			}
		}
	}
	return m;
}
