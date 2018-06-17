/*
	Name: 背包系列专题之完全背包问题
	Author: 巧若拙
	Description: 
完全背包问题：在n种物品中选取若干件（同一种物品可多次选取）放在容量为c的背包里，分别用P[i]和W[i]存储第i种物品的价值和重量。
求解怎么装物品可使背包里物品总价值最大。
样例输入
4 12
2 3
5 7
6 8
10 12
样例输出
18
*/
#include<iostream>

using namespace std;

const int MAXC = 10000; //背包最大容量 
const int MAXN = 2000; //物品的最大个数
int W[MAXN+1];//物品的重量 
int P[MAXN+1];//物品的价值 
int B1[MAXN+1][MAXC+1]; //记录给定n个物品装入容量为c的背包的最大价值 
int B2[MAXN+1][MAXC+1]; //记录给定n个物品装入容量为c的背包的最大价值 
int pre[MAXC+1]; //pre[j]相当于B2[i-1][j] 
int cur[MAXC+1]; //cur[j]相当于B2[i][j]
int B4[MAXC+1]; //记录最优解 
int X[MAXN+1]; //记录装入背包中的物品编号及其数量 

int CompletePack_1(int n, int c);//动态规划+朴素的穷举思想
int CompletePack_2(int n, int c);//动态规划:F[i][j] = max(F[i-1][j], F[i][j-W[i]] + P[i])
int CompletePack_3(int n, int c);//优化的动态规划算法，用2个一维数组代替二维数组 
int CompletePack_4(int n, int c);//优化的动态规划算法，一维数组存储记录
void Show(int i, int j);  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量
int Show_2(int n, int c); //利用数组B2[][]，输出物品装载情况，并返回实际装载量，X[i]初始化为0 

int main() 
{
	int n, c;
	cin >> n >> c;
	
	for (int i=1; i<=n; i++)//不计下标为0的元素 
	{
		cin >> W[i] >> P[i];
	}
	
	//动态规划+朴素的穷举思想，需要用到全局变量W[], P[], 另有B1[MAXN+1][]初始化为0
	cout << CompletePack_1(n, c) << endl; 
	
	//动态规划：二维数组存储记录，需要用到全局变量W[], P[], 另有B2[MAXN+1][]默认初始化为0 
	cout << CompletePack_2(n, c) << endl; 
	
	//动态规划：使用2个一维数组存储记录，需要用到全局变量W[], P[], 另有pre[]和cur[]均初始化为0
	cout << CompletePack_3(n, c) << endl; 
	
	//优化的动态规划算法，一维数组存储记录，需要用到全局变量W[], P[], 另有B4[]初始化为0
	cout << CompletePack_4(n, c) << endl; 
	
	//利用数组B2[][]，输出物品装载情况，X[i]初始化为0
	cout << Show_2(n, c) << endl; 
	
	//利用数组B2[][]，按照编号顺序，递归输出装入背包的物品信息（编号，数量，重量，价值）
	Show(n, c); 
	
	return 0;
}

int CompletePack_1(int n, int c)//动态规划+朴素的穷举思想
{
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			//朴素的穷举思想，穷举装入第i种物品的数量，存储能获得的最大价值到B[i][j] 
			int bestP = 0;
			for (int k=0; k*W[i]<=j; k++)
			{
				if (bestP < B1[i-1][j-k*W[i]] + k*P[i])
					bestP = B1[i-1][j-k*W[i]] + k*P[i];
			}
			B1[i][j] = bestP;
		}
	}
	
	return B1[n][c];
}

int CompletePack_2(int n, int c)//动态规划:F[i][j] = max(F[i-1][j], F[i][j-W[i]] + P[i])
{
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			if (j < W[i]) //现有容量不够，则和给定i-1个物品装入容量为j的背包的结果一致 
				B2[i][j] = B2[i-1][j];
			else //现有容量足够，本次可以选择装或不装第i件物品（因为第i件物品可以装无限次，故背包中可能已经装有第i件物品了） 
				B2[i][j] = max(B2[i-1][j], B2[i][j-W[i]] + P[i]);
		}
	}
	
	return B2[n][c];
}

int CompletePack_3(int n, int c)//优化的动态规划算法，用2个一维数组代替二维数组 
{
	//pre[j]相当于B2[i-1][j]，cur[j]相当于B2[i][j] 
 	for (int i=1; i<=n; i++)
	{   //须先求出列坐标j较小的F[j]，故让循环变量j的值从小到大递增
		for (int j=1; j<=c; j++)
		{
			if (j < W[i] || pre[j] > cur[j-W[i]] + P[i])
				cur[j] = pre[j]; 
			else
				cur[j] = cur[j-W[i]] + P[i];
		}
		for (int j=0; j<=c; j++)
		{
			pre[j] = cur[j]; 
		}
	}
	
	return cur[c];
}

int CompletePack_4(int n, int c)//进一步优化的动态规划算法，用1个一维数组代替二维数组
{
 	for (int i=1; i<=n; i++)
	{//须先求出列坐标j较小的F[j]，故让循环变量j的值从小到大递增 
		for (int j=W[i]; j<=c; j++)
		{//当(j < W[i] || B4[j] > B4[j-W[i]] + P[i])时，B4[j]的值不变
			if (B4[j] < B4[j-W[i]] + P[i])
				B4[j] = B4[j-W[i]] + P[i];
		}
	}
	
	return B4[c];
}

void Show(int i, int j)  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量
{
	if (j == 0 || i == 0)
		return;
	
	if (B2[i][j] == B2[i-1][j]) 
	{
		Show(i-1, j); //未装载物品i
	}
	else
	{
		for (int k=j/W[i]; k>0; k--)
		{
			if (B2[i][j] == B2[i-1][j-k*W[i]] + k*P[i]) //装载了k个物品i 
			{
				Show(i-1, j-k*W[i]);
				cout << i << ": " << k << " " << W[i] << " " << P[i] << endl;
				return;
			}
		}
	}
} 

int Show_2(int n, int c) //利用数组B2[][]，输出物品装载情况，并返回实际装载量，X[i]初始化为0 
{
	for (int i=n,j=c; i>0; i--)
	{
		if (B2[i][j] != B2[i-1][j]) 
		{
			for (int k=j/W[i]; k>0; k--)
			{
				if (B2[i][j] == B2[i-1][j-k*W[i]] + k*P[i])
				{
					X[i] = k;
					j -= k*W[i]; //更新j的值 
					break;
				}
			}
		}
	}
	
	int s = 0;
	for (int i=1; i<=n; i++)
	{
		if (X[i] > 0)
		{
			s += P[i] * X[i];
			cout << i << ": " << X[i] << " " << W[i] << " " << P[i] << endl;
		}
	}	
	return s;
} 
