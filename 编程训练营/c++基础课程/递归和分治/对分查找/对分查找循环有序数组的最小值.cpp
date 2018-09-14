/*
	Name: 对分查找循环有序数组的最小值 
	Copyright: 
	Author: 
	Date: 12-09-18 21:09
	Description: 所谓循环有序数组是指把一个非递减数组分成左右两段，然后左右两段整体置换，
	得到一个循环有序数组，例如，原数组A[6]={1，2，3，4，5，6}，
	可以生成B[6]={1，2，3，4，5，6, 1，2},或者C[6]={5，6, 1，2，3，4}等循环有序数组。 
	算法思想：虽然目标是寻找最小值，但应该先确定最大值位置。
	若为循环有序数组，则最小值在最大值右侧；若为纯递增数组，则最小值在最左端。 
	*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M] = { 1,3,5,7,9,11,11,11,19,19};

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
	int minPos = low; //若为纯递增数组，即循环有序数组的右段长度为0，则返回minPos 
	int mid;
     
    //不断缩小搜索范围，最后只剩2个元素，
	//若为循环有序数组，最终low和high分别指向最大值和最小值
	//若为纯递增数组，最终low和high分别指向次大值和最大值
	while (low < high) //多于2个元素 
	{ 
	    if (low + 1 == high)//只剩2个元素
        {
        	if (A[low] <= A[high]) //是纯递增数组，则返回minPos
			   return minPos;
			else                   //否则A[high]为最小值 
				return high; 
		 } 
		mid = (low + high) / 2;
		if (A[mid] >= A[low]) //mid在最大值左侧，或等于最大值 
			low = mid;
		else   //mid在最大值右侧， 
			high = mid - 1;
	}
	
	return minPos; //只有1个元素 
}
