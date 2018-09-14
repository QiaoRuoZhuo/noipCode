/*
	Name: 对分查找循环有序数组 
	Copyright: 
	Author: 
	Date: 12-09-18 21:09
	Description: 所谓循环有序数组是指把一个非递减数组分成左右两段，然后左右两段整体置换，
	得到一个循环有序数组，例如，原数组A[6]={1，2，3，4，5，6}，
	可以生成B[6]={1，2，3，4，5，6, 1，2},或者C[6]={5，6, 1，2，3，4}等循环有序数组。 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M] = {11,13,15,17,19,1,3,5,7,9};

int Fun(int low, int high, int key);//对分查找循环有序数组 

int main() 
{
	int n  = M;
	
	for (int i=0; i<n; i++)
		cout << i << ": " << A[i] << " ";
	cout << endl;
	for (int k=0; k<=20; k++)
		cout << k << ": " << Fun(0,n-1,k) << " ";
	cout << endl;
	return 0;	
} 

int Fun(int low, int high, int key)//对分查找循环有序数组 
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == key)
			return mid;
		if (A[mid] >= A[low]) //mid在谷点左侧 
		{
			if (A[mid] >= key && A[low] <= key) //key在mid左侧 
				high = mid - 1;
			else                         //key在mid右侧 
				low = mid + 1;
		}
		else   //mid在谷点右侧 
		{
			if (A[mid] <= key && A[high] >= key) //key在mid右侧 
				low = mid + 1;
			else                         //key在mid左侧 
				high = mid - 1;
		}
	}
	return -1;
}
