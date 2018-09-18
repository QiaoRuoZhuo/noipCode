/*
	Name: 将整数调整成最大值 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: 输入一个正整数，将其各位数字进行调换以后获得一个最大整数，返回该最大整数。 
	例如输入n=2563;则返回6532。 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

int Fun(unsigned int n); 

int main()
{
	for (int i=1; i<=1000; i++)
		cout << i << ": " << Fun(i) << "   ";
	cout << endl; 
	
	return 0;
}

int Fun(unsigned int n)
{
	int A[50] = {0};
	int m = 0, t = 0, len = 0, i;
	
	while (n > 0)
	{
		t = n % 10;
		n /= 10;
		for (i=len-1; i>=0 && A[i]<t; i--) //递减序插入新值 
			A[i+1] = A[i];
		A[i+1] = t;
		len++;
	}
	for (i=0; i<len; i++)
		m = m * 10 + A[i];
	return m;
}
