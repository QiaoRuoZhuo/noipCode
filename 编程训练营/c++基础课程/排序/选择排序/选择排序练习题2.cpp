/*
	Name: 选择排序练习题2
	Copyright: 
	Author: 
	Date: 09-09-18 22:18
	Description: 
	某学校举行校园歌手比赛，数组A存放歌手的得分，数组B存放名次。
	名次计算规则为：先对数组A中的元素按高到低的排序，分值最高为第1名，分值相同则名次相同。
	例如当A[6] = {80,70,70,70,60,60}，则B[6] = {1,2,2,2,5,5}。 
部分代码如下，请将语句1到语句5填写完整。 
for (int i=n-1; i>0; i--)
	{
		int k = i;
		for (int j=0; j<i; j++)
		{
			if ( ) //语句1 
				k = j;
		}
		if (k != i)
			swap( );//语句2 
	}
	
	B[0] =  ; //语句3
	for (int i=1; i<n; i++)
	{
		if (A[i] == A[i-1])
			B[i] =  ; //语句4
		else
			B[i] =  ; //语句5
	}
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	const int M = 20;
	int A[M] = {0}, B[M] = {0};
	int n = M;
	for (int i=0; i<n; i++)
		A[i] = rand()%9 + 1;
		
	for (int i=n-1; i>0; i--)
	{
		int k = i;
		for (int j=0; j<i; j++)
		{
			if (A[k] < A[j]) //语句1 
				k = j;
		}
		if (k != i)
			swap(A[k], A[i]);//语句2 
	}
	
	B[0] = 1; //语句3
	for (int i=1; i<n; i++)
	{
		if (A[i] == A[i-1])
			B[i] = B[i-1]; //语句4
		else
			B[i] = i + 1; //语句5
	}
	for (int i=0; i<n; i++)
		cout << A[i] << " " << B[i] << endl;
	
	
	return 0;	
} 
