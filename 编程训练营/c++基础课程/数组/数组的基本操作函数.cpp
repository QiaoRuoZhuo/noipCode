/*
	Name: 数组的基本操作函数 
	Copyright: 
	Author: 
	Date: 04\09\18 15:24
	Description: 
*/
#include <iostream>
#include <cstdlib>

using namespace std;

//////////////////第1节（基本操作） 
//输出数组A的所有元素（元素间用空格隔开）
void PrintArray(const int A[], int n);
//输出数组A中区域[low,high]的元素（元素间用空格隔开）
void PrintArray(const int A[], int low, int high);
//将数组A中区域[low,high]的元素复制到数组B，并返回数组B的长度 
int CopyArray(const int A[], int B[], int low, int high);
//生成n个随机数为数组A赋值 
void CreateArray(int A[], int n);
//从键盘读入n个数为数组A赋值 
void CreateArray(int A[], int n);
//将数组A中值为x的元素改为y 
void ChangeValue(int A[], int n, int x, int y);
//统计数组A中奇数的数量 
int OddNumber(const int A[], int n);
//将数组A中的奇数存储到数组B，并返回数组B的长度 
int OddNumerArray(const int A[], int B[], int n);
//在数组A中查询是否存在值为x的元素，若存在返回第一个值为x的元素的下标，否则返回-1 
int Find(const int A[], int n, int x);
//统计数组A中值为x的元素的数量 
int NumOfValue(const int A[], int n, int x);

int main()
{
	const int MAX = 20;
	int A[MAX] = {0};
	
	for (int i=0; i<MAX; i++)  
	{
		A[i] = i * 5;
	}
	
	PrintArray(A, MAX);
	
    return 0;
}

//输出数组A的所有元素（元素间用空格隔开）
void PrintArray(const int A[], int n)
{
	for (int i=0; i<n; i++)  
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
