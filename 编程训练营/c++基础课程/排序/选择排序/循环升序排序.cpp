/*
	Name: 循环升序排序
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: 循环排序。
任意生成10个[1,100]之间的整数，编程实现将这10个数进行循环升序排序，
即首尾相连后是一个升序序列。要求第一个最小值位置不变，然后依次进行排列。
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 11;
int A[MAX], B[MAX];

void SelectCircleSort(int n);
void SelectCircleSort2(int n);

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%9 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	SelectCircleSort2(MAX);
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void SelectCircleSort(int n) //第一个最小值位置不变 
{
	int i, j, k, p=0;
	for (i=1; i<n; i++) //查找最小值下标 
	{
		if (A[p] > A[i])
		   p = i;
	}
	B[p] = 1;
	p = (p == 0) ? n-1 : p-1; //获取最大值下标 
 	
	for (i=1; i<n; i++) //对n-1个元素按照递减序选择排序 
	{
		k = p;
		for (j=0; j<n; j++)
		{
			if (B[j] == 0 && A[j] > A[k]) //更新最大值下标 
	    	    k = j;
		}
		if (k != p)
		   swap(A[k], A[p]);
        B[p] = 1;
        p = (p == 0) ? n-1 : p-1; //更新新的最大值下标 
	}
}

void SelectCircleSort2(int n) //第一个最大值位置不变 
{
	int i, j, k, p=0;
	for (i=1; i<n; i++) //查找最大值下标 
	{
		if (A[p] < A[i])
		   p = i;
	}
	B[p] = 1;
	p = (p == n-1) ? 0 : p+1; //获取最小值下标 
 	
	for (i=1; i<n; i++) //对n-1个元素按照递增序选择排序 
	{
		k = p;
		for (j=0; j<n; j++)
		{
			if (B[j] == 0 && A[j] < A[k]) //更新最小值下标 
	    	    k = j;
		}
		if (k != p)
		   swap(A[k], A[p]);
        B[p] = 1;
        p = (p == n-1) ? 0 : p+1; //更新新的最小值下标 
	}
}


