/*
	Name: 折半查找 
	Copyright: 
	Author: 
	Date: 08-01-18 09:19
	Description:
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 10;
int A[MAX];

int BinarySearch(int x, int low, int high) //折半查找值为x的元素的下标，找不到则返回-1 
{
	for (int mid=(low+high)/2; low<=high; mid=(low+high)/2)
	{
		if (x == A[mid])
			return mid;
		else if (x < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int DGBinarySearch(int x, int low, int high) //折半查找值为x的元素的下标，找不到则返回-1 
{
	if (low > high)
		return -1;
	int mid = (low+high)/2;
	if (x == A[mid])
		return mid;
	else if (x < A[mid])
		return DGBinarySearch(x, low, mid-1);
	else
		return DGBinarySearch(x, mid+1, high);
}

int main() 
{
	for(int i=0; i<MAX; i++)
		A[i] = i+1;
	
	cout << BinarySearch(7, 0, MAX-1) << endl;
	cout << DGBinarySearch(7, 0, MAX-1) << endl;
		
    return 0;
}
