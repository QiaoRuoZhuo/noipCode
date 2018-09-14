/*
	Name: 折半查找变例6
	Copyright: 
	Author: 
	Date: 14\09\18 14:51
	Description: 已知一无序数组a中的元素为"90,15,40,72,65,32,81,6"，
	通过引入数组b存储a中元素按升序排序时的下标，b数组元素为"8,2,6,3,5,4,7,1"，
	使得a(b(1))<= a(b(2))<=……a(b(n))，从而对数组a中的元素进行对分查找。
	部分代码如下：
i = 1: j = 8: c = 0
    key = 32
    Do While i <= j
        m = (i + j) \ 2
        t = b(m)
        c = c + 1
        If a(t) = key Then p = t: Exit Do
        If a(t) < key Then i = m + 1 Else j = m - 1
Loop
程序运行结束后变量c的值为（  C   ）
A 1    B 2    C 3    D 4

*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAX = 9;
int A[MAX] = {0,90,15,40,72,65,32,81,6};
int B[MAX] = {0,8,2,6,3,5,4,7,1};

int BinarySearch(int i, int j, int key) //折半查找值为x的元素的下标，找不到则返回-1 
{
	int c = 0, m, t;
	while (i <= j)
	{
		c++;
		m = (i + j) / 2;
		t = B[m];
		if (key == A[t])
			return t;
		else if (key < A[t])
			j = m - 1;
		else
			i = m + 1;
	}

	return -1;
}

int main() 
{
	for (int i=1; i<8; i++)
		cout << A[i] << ":" << BinarySearch(1, 8, A[i]) << endl;
		
    return 0;
}
