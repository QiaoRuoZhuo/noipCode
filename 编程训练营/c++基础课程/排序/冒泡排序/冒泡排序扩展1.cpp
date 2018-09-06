/*
	Name: 冒泡排序扩展1 
	Copyright: 
	Author: 
	Date: 06\09\18 15:23
	Description: 
	对数组A中值不小于key的元素进行递增排序，同时不改变小于key的元素的位置。
	例如，A[]={34,56,21,45,13,31}，若key=30，则排序后A[]={31,34,21,45,13,56} 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M];

void Fun(int n, int key);//对数组A中值不小于key的元素进行递增排序

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(n, 10);
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int n, int key)//对数组A中值不小于key的元素进行递增排序
{
	int P[M] = {0};
	int m = 0;
	
	for (int i=0; i<n; i++) //记录满足条件的元素 
	{
		if (A[i] >= key)
		   P[m++] = i; //语句1 
	}
	for (int i=m-1; i>0; i--)////语句2 
	{
		for (int j=0; j<i; j++)
		{
			if (A[P[j]] > A[P[j+1]]) //语句3
			   swap(A[P[j]],A[P[j+1]]);
		}
	}
}



