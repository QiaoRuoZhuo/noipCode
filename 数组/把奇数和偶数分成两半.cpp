/*
	Name: 把奇数和偶数分成两半 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: 有一组正整数，要求把奇数和偶数分成两半，其中奇数在前，偶数在后，返回奇数的数量。 
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 10;
int A[M];

int Fun(int n);//要求把奇数和偶数分成两半，其中奇数在前，偶数在后，返回奇数的数量

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 19 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	cout << Fun(n) << endl;
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

int Fun(int n)//要求把奇数和偶数分成两半，其中奇数在前，偶数在后，返回奇数的数量
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


