/*
	Name: 删除某个区间内元素 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: 编写一个函数删除数组A中元素值在[x,y]区间的所有元素，
	并返回新的数组长度。 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

int Fun(int A[], int n, int x, int y); 

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%100 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	int n = Fun(A, MAX, 50, 70);
	
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

int Fun(int A[], int n, int x, int y)
{
	int k = 0;
	
	for (int i=0; i<n; i++)
	{
		if (A[i] >= x && A[i] <= y)
		   k++;
        else
	        A[i-k] = A[i]; //前移k个位置 
	}
	return n - k;
}
