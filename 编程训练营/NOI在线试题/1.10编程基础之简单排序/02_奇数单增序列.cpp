/*
	Name: 02_奇数单增序列
	Copyright: 
	Author: 
	Date: 17-08-17 10:45
	Description: 02_奇数单增序列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个长度为N（不大于500）的正整数序列，请将其中的所有奇数取出，并按升序输出。

输入
共2行：
第1行为 N；
第2行为 N 个正整数，其间用空格间隔。
输出
增序输出的奇数序列，数据之间以逗号间隔。数据保证至少有一个奇数。
样例输入
10
1 3 2 6 5 4 9 8 7 10
样例输出
1,3,5,7,9
*/
#include<iostream>

using namespace std;

const int M = 500;
int A[M], B[M];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	//获取第一个奇数 
	int f = 0;
	while (f < n && A[f]%2 == 0)
		f++;
	B[0] = A[f];
	
	int len = 1, low, high, mid;
	for (int i=f+1; i<n; i++)//对老年人插入排序（存储序号） 
	{
		if (A[i]%2 == 1)
		{
			low = 0;
			high = len-1;
			while(low <= high) //折半查找插入位置
			{
				mid = (low + high)/2;
				if (B[mid] > A[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j=len++; j>low; j--)
		    {
				B[j] = B[j-1];
		    }
		    B[low] = A[i];
		}
	}
	
	cout << B[0];
	for (int i=1; i<len; i++)
		cout << "," << B[i];
	cout << endl;
	
    return 0;
}
