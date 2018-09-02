/*
	Name: 求分数的精确值 
	Copyright: 
	Author: 
	Date: 02-09-18 16:02
	Description: 求分数的精确值 
	输入分子和分母，输出其商，如果商为循环小数，将循环节用括号括起来，
	否则最多计算到第200位。 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 201;
int A[MAX] = {0};
int B[MAX] = {0};

int Fun(int m, int n); //求分数的精确值，返回商的长度 
int Circulate(int n);//返回循环节的位置 

int main() 
{
	int m, n;
	cin >> m >> n;
	while(m > 0 && n > 0)
	{
		cout << Fun(m, n) << endl;
		cin >> m >> n;
	}
	
    return 0;
}

int Fun(int m, int n) //求分数的精确值，返回商的长度 
{
	int pos = 0; //循环节的位置
	int pa = 0, pb = 0;
	
	A[0] = m / n;
	B[0] = m % n;
	while (B[pb] != 0 && pa < MAX && pos == pb)
	{
		m = B[pb] * 10;
		A[++pa] = m / n;
		B[++pb] = m % n;
		pos = Circulate(pb);
	}
	cout << A[0] << ".";
	for (int i=1; i<=pos; i++)
		cout << A[i];
	if (pos != pb)
		cout << "(";
	for (int i=pos+1; i<=pa; i++)
		cout << A[i];
	if (pos != pb)
		cout << ")";
	cout << endl;
	
	return pa;
}

int Circulate(int n)//返回循环节的位置 
{
	for (int i=0; i<n; i++)
	{
		if (B[i] == B[n])
			return i;
	}
	return n;
}
