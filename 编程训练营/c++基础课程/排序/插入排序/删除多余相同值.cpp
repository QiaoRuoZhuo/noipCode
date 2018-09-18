/*
	Name: 删除多余相同值 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: 已知数组A的元素值按非递减有序排列，编写一个函数删除多余相同元素，
	并返回新的数组长度。 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX] = {1,1,3,3,5,6,7,7,7,7};

int Fun(int A[], int n); 
int Fun2(int A[], int n);
int Fun3(int A[], int n);

int main()
{
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	int n = Fun3(A, MAX);
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

int Fun(int A[], int n)
{
	int i = 1, j;
	
	while (i < n)
	{
		if (A[i-1] != A[i])
		   i++;
        else
        {
        	for (j=i; j<n; j++)
        		A[j-1] = A[j];
       		n--;
		}
	}
	return n;
}


int Fun2(int A[], int n)
{
	int i, j, k, num;
	
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n && A[j]==A[i]; j++);
		num = j - i - 1; //与A[i]等值的元素个数 
		if (num > 0)
		{
			for (k=j; k<n; k++) //整块移动 
				A[k-num] = A[k];
			n -= num;
		}
	}
	return n;
}


int Fun3(int A[], int n)
{
	int k = 0;
	
	for (int i=1; i<n; i++)
	{
		if (A[i-1] == A[i])
		   k++;
        else
	        A[i-k] = A[i]; //前移k个位置 
	}
	return n - k;
}
