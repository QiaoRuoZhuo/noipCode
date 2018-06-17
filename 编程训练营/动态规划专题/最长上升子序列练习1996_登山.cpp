/*
	Name: 1996_登山
	Author:巧若拙 
	Description: 1996_登山
五一到了，PKU-ACM队组织大家去登山观光，队员们发现山上一个有N个景点，并且决定按照顺序来浏览这些景点，
即每次所浏览景点的编号都要大于前一个浏览景点的编号。同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，
并且一旦开始下山，就不再向上走了。队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？
输入
Line 1： N (2 <= N <= 1000) 景点数
Line 2： N个整数，每个景点的海拔
输出
最多能浏览的景点数
样例输入
8
186 186 150 200 160 130 197 220
样例输出
4
*/
#include<iostream>

using namespace std;

const int MAX = 1001; 
int A[MAX];
int SL2[MAX]; //记录到元素i为止的最长上升子序列的长度 
int SR2[MAX]; //记录到元素i为止的最长上升子序列的长度 

int DP_2(int n); //顺序处理 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
	}
	
	cout << DP_2(n) << endl;//顺序处理 
	
    return 0;
}

int DP_2(int n) //顺序搜索 
{
	for (int i=0; i<n; i++)//从左向右搜索上升子序列 
	{ 
		for (int j=i-1; j>=0; j--) 
		{
			if (A[i] > A[j] && SL2[j] > SL2[i])
				SL2[i] = SL2[j];
		}
		SL2[i]++;  
	}
	
	for (int i=n-1; i>=0; i--)//从右向左搜索上升子序列 
	{ 
		for (int j=i+1; j<n; j++) 
		{
			if (A[i] > A[j] && SR2[j] > SR2[i])
				SR2[i] = SR2[j];
		}
		SR2[i]++;  
	}
	
	int m = 0;
	for (int i=0; i<n; i++)//从左向右搜索上升子序列 
	{ 
		if (m < SL2[i] + SR2[i])
			m = SL2[i] + SR2[i];	 
	}
	
	return m - 1; //最高点重复计算了一次 
}
