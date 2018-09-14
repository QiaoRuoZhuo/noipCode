/*
	Name: 折半插入排序 
	Copyright: 
	Author: 
	Date: 08-01-18 14:23
	Description:
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void InsertSort(int A[], int n);//用插入排序法对数组A进行排序（非递减序列） 
void InsertSort_1(int A[], int n);//插入排序改进算法：二分插入 
int BinaryInsert(int x, int low, int high); //迭代算法：折半查找值为x的元素的插入位置 
int DGBinaryInsert(int x, int low, int high); //递归算法：折半查找值为x的元素的插入位置 

const int MAX = 10;
int A[MAX];

int main() 
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%10 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	InsertSort(A, MAX);
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
		
    return 0;
}

void InsertSort(int A[], int n)//用插入排序法对数组A进行排序（非递减序列） 
{
	int p; //用来存储插入位置的临时变量 
	int temp; //用来交换数组元素值的临时变量
	for (int i=1; i<n; i++) //A[0..i-1]为已排序部分，将A[i]插入到A[0..i-1]中 
    {
		temp = A[i];
    	for (p=i; p>0; p--)//内层循环逆序搜索A[0..i-1]，移动元素以腾出插入位置 
        {
            if (A[p-1] > temp)
	            A[p] = A[p-1];
	        else
	        	break;
        }
        A[p] = temp;
	}
}

int BinaryInsert(int x, int low, int high) //迭代算法：折半查找值为x的元素的插入位置 
{
	int mid;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (A[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int DGBinaryInsert(int x, int low, int high) //递归算法：折半查找值为x的元素的插入位置 
{
	if (low > high)
		return low;
	
	int mid = (low+high)/2;
	if (A[mid] > x)
		return DGBinaryInsert(x, low, mid-1);
	else
		return DGBinaryInsert(x, mid+1, high);
}

void InsertSort_1(int A[], int n)//插入排序改进算法：二分插入 
{
	int mid, pos;
	int temp; //用来存储待插入元素的临时变量 
	for (int i=1; i<n; i++) //A[0..i-1]为已排序部分，将A[i]插入到A[0..i-1]中 
    {
		temp = A[i];
		pos = BinaryInsert(temp, 0, i-1); //二分查找插入位置
    	for (int j=i; j>pos; j--)//移动元素以腾出插入位置 
	        A[j] = A[j-1];
        A[pos] = temp;
	}
}

/*
插入排序在对几乎已经排好序的数据操作时，效率高，几乎可以达到线性排序的效率，但进行插入操作时，每次只能将数据移动一位，难免出现大量重复移动，
如果能将元素尽可能快的移动到它“该去”的地方，将大大减少重复移动的次数，提高效率。
希尔排序是把全部元素分组排序，将所有距离为步长gap的元素放在同一个组中，通过“跳跃式移动”的方法，能让元素每次移动一大步，
即步长gap>1，大大提高了移动的效率。一趟排序下来，虽然同组的元素没有挨在一起，各组元素相互隔开，但是由于每一组都已经各自排好序了，
所以整个序列还是“基本有序”的。
然后再取越来越小的步长进行排序，直到步长gap=1时，就是普通的插入排序，但是到了这步，整个序列是“基本有序”了，直接插入排序也能高效完成。
*/
void InsertSort_2(int A[], int n)//插入排序改进算法2：希尔排序 
{
	int p; //用来存储插入位置的临时变量 
	int temp; //用来交换数组元素值的临时变量
   
    for (int gap=n/2; gap>0; gap/=2)//元素跳跃的步长不断减少，步长为1时即为直接插入排序
	{
		for(int i=gap; i<n; i++)//将A[i]插入到A[0..i-1]中 
		{
			temp = A[i];
			for (p=i; p>=gap; p-=gap)//向后跳跃移动元素以腾出插入位置，跳跃距离为gap
	        {
	            if (A[p-gap] > temp)
		            A[p] = A[p-gap];
		        else
		        	break;
	        }
	        A[p] = temp;
		}
	}
}
