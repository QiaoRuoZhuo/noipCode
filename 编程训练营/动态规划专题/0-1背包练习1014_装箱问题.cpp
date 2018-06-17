/*
	Name: 1014_装箱问题  
	Author: 巧若拙 
	Description: 
有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
输入描述 Input Description
一个整数v，表示箱子容量
一个整数n，表示有n个物品
接下来n个整数，分别表示这n 个物品的各自体积
输出描述 Output Description
一个整数，表示箱子剩余空间。

样例输入 Sample Input
24 
6 
8 3 12 7 9 7

样例输出 Sample Output
0 
算法分析：这是一个典型的0-1背包问题，可设物品的价值大小等于其体积，求最大价值。
*/
#include<iostream>

using namespace std;

const int MAXC = 20000; //背包最大容量 
const int MAXN = 30; //物品的最大个数
int V[MAXN+1];//第i个数的值相当于0-1背包中物品的体积和价值 
int F[MAXC+1]; //动态规划中记录给定n个物品装入容量为j的背包的最大价值

int ZeroOnePack_5(int n, int c);//优化的动态规划算法，一维数组存储记录，F[j]初始化为0 

int main() 
{
	int n, c;
	cin >> c >> n;
	
	for (int i=1; i<=n; i++)//不计下标为0的元素 
	{
		cin >> V[i];
	}
	
	cout << c - ZeroOnePack_5(n, c) << endl; 
	
	return 0;
}

int ZeroOnePack_5(int n, int c)//优化的动态规划算法，一维数组存储记录，F[j]初始化为0  
{
 	for (int i=1; i<=n; i++)
	{//须先求出列坐标j较大的F5[j]，故让循环变量j的值从大到小递减
		for (int j=c; j>=V[i]; j--)
		{
			if (F[j] < F[j-V[i]] + V[i])
				F[j] = F[j-V[i]] + V[i];
		}
	}
	
	return F[c];
}

