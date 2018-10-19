/*
	Name: 分别对奇数和偶数排序 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: 有一组正整数，要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后。 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 30;
int A[M];

int OddNum(int n);//要求把奇数和偶数分成两半，其中奇数在前，偶数在后，返回奇数的数量
void Fun(int low, int high);//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
void Fun2(int low, int high);//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 39 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
//	int len = OddNum(n);//要求把奇数和偶数分成两半，其中奇数在前，偶数在后，返回奇数的数量
//	Fun(0, len-1);
//	Fun(len, n);
	
	Fun2(0, n-1);
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int low, int high)//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
{
    int lastSwapPos;//最后一次发生交换操作的位置
    int temp; //用来交换数组元素值的临时变量
    int i;

    while (low < high)
    {
        lastSwapPos = low;//假设最后一次交换位置为左边界（即无交换） 
        for (i=low; i<high; i++)
        {
            if (A[i] > A[i+1])
            {
                temp = A[i];
                A[i] =A[i+1];
                A[i+1] =temp;
                lastSwapPos = i;//该处发生了交换操作，更新需要排序的成员范围 
            }
        }

        high = lastSwapPos;//设置新的右边界
        for (i=high; i>low; i--)
        {
            if (A[i] < A[i-1])
            {
                temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp;
                lastSwapPos = i;//该处发生了交换操作，更新需要排序的成员范围 
            }
        }
        low = lastSwapPos;//设置新的左边界 
    }
}

int OddNum(int n)//要求把奇数和偶数分成两半，其中奇数在前，偶数在后，返回奇数的数量
{
    int i = 0, j = n - 1;
	
    while (i < j)
    { 
        while (i < j && A[i] % 2 == 1)
			i++;
		while (i < j && A[j] % 2 == 0)
			j--;
		if (i < j)
			swap(A[i++], A[j--]);
    }
    if (A[j] % 2 == 0)
    	j--;
    return j+1;
}

void Fun2(int low, int high)//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
{
    for (int i=low; i<high; i++)
    {
        for (int j=high; j>i; j--)
        {
            if ((A[j]%2 == A[j-1]%2 && A[j] < A[j-1]) || A[j]%2 > A[j-1]%2)
            {
                swap(A[j], A[j-1]);
            }
        }
    }
}
