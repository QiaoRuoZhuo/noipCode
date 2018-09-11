/*
	Name: 左右升序排列 
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: 已知数组A有奇数个元素，编写函数对数组A进行左右升序排序，
所谓左右升序排列是指把最小值反正最中间，然后依次在最小值左右两侧排列第2和第3小元素。
例如，当数组A[7]={3,5,7,2,4,1,6}时，排序后A[7]={6,4,2,1,3,5,7} 。 
	
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 11;
int A[MAX];

void SelectSort1(int n);

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%19 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	SelectSort1(MAX);
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void SelectSort1(int n)
{
	int i, j, k, p1, p2;
	for (i=0,j=n-1; i<j; i++,j--)
	{
		p1 = j, p2 = i;//分别在最右端和最左端放置最大值和次大值 
		if (A[p1] < A[p2]) 
		   swap(A[p1], A[p2]);
		
		for (k=i+1; k<j; k++)
		{
			if (A[k] > A[p1]) //更新最大值和次大值下标 
    	    {
    	    	p2 = p1;
    	    	p1 = k;
    	    }
		    else if (A[k] > A[p2])//更新次大值下标 
                p2 = k;
		}
		if (j != p1)
		   swap(A[j], A[p1]);
        if (j == p2)
           p2 = p1;
        if (i != p2)
		   swap(A[i], A[p2]);
	}
}

