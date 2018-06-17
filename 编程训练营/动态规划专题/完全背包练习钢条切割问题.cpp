/* 
    Name: 钢条切割问题 
    Author: 巧若拙  
    Description:  给定一段长度为n英寸的钢条和一个价格表 pi (i=1,2, …,n)，求切割钢条的方案，使得销售收益rn最大。
	注意，如果长度为n英寸的钢条价格pn足够大，最优解可能就是完全不需要切割。
若钢条的长度为i，则钢条的价格为Pi，如何对给定长度的钢条进行切割能得到最大收益？
长度i   1   2   3   4     5     6     7     8     9     10
价格Pi  1   5   8   9    10     17    17    20    14    30

i = 1时，钢条不可切割，r[1]= 1；
i = 2时，钢条可分割为1+ 1，其价格为2。若不分割（0 + 2），价格为5。即r[2] = 5；
i = 3时，钢条可分割为0+ 3，1 + 2。r[3] = 8；
同理可得：
r[4] = 10（2+ 2）；
r[5] = 13（2+ 3）；
r[6] = 17（0+ 6）；
r[7] = 18（1+ 6或4+ 3=> 2 + 2 + 3）；
.......
我们可以发现，长度为7时，将其切割为长度4与长度3的钢条，并对两个钢条分别求最优解：
长度4的最优解为r[4] = 10（2 + 2），长度3的最优解为r[3] = 8，即可得r[7] =r[4]+ r[3] =>原问题的最优解等于子问题的最优解之和的最大值
我们将钢条左边切割下长度为 i 的一段，只对右边剩下的长度为 n-i 的一段继续进行切割（递归求解），对左边的一段不再进行切割。
即问题分解的方式为：将长度为n 的钢条分解为左边开始一段，以及剩余部分继续分解的结果。
这样，不做任何切割的方案就可以描述为：第一段的长度为n ，收益为 pn，剩余部分长度为0，对应的收益为r0=0。于是公式的简化版本：
因此，在计算r[i]时，所求值即为r[0] +r[i]，r[1]+ r[i-1]，r[2]+ r[i-2]，...  ，r[i-1] +r[1] 之间的最大值，
而在动态规划中，r[0]--r[i-1]的值在计算r[i]之前已经保存好了，进行少量的运算便能取得最优结果。

这个是典型的完全背包问题，相当于共有n个物品，物品的重量wi分别是1-n，价值为pi，背包总容量为n，求最大价值。 
*/  
#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

const int MAXC = 10000; //背包最大容量 
const int MAXN = 10000; //物品的最大个数
int W[MAXN+1];//物品的重量 
int P[MAXN+1];//物品的价值 
int B2[MAXN+1][MAXC+1]; //记录给定n个物品装入容量为c的背包的最大价值 
int B4[MAXC+1]; //记录最优解 
int X[MAXN+1]; //记录装入背包中的物品编号及其数量 

int CompletePack_2(int n, int c);//动态规划:F[i][j] = max(F[i-1][j], F[i][j-W[i]] + P[i])
int CompletePack_4(int n, int c);//优化的动态规划算法，一维数组存储记录
void Show(int i, int j);  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量
int Show_2(int n, int c); //利用数组B2[][]，输出物品装载情况，并返回实际装载量，X[i]初始化为0 

int main() 
{
	int n, c;
	cin >> n;
	
	for (int i=1; i<=n; i++)//随机获取长度价格，但确保长的比短的价值高   
    {  
        do{  
            P[i] = (i>4)? (P[i-4] + rand()%20+1) : rand()%20+1;  
        }while (P[i] <= P[i-1]);  
        printf("%d ", P[i]);  
        W[i] = i;
    }  
	c = n;
	//动态规划：二维数组存储记录，需要用到全局变量W[], P[], 另有B2[MAXN+1][]默认初始化为0 
	cout << CompletePack_2(n, c) << endl; 
	
	//优化的动态规划算法，一维数组存储记录，需要用到全局变量W[], P[], 另有B4[]初始化为0
	cout << CompletePack_4(n, c) << endl; 
	
	//利用数组B2[][]，输出物品装载情况，X[i]初始化为0
	cout << Show_2(n, c) << endl; 
	
	//利用数组B2[][]，按照编号顺序，递归输出装入背包的物品信息（编号，数量，重量，价值）
	Show(n, c); 

	return 0;
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
			s += W[i] * X[i];
			cout << i << ": " << X[i] << " " << W[i] << " " << P[i] << endl;
		}
	}	
	return s;
} 
