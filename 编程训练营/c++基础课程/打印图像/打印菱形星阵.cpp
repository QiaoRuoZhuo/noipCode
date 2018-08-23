/*
	Name: 打印菱形星阵 
	Copyright: 
	Author: 
	Date: 19-08-18 21:34
	Description: 输入n，打印(2*n-1)行菱形星阵
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)//打印上三角形
	{
		for (int j=1; j<=n-i; j++)
			cout << " ";
		for (int j=1; j<=2*i-1; j++)
			cout << "*";
		cout << endl;
	} 
	for (int i=n-1; i>=1; i--)//打印下三角形
	{
		for (int j=1; j<=n-i; j++)
			cout << " ";
		for (int j=1; j<=2*i-1; j++)
			cout << "*";
		cout << endl;
	} 
     
    return 0;               
}           
