/*
	Name: 1768_最大子矩阵
	Author: 巧若拙 
描述
已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
比如，如下4 * 4的矩阵
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
的最大子矩阵是
9 2
-4 1
-1 8
这个子矩阵的大小是15。
输入
输入是一个N * N的矩阵。输入的第一行给出N (0 < N <= 100)。
再后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）给出矩阵中的N2个整数，
整数之间由空白字符分隔（空格或者空行）。已知矩阵中整数的范围都在[-127, 127]。
输出
输出最大子矩阵的大小。
样例输入
4
0 -2 -7 0 
9 2 -6 2
-4 1 -4  1
-1 8  0 -2
样例输出
15

算法分析：
分别采用了3种算法：
算法1是计算夹在上下边界之间的矩阵的最大连续子序列之和，即设置一个数组B[k]存储行号为[i,j]范围内，第k列元素的和，计算数组B中最大子序列和
算法2是计算夹在左右边界之间的矩阵的最大连续子序列之和，即设置一个数组B[k]存储列号为[i,j]范围内，第k行元素的和，计算数组B中最大子序列和 
算法3和算法2的思路基本一致，但是采用了不同的数据结构和计算数组中最大子序列和的方法。 
算法4和算法3的思路基本一致，但是采用了不同的设置左右边界方法。 
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;
int A[N+1][N+1], C[N+1][N+1];
int B[N+1];

int Fun_1(int n);//计算夹在上下边界之间的矩阵的最大连续子序列之和 
int Fun_2(int n);//计算夹在左右边界之间的矩阵的最大连续子序列之和解法一 
int Fun_3(int n);//计算夹在左右边界之间的矩阵的最大连续子序列之和解法二 
int Fun_4(int n);//计算夹在左右边界之间的矩阵的最大连续子序列之和解法三 

int main() 
{
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> A[i][j];
		}
	}
	
	cout << Fun_1(n) << endl;
	cout << Fun_2(n) << endl;
	cout << Fun_3(n) << endl;
	cout << Fun_4(n) << endl;
	
	return 0;	
} 

int Fun_1(int n)//计算夹在上下边界之间的矩阵的最大连续子序列之和 
{
	int maxSum = A[1][1], sum;
	for (int i=1; i<=n; i++)//i为上边界 
	{
		memset(B, 0, sizeof(B));
		for (int j=i; j<=n; j++)//j为下边界 
		{
			for (int k=1; k<=n; k++)//k表示列号
			{
				B[k] += A[j][k]; //B[k]存储行号为[i,j]范围内，第k列元素的和 
			} 
			//计算数组B中最大子序列和
			sum = B[1];
			for (int k=2; k<=n; k++)//k表示列号
			{
				if (sum > 0)
				{
					sum += B[k];
					if (sum > maxSum)
					{
						maxSum = sum;
					}
				}
				else
				{
					sum = B[k];
				}
			}  
		}
	}
	return maxSum;
} 

int Fun_2(int n)//计算夹在左右边界之间的矩阵的最大连续子序列之和解法一
{
	int maxSum = A[1][1], sum;
	for (int i=1; i<=n; i++)//i为左边界 
	{
		memset(B, 0, sizeof(B));
		for (int j=i; j<=n; j++)//j为右边界 
		{
			for (int k=1; k<=n; k++)//k表示行号
			{
				B[k] += A[j][k]; //B[k]存储列号为[i,j]范围内，第k行元素的和 
			} 
			//计算数组B中最大子序列和
			sum = B[1];
			for (int k=2; k<=n; k++)//k表示行号
			{
				if (sum > 0)
				{
					sum += B[k];
					if (sum > maxSum)
					{
						maxSum = sum;
					}
				}
				else
				{
					sum = B[k];
				}
			}  
		}
	}
	return maxSum;
}

int Fun_3(int n)//计算夹在左右边界之间的矩阵的最大连续子序列之和解法二 
{
	for (int i=1; i<=n; i++)//C[i][j]记录第i行前j个数的和 
	{
		for (int j=1; j<=n; j++)
		{
			C[i][j] = C[i][j-1] + A[i][j];
		}
	}
	
	int maxSum = A[1][1], sum;
	for (int i=1; i<=n; i++)//i为左边界 
	{
		for (int j=i; j<=n; j++)//j为右边界 
		{
			//在列号为[i,j]范围内，把每一行元素的和看成一个新的元素，共n行，则有n个元素，求这n个元素的最大子序列和
			sum = 0;
			for (int k=1; k<=n; k++)//k表示行号
			{
				sum += C[k][j] - C[k][i-1];
				if (sum > maxSum)
				{
					maxSum = sum;
				}
				else if (sum < 0)
				{
					sum = 0;
				}
			}  
		}
	}
	return maxSum;
}

int Fun_4(int n)//计算夹在左右边界之间的矩阵的最大连续子序列之和解法三 
{
	for (int i=1; i<=n; i++)//C[i][j]记录第i行前j个数的和 
	{
		for (int j=1; j<=n; j++)
		{
			C[i][j] = C[i][j-1] + A[i][j];
		}
	}
	
	int maxSum = A[1][1], sum;
	for (int r=1; r<=n; r++)//r表示正在处理的矩阵的宽度 
	{
		for (int i=1; i<=n-r+1; i++)//i为左边界 
		{
			int j = i + r - 1;//j为右边界 
			//在列号为[i,j]范围内，把每一行元素的和看成一个新的元素，共n行，则有n个元素，求这n个元素的最大子序列和
			sum = 0;
			for (int k=1; k<=n; k++)//k表示行号
			{
				sum += C[k][j] - C[k][i-1];
				if (sum > maxSum)
				{
					maxSum = sum;
				}
				else if (sum < 0)
				{
					sum = 0;
				}
			}  
		}
	}
	return maxSum;
}
