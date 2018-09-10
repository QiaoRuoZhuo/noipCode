/*
	Name:连续非递减序列的最大步长 
	Copyright: 
	Author: 
	Date: 04\09\18 10:01
	Description: 在数组A中，计算连续非递减序列的最大步长，所谓步长是指连续非递减序列中始末位置元素的差值。
	说明：
	要求1：输出出其中最大步长。 
	要求2：并输出第一个满足条件的该连续非递减序列。 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 20;
int A[M];

int Fun_1(int n);//返回连续非递减序列的最大步长
void Fun_2(int n);//输出该连续非递减序列
int Fun_3(int n);//返回连续非递减序列的最大步长
void Fun_4(int n);//输出该连续非递减序列

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 69 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun_1(n) << endl;
	Fun_2(n);
	cout << Fun_3(n) << endl;
	Fun_4(n);
	
	return 0;	
} 

int Fun_1(int n)//返回连续非递减序列的最大步长
{
    int msub = 0, left = 0;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
		    if (A[i-1]-A[left] > msub)  
	   	   	    msub = A[i-1]-A[left];
		    left = i;
		}
    }
    //单独处理最后一个元素
	if (A[n-1] > A[n-2] && A[n-1]-A[left] > msub)  
		msub = A[n-1]-A[left];
	return msub;
}

void Fun_2(int n)//输出该连续非递减序列
{
    int left = 0, mleft = 0, mright = 0;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
		    if (A[i-1]-A[left] > A[mright]-A[mleft])  
   		    {
	   	   	    mleft = left;
	   	   	    mright = i - 1;
		    }
		    left = i;
		}
    }
    //单独处理最后一个元素
	if (A[n-1] > A[n-2] && A[n-1]-A[left] > A[mright]-A[mleft])  
	{
 	    mleft = left;
	    mright = n - 1;
    }
    for (int i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}

int Fun_3(int n)//返回连续非递减序列的最大步长
{
    int msub = 0, left = 0;
	
    for (int i=1; i<n; i++)
    { 
        while (i < n && A[i] > A[i-1])
        	i++;
		if (A[i-1]-A[left] > msub)  
  		    msub = A[i-1]-A[left];
		left = i;
    }
    
    return msub;  
}

void Fun_4(int n)//输出该连续非递减序列
{
    int left = 0, mleft = 0, mright = 0;
    int m = 0, t = 1, i = 1;
	
    for (int i=1; i<n; i++)
    { 
        while (i < n && A[i] > A[i-1])
        	i++;
		if (A[i-1]-A[left] > A[mright]-A[mleft])  
  		{
		    mleft = left;
		    mright = i - 1;
		}
		left = i;
    }
    
    for (i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}

