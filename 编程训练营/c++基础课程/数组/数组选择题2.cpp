/*
	Name: 数组选择题2
	Copyright: 
	Author: 
	Date: 04\09\18 15:49
	Description: 
	有如下代码段：
	int A[10] = {0};
	int n = 10242048, s = 0;  
	while (n != 0)
	{
		A[n%10] = 1;
		n /= 10;
	}
	for (int i=0; i<10; i++)
		s += A[i];
	cout << s;
	执行上述代码段后，程序输出（ C  ）
	A 1   B 2   C 5   D 10 
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	int A[10] = {0};
	int n = 10242048, s = 0;  
	while (n != 0)
	{
		A[n%10] = 1;
		n /= 10;
	}
	for (int i=0; i<10; i++)
		s += A[i];
	cout << s;
	
	return 0;	
} 
