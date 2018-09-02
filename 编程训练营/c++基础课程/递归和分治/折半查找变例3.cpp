/*
	Name: 折半查找变例3 
	Copyright: 
	Author: 
	Date: 21-08-18 17:09
	Description: 已知数组元素A[1]到A[8]的值依次为{3,18,20,24,45,56,67,88}，
	执行该程序段后，函数返回的值不可能是( B  ) 
	A -3   B -4  C 3  D 4
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 9;
int A[MAX] = {0,3,18,20,24,45,56,67,88};

int BinarySearch(int i, int j) //折半查找值为x的元素的下标，找不到则返回-1 
{
	int k=0, m;
	int key = rand()%100;

	while (i <= j)
	{
		m = (i + j) / 2;
		if (key == A[m])
			break;
		else if (key < A[m])
			j = m - 1, k--;
		else
			i = m + 1, k++;
	}
	return k;
}

int main() 
{
	cout << BinarySearch(1, 8) << endl;
		
    return 0;
}
