/*
	Name: 对分查找循环有序数组的最大值 
	Copyright: 
	Author: 
	Date: 12-09-18 21:09
	Description: 所谓循环有序数组是指把一个非递减数组分成左右两段，然后左右两段整体置换，
	得到一个循环有序数组，例如，原数组A[6]={1，2，3，4，5，6}，
	可以生成B[6]={1，2，3，4，5，6, 1，2},或者C[6]={5，6, 1，2，3，4}等循环有序数组。
	算法思想：不断缩小搜索范围，最后只剩2个元素，
	若为循环有序数组，最终low和high分别指向最大值和最小值；
	若为纯递增数组，最终low和high分别指向次大值和最大值。 
 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 5;
//int A[M] = { 1,3,5,7,9,11,11,11,19,19};
int A[M] = {11,19,21, 3,4};

int Fun(int low, int high);//对分查找循环有序数组的最大值下标 

int main() 
{
	int n  = M;
	
	for (int i=0; i<n; i++)
		cout << i << ": " << A[i] << " ";
	cout << endl;
	
	cout << A[Fun(0,n-1)] << endl;
	return 0;	
} 

int Fun(int low, int high)//对分查找循环有序数组的最大值下标 
{
	int maxPos = high; //若为纯递增数组，即循环有序数组的右段长度为0，则返回maxPos 
	int mid;
	
	while (low < high) //多于1个元素 
	{ 
        if (low + 1 == high)//只剩2个元素
        {
        	if (A[low] <= A[high]) //是纯递增数组，则返回minPos
			   return maxPos;
			else                   //否则A[low]为最大值 
				return low; 
		 } 
		mid = (low + high) / 2;
		if (A[mid] >= A[low]) //mid在最大值左侧，或等于最大值 
			low = mid;
		else   //mid在最大值右侧
			high = mid; //提问：为何不能写作high=mid-1？原因：考虑A[mid]为最大值的情形 
	}
	
	return maxPos; //只有一个元素 
}
