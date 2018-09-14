/*
	Name: 折半查找变例7随机分段查找
	Copyright: 
	Author: 
	Date: 14\09\18 14:51
	Description: 把折半查找改为随机设定枢纽 
    将语句1,2补充完整。 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 6;
int A[MAX] = {0,6,18,25,37,49};

int BinarySearch(int i, int j, int key) //随机分段查找值为x的元素的下标，找不到则返回-1 
{
	int m;

	while (i <= j)
	{
		m = rand() % (j - i + 1) + i;
		if (key == A[m])
			return m;
		else if (key < A[m])
			j = m - 1; //语句1 
		else
			i = m + 1; //语句2
	}
	return -1;
}

int main() 
{
	for (int key=0; key<50; key++)
		cout << key << ":" << BinarySearch(1, 5, key) << endl;
		
    return 0;
}
