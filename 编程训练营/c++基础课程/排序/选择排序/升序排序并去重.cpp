/*
	Name: 升序排序并去重 
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: 编写函数对数组A进行升序排序，并去掉重复的元素，返回新数组的长度。
	将下列代码段中的语句补充完整：
int SelectSort2(int n)
{
	int i = 0, j, k, r = n - 1;
	while (i < r)
	{
		k =  //语句1 
		for (j=r; j>i; j--)
		{
			if (A[j] == A[i])
			{
				A[j] = //语句2 
				if (k == r)
				   k = //语句3 
	            r--;
			}   
		    else if (A[k] > A[j])
                k = //语句4
		}
		if (k != i)
		   swap(A[i], A[k]);
        else  
        	//语句5
	}
	return //语句6
} 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

int SelectSort1(int n); 
int SelectSort2(int n); 
int SelectSort3(int n); 

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%5 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << SelectSort3(MAX) << endl;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

int SelectSort1(int n)
{
	int i, j, k, r = n - 1;
	for (i=0; i<r; i++)
	{
		k = i;
		for (j=i+1; j<=r; j++)
		{
			if (A[j] == A[k])
    	        A[j--] = A[r--];   
		    else if (A[k] > A[j])
                k = j;
		}
		if (k != i)
		   swap(A[i], A[k]);
	}
	return r + 1;
}

int SelectSort2(int n)
{
	int i = 0, j, k, r = n - 1;
	while (i < r)
	{
		k = i;
		for (j=r; j>i; j--)
		{
			if (A[j] == A[i])
			{
				A[j] = A[r];   
				if (k == r)
				   k = j;
	            r--;
			}   
		    else if (A[k] > A[j])
                k = j;
		}
		if (k != i)
		   swap(A[i], A[k]);
        else  //注意：只有未交换时才前进，否则可能仍存在与A[k]等值的最小元素 
        	i++;
	}
	return r + 1;
}

int SelectSort3(int n)
{
	int i = 0, j, k, r = n - 1;
	while (i < r)
	{
		k = i;
		for (j=i+1; j<=r; j++)
		{
			if (A[j] == A[i])
				A[j--] = A[r--]; 
		    else if (A[k] > A[j])
                k = j;
		}
		if (k != i)
		   swap(A[i], A[k]);
        else  
        	i++;
	}
	return r + 1;
}
