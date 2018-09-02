/*
	Name: 选择排序变例之奇升偶降 
	Copyright: 
	Author: 
	Date: 21-08-18 16:37
	Description: 有一组正整数，要求对其中的奇数进行升序排序，对偶数进行降序排序，
	且排序后奇数在前，偶数在后。排序示例如下：
	排序前：64 58 52 95 39 67 60 71
	排序后：39 67 71 95 64 60 58 52 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

void SelectSort(int left, int right); 

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%10 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	SelectSort(0,MAX-1);
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void SelectSort(int left, int right)
{
	int k, m;
	
	while (left < right)
	{
		for (m=left,k=left+1; k<=right; k++)//找出最小值 
		{
			if (A[k] < A[m])
				m = k;
		}
		if (A[m]%2 == 1)//奇数递增 
		{
			swap(A[m], A[left]);
			left++;
		}
		else  //偶数递减 
		{
			swap(A[m], A[right]);
			right--;
		}
	}
}
