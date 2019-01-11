/*
	Name: 使用插入排序分别对奇数和偶数排序 
	Copyhigh: 
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

void Fun(int low, int high);//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 39 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(0, n-1);
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void Fun(int low, int high)//要求分别对奇数和偶数进行升序排序，其中奇数在前，偶数在后
{
	int mid = low; //mid是第一个已排序偶数的下标 
    for (int i=low; i<=high; i++) //因为不知道第一个数的奇偶性，故从第1个元素开始
    {
    	int t = A[i];
    	int j = i - 1;
        if (A[i] % 2 == 1)
        {
        	while (j >= mid || (j >= low && A[j] > t))
        	{
        		A[j+1] = A[j];
        		j--;
			}
			A[j+1] = t;
			mid++;
		}
		else
		{
			while (j >= mid && A[j] > t)
        	{
        		A[j+1] = A[j];
        		j--;
			}
			A[j+1] = t;
		}
    }
}
