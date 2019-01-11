/*
	Name: 使用选择排序分别对奇数和偶数排序 
	Copyhigh: 
	Author: 
	Date: 30-08-18 16:26
	Description: 有一组正整数，要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后。 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 30;
int A[M];

void Fun(int low, int high);//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 39 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(0, n-1);
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int low, int high)//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
{
	int i, k, m;
	
	while (low <= high)
	{
		if (A[low] % 2 == 1) //是奇数则把最小值交换到左端
		{
			for (m=low,k=low+1; k<=high; k++) 
			{
				if (A[k] % 2 == 1 && A[k] < A[m])
					m = k;
			}
			if (m != low)//奇数递增 
				swap(A[m], A[low]);
			low++;
	    } 
	    else  //是偶数则把最大值交换到右端
	    {
			for (m=low,k=low+1; k<=high; k++) 
			{
				if (A[k] % 2 == 0 && A[k] > A[m])
					m = k;
			}
			swap(A[m], A[high]);
			high--; //偶数递减 
	    } 
	}
}
