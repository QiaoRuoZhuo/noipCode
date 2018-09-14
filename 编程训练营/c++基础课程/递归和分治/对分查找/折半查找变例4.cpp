/*
	Name: 折半查找变例4 
	Copyright: 
	Author: 
	Date: 21-08-18 17:09
	Description: 已知数组元素A[1]到A[10]的值依次为{3,9,21,21,21,21,27,28,39,40}，
	执行该程序段后，变量R,A[R]的值分别是( C  ) 
	A 2,9   B 3,21  C 6,21  D 7,27
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 11;
int A[MAX] = {0,3,9,21,21,21,21,27,28,39,40};

int BinarySearch(int L, int R, int key) //折半查找值为x的元素的下标，找不到则返回-1 
{
	int k=0, m;

	while (L <= R)
	{
		m = (L + R) / 2;
		if (key >= A[m])
			L = m + 1;
		else
			R = m - 1;
	}
	return R;
}

int main() 
{
	cout << BinarySearch(1, 10, 21) << endl;
		
    return 0;
}
