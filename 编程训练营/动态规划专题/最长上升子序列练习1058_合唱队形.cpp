/*
	Name: 1058_合唱队形
	Author:巧若拙 
	Description: 1058_合唱队形  2004年NOIP全国联赛提高组
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，  
则他们的身高满足T1<...<Ti>Ti+1>…>TK(1<=i<=K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入描述 Input Description
输入文件chorus.in的第一行是一个整数N(2<=N<=100)，表示同学的总数。第一行有n个整数，用空格分隔，
第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)。
输出描述 Output Description
输出文件chorus.out包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
样例输入 Sample Input
8
186 186 150 200 160 130 197 220
样例输出 Sample Output
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
	for (int i=0; i<n; i++) 
	{ 
		if (m < SL2[i] + SR2[i])
			m = SL2[i] + SR2[i];	 
	}
	
	return n - m + 1; //最高点重复计算了一次 
}
