/*
	Name: 常量，变量和数组的地址 
	Copyright: 
	Author: 
	Date: 04\09\18 13:55
	Description: 了解数组元素的地址分布 
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	const int MAX = 4;
	const double MIN = 66;
	int m = 100, n = 200;
	int a[MAX] = {1,2,3,4};
	int b[5*5*MAX] = {0};
	int &c = a[0];
	
	cout << MAX << " : " << &MAX << endl;
	cout << MIN << " : " << &MIN << endl;
	cout << m << " : " << &m << endl;
	cout << n << " : " << &n << endl;
	for (int i=0; i<MAX; i++)
		cout << a[i] << " "<< &a[i] << endl;
	cout << a << endl;
	cout << &a << endl; 
    
    return 0;
} 
