/*
	Name: 2985_数字组合
	Author: 巧若拙
描述
有n个正整数，找出其中和为t(t也是正整数)的可能的组合方式。如：
n=5,5个数分别为1,2,3,4,5，t=5；
那么可能的组合有5=1+4和5=2+3和5=5三种组合方式。
输入
输入的第一行是两个正整数n和t，用空格隔开，其中1<=n<=20,表示正整数的个数，t为要求的和(1<=t<=1000)
接下来的一行是n个正整数，用空格隔开。
输出
和为t的不同的组合方式的数目。
样例输入
5 5
1 2 3 4 5
样例输出
3

算法分析：这是一个典型的0-1背包问题，只不过不是求最优解，而是求所有可能的组合，故需要累计所有的组合。 
*/
#include<iostream>

using namespace std;

const int MAXC = 10000; //背包最大容量 
const int MAXN = 20; //物品的最大个数
int V[MAXN+1];//第i个数的值相当于0-1背包中物品的重量和价值 
long long F[MAXC+1] = {1}; //记录给定n个物品装入容量为j的背包的分配方案数量 
int B3[MAXN+1][MAXC+1]; //动态规划中记录给定i个物品装入容量为j的背包的分配方案数量 

long long ZeroOnePack_3(int n, int c);//可以转化为求0-1背包的方案总数
long long ZeroOnePack_5(int n, int c);//可以转化为求0-1背包的方案总数

int main() 
{
	int n, c;
	cin >> n >> c;
	
	for (int i=1; i<=n; i++)//不计下标为0的元素 
	{
		cin >> V[i];
	}
	
	cout << ZeroOnePack_3(n, c) << endl; 
//	cout << ZeroOnePack_5(n, c) << endl; 
	
	return 0;
}

long long ZeroOnePack_3(int n, int c)//可以转化为求0-1背包的方案总数 
{
	for (int i=0; i<=n; i++) //和为0时总有1个方案 
		B3[i][0] = 1;
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++) 
		{
			B3[i][j] = B3[i-1][j]; //先假设不使用物品i，即没有产生新的方案 
			if (j >= V[i]) //加上使用物品i后产生的新方案 
				B3[i][j] += B3[i-1][j-V[i]];
		}
	}
	
	return B3[n][c];
}

long long ZeroOnePack_5(int n, int c)//可以转化为求0-1背包的方案总数 
{
 	for (int i=1; i<=n; i++)
	{//须先求出列坐标j较大的F[j]，故让循环变量j的值从大到小递减
		for (int j=c; j>=V[i]; j--)
		{//当(j < V[i])时，F[j]的值不变，即没有产生新的方案 
			F[j] += F[j-V[i]];
		}
	}
	
	return F[c];
}
