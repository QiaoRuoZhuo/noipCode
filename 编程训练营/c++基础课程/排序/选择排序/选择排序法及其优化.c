/*
	Name: 选择排序法及其优化 
	Copyright: 
	Author: 巧若拙 
	Date: 09/09/14 18:11
	Description: 
	选择排序基础算法是每一趟从待排序的数据元素中选出最小（或最大）的一个元素，顺序放在已排好序的数列的最后，直到全部待排序的数据元素排完。 
	改进版本：为了减少比较的次数，可采用每一趟扫描时，同时选出最大和最小值，这样逐步缩小扫描范围，直到只剩下一个元素。 
	改进版本中有一点要注意：如果最大值在最左边，肯定要被移走，此时要转移到相应的新位置。 
*/
#include<stdio.h>
#include<stdlib.h> 

#define MAX 10

void SelectSort_1(int vec[], int n);
void SelectSort_2(int vec[], int n);
void DisPlay(int vec[], int n);

int main(void)
{
	int vec[MAX] = {1,2,8,3,3,5,9,7,7,4};
	int n = MAX;
	
	DisPlay(vec, n);
	SelectSort_2(vec, n);
	DisPlay(vec, n);
	
	return 0;
}

void DisPlay(int vec[], int n)
{
	int i;
	
	printf("\n共有%d个元素：", n);
	
	for (i=0; i<n; i++)
	{
		printf("%d, ", vec[i]);
	}
	printf("\n");
}

void SelectSort_1(int vec[], int n) //选择排序基础算法 
{
	int i, j, min;
	int temp;
	
	for (i=0; i<n-1; i++)
	{
		min = i;
		for (j=i+1; j<n; j++)
		{
			if (vec[j] < vec[min])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			temp = vec[i];
			vec[i] = vec[min];
			vec[min] = temp;
		}	
	}
}

void SelectSort_2(int vec[], int n) //选择排序改进算法：同时选出最大和最小值 
{
	int i, min, max, left, right;
	int temp;
	
	for (left=0, right=n-1; left<right; left++, right--)
	{
		min = left;
		max = right;
		for (i=left; i<=right; i++)
		{
			if (vec[i] < vec[min])
			{
				min = i;
			}
			else if (vec[i] > vec[max])
			{
				max = i;
			}
		}
		
		if (min != left)
		{
			temp = vec[left];
			vec[left] = vec[min];
			vec[min] = temp;
			
			if (max == left) //如果最大值在最左边，肯定要被移走，此时要转移到相应的新位置 
			{
				max = min;
			}
		}	
		
		if (max != right)
		{
			temp = vec[right];
			vec[right] = vec[max];
			vec[max] = temp;
		}
	}
}
