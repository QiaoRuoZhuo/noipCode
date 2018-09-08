/*
	Name: 降序序列 
	Copyright: 
	Author: 
	Date: 04\09\18 10:01
	Description: 在一个数据序列中，如果出现连续降序的几个数，称为一个降序序列，该降序序列中数的个数称为序列长度。
	用随机函数产生n个数据的序列，
	要求1：查找出其中最长降序序列的长度
	要求2：并输出该最长降序序列。 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 20;
int A[M];

int Fun(int n);//返回最长降序序列的长度
void Fun_2(int n);//输出该最长降序序列
int Fun_3(int n);//返回最长降序序列的长度
void Fun_4(int n);//输出该最长降序序列

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i]=n-i;//A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun(n) << endl;
	Fun_2(n);
	cout << Fun_3(n) << endl;
	Fun_4(n);
	
	return 0;	
} 

int Fun(int n)//返回最长降序序列的长度
{
    int m = 0, t = 1;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
        	t++;
		}
		else
		{
			if (t > m)
				m = t;
			t = 1;
		}
    }
    return (t > m) ? t : m; //最长降序序列包含最后一个元素  
}

void Fun_2(int n)//输出该最长降序序列
{
    int left = 0, mleft = 0, mright = 0;
    int m = 0, t = 1;
	
    for (int i=1; i<n; i++)
    { 
        if (A[i] < A[i-1])
        {
        	t++;
		}
		else
		{
			if (t > m)
			{
				m = t;
				mleft = left;
				mright = i - 1;
			}
			t = 1;
			left = i;
		}
    }
    if (t > m) //最长降序序列包含最后一个元素 
	{
	    m = t;
	    mleft = left;
		mright = n - 1;
	}
    
    for (int i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}

int Fun_3(int n)//返回最长降序序列的长度
{
    int m = 0, t = 1, i = 1;
	
    while (i < n)
    { 
        while (i < n && A[i] < A[i-1])
        {
        	t++;
        	i++;
		}
		if (t > m)
			m = t;
		t = 1;
		i++;
    }
    
    return m;  
}

void Fun_4(int n)//输出该最长降序序列
{
    int left = 0, mleft = 0, mright = 0;
    int m = 0, t = 1, i = 1;
	
    while (i < n)
    { 
        while (i < n && A[i] < A[i-1])
        {
        	t++;
        	i++;
		}
		if (t > m)
		{
			m = t;
			mleft = left;
			mright = i - 1;
		}
		t = 1;
		left = i++;
    }
    
    for (i=mleft; i<=mright; i++)
		cout << A[i] << " ";
	cout << endl;
}
