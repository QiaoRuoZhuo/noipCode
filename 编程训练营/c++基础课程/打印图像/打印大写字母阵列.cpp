/*
	Name: 打印大写字母阵列
	Copyright: 
	Author: 
	Date: 19-08-18 21:34
	Description: 输入n，打印大写字母阵列
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
		for (int j=0; j<n-i; j++)//输出空格 
			cout << " ";
		for (int j=0; j<i; j++)//顺序输出字母 
			cout << char('A'+j);
		for (int j=i-2; j>=0; j--)//逆序输出字母 
			cout << char('A'+j);
		cout << endl;
	} 
    return 0;               
}           
