/*
	Name: 查找数组中的逆序对
	Copyright: 
	Author: 
	Date: 10-01-18 13:57
	Description: 题目描述：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。
输入：
每个测试案例包括两行：
第一行包含一个整数n，表示数组中的元素个数。其中1 ≤n ≤40000。
第二行包含n个整数，每个数组均为int类型。
输出：
对应每个测试案例，输出一个整数，表示数组中的逆序对的总数。
样例输入：
4
7 5 6 4
样例输出：
5

算法分析：
算法一：逐个统计，时间复杂度是N^2
算法二：利用归并排序的思想，在合并过程中统计逆序对的个数。时间复杂度是 N*Log(N)。 
*/

#include<iostream>

using namespace std;

const int MAX = 40001;
int A[MAX], TA[MAX];
int sum = 0;

int ReverseNum_1(int n); //逐个统计求逆序对 
int ReverseNum_2(int n); //归并排序求逆序对 
void MergeSort(int low, int high);//归并排序算法（递归） 
void MergeSort_2(int low, int high);//归并排序算法（非递归） 
void Merge_1(int low, int mid, int high);//合并序列，同时统计逆序对数量 
void Merge_2(int low, int mid, int high);//先复制再合并，可以使代码更简洁 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
	}
	
	cout << ReverseNum_2(n);
		
    return 0;
}

int ReverseNum_1(int n)
{
	int s = 0;
	for (int i=1; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			s += A[j] > A[i];
		}
	}
	return s;
}

int ReverseNum_2(int n)
{
	MergeSort(0, n-1);
	return sum;
}

void MergeSort(int low, int high)
{
	if (low == high)
		return;
		
	int mid = (low + high) / 2;
	MergeSort(low, mid);
	MergeSort(mid+1, high);
	Merge_2(low, mid, high);
}

void MergeSort_2(int low, int high)
{
	int i, L1, L2=1, n=high-low+1;
	for (L1=L2; L2<=n; L1=L2)//外部 for 循环的循环体每执行一次，都使L1和L2加倍
	{
		L2 = L1 * 2;
		for (i=0; i+L2<=n; i+=L2)
		{
			Merge_2(i, i+L1-1, i+L2-1);
		}
		//若剩下的元素数量介于L1和L2之间，说明这是两个数量不等的序列，对他们进行合并操作；
		//若剩下的元素数量不多于L1，说明这些元素属于同一个已排序的序列，无需合并。
		if (i+L1 < n)
			Merge_2(i, i+L1-1, n-1);
	}
}

void Merge_1(int low, int mid, int high)
{
	int i=low, j=mid+1, k=low;
	//将A[]中元素按非递减序归并入TA[] 
	while (i<=mid && j<=high)
	{
		if (A[i] <= A[j])
		{
			TA[k++] = A[i++];
		}	
		else
		{
			TA[k++] = A[j++];
			sum += mid - i + 1;//统计逆序对数量 
		}
	}
	//将A[]中剩余的元素复制到TA[] 
	while (i <= mid)
	{
		TA[k++] = A[i++];
	}
	while (j <= high)
	{
		TA[k++] = A[j++];
	}
	//将合并好的有序序列复制到A[] 
	for (i=low; i<=high; i++)
	{
		A[i] = TA[i];
	}
}

void Merge_2(int low, int mid, int high)
{
	int i, j, k;
	//将A[low..mid]中元素顺序复制到tempA[low..mid]
	for (i=low; i<=mid; i++) 
	{
		TA[i] = A[i];
	}
	//将A[mid+1..hig]中元素逆序序复制到tempA[mid+1..hig]
	for (i=mid+1,j=high; i<=high; i++,j--) 
	{
		TA[i] = A[j];
	}
	//将TA[]中元素按非递减序归并入A[] 
	for (k=i=low,j=high; k<=high; )//只需判断k是否越界（也可判断i<=j） 
	{
		if (TA[i] <= TA[j])
		{
			A[k++] = TA[i++];
		}	
		else
		{
			A[k++] = TA[j--];
			sum += mid - i + 1;//统计逆序对数量 
		}
	}
}
