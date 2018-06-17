/*
	Name: 动态规划专题之0-1背包问题
	Author: 巧若拙
	Description: 
0-1背包问题：在n种物品中选取若干件（同一种物品最多选一次）放在容量为c的背包里，分别用P[i]和W[i]存储第i种物品的价值和重量。
求解怎么装物品可使背包里物品总价值最大。
样例输入
4 12
2 3
5 7
6 8
10 12
样例输出
15
*/
#include<iostream>
#include<cstring>

using namespace std;

const int MAXC = 10000; //背包最大容量 
const int MAXN = 2000; //物品的最大个数
int W[MAXN+1];//物品的重量 
int P[MAXN+1];//物品的价值 
int B2[MAXN+1][MAXC+1]; //备忘录，记录给定n个物品装入容量为c的背包的最大价值 
int B3[MAXN+1][MAXC+1]; //动态规划中记录给定i个物品装入容量为j的背包的最大价值 
int pre[MAXC+1]; //记录上一行元素值
int cur[MAXC+1]; //记录当前行元素值
int F[MAXC+1]; //动态规划中记录给定n个物品装入容量为j的背包的最大价值
bool X[MAXN+1]; //记录装入背包中的物品编号 
int cw, cp;//在回溯算法中分别记录给定t个物品时，已装物品的总重量和总价值
int bestPrice; //在回溯算法中记录目前已知的最大总价值，初始化为0 

int Sum(int n, int t);//累计第t+1到n个物品的总价值
void ZeroOnePack_1(int n, int c, int t);//回溯算法求0-1背包问题 
int ZeroOnePack_2(int n, int c);//记忆化搜索（备忘录算法）求0-1背包问题 
int ZeroOnePack_3(int n, int c);//动态规划：二维数组存储记录
int ZeroOnePack_4(int n, int c);//优化的动态规划算法，使用2个一维数组代替二维数组
int ZeroOnePack_5(int n, int c);//优化的动态规划算法，一维数组存储记录
int Show_3(int n, int c); //利用数组B3[][]，输出物品装载情况，并返回实际装载量，X[i]初始化为0 
void Show(int i, int j);  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量

int main() 
{
	int n, c;
	cin >> n >> c;
	
	for (int i=1; i<=n; i++)//不计下标为0的元素 
	{
		cin >> W[i] >> P[i];
	}
	
	//回溯算法，需要用到全局变量cw, cp, bestPrice, W[], P[]
	ZeroOnePack_1(n, c, 1); //不计下标为0的元素
	cout << bestPrice << endl;
	
	//记忆化搜索（备忘录算法），需要用到全局变量W[], P[], 另有B2[MAXN+1][]初始化为-1
	memset(B2, -1, sizeof(B2)); //先初始化B2的值全为-1
	cout << ZeroOnePack_2(n, c) << endl; 
	
	//动态规划：二维数组存储记录，需要用到全局变量W[], P[], 另有B3[MAXN+1][]默认初始化为0 
	cout << ZeroOnePack_3(n, c) << endl; 
	
	//动态规划：使用2个一维数组存储记录，需要用到全局变量W[], P[], 另有pre[]和cur[]均初始化为0
	cout << ZeroOnePack_4(n, c) << endl; 
	
	//优化的动态规划算法，一维数组存储记录，需要用到全局变量W[], P[], 另有F[]初始化为0
	cout << ZeroOnePack_5(n, c) << endl; 
	
	//利用数组B3[][]，输出物品装载情况，X[i]初始化为0
	cout << Show_3(n, c) << endl; 
	
	//利用数组B3[][]，按照编号顺序，递归输出装入背包的物品信息（编号，重量，价值）
	Show(n, c); 
	
	return 0;
}

int Sum(int n, int t)//累计第t+1到n个物品的总价值 
{
 	int s = 0;
    for (int i=t+1; i<=n; i++) 
	{
	 	s += P[i];
	}
    return s;
}

void ZeroOnePack_1(int n, int c, int t)//回溯算法求0-1背包问题 
{
    if (t == n+1)
    {
        bestPrice = max(cp, bestPrice);
    }
    else
    {  
 		if (cw+W[t] <= c)//若不超载，则先分析装t号物品的情形（应该有可能得到更好的解，否则在上一层就被剪枝了） 
 		{
			cw += W[t]; cp += P[t];
			ZeroOnePack_1(n, c, t+1);
			cw -= W[t]; cp -= P[t];
	    }	
	 	//再分析不装t号物品的情形
		if (cp+Sum(n, t) > bestPrice)//如果有可能得到更好的解，则进入下一层（装都没装，判断是否超载也是白判断，放到下一层再做判断） 
			ZeroOnePack_1(n, c, t+1);
    }
}

int ZeroOnePack_2(int n, int c)//记忆化搜索（备忘录算法）求0-1背包问题，B2[n][c]初始化为-1 
{
 	if (B2[n][c] != -1)  
		return B2[n][c];
 	
	int bestP = 0;
	if (n == 1)//处理只给定了1个物品的情形 
	{
		bestP = (c >= W[n]) ? P[n] : 0;
	}
	else
	{
		if (c < W[n])//若装不下，则不装第n个物品
			bestP = ZeroOnePack_2(n-1, c);
		else //如果装得下，从装和不装两者中取最大值 
		    bestP = max(ZeroOnePack_2(n-1, c), ZeroOnePack_2(n-1, c-W[n]) + P[n]);
	}
	
    return B2[n][c] = bestP;//做备忘录 
}

int ZeroOnePack_3(int n, int c)//动态规划：二维数组存储记录，B3[i][j]初始化为0 
{
	//记录前i(1<=i<n)个物品装入容量为1-c的背包的最大价值 
 	for (int i=1; i<n; i++)
	{
		//for (int j=1; j<W[i]; j++)//背包容量不够，不能装下第i件物品 
//			B3[i][j] = B3[i-1][j];
//		for (int j=W[i]; j<=c; j++)//背包容量足够，可以选择装或不装第i件物品 
//			B3[i][j] = max(B3[i-1][j], B3[i-1][j-W[i]] + P[i]);
        for (int j=1; j<=c; j++)
		{
			B3[i][j] = B3[i-1][j]; //先分析不装第i个物品的情形 
			if (j >= W[i] && B3[i-1][j] < B3[i-1][j-W[i]] + P[i])
				B3[i][j] = B3[i-1][j-W[i]] + P[i];
		}
	}
	//因为每个物品最多只能装一次，故背包不一定能装满，则对于给定的n个物品来说，B[n][c]==B[n][j]，其中W[n]<=j<=c 
	//所以对第n个物品来说，只需直接计算B[n][c]，而不用考虑其他的容量j，这样可以减少计算量 
	if (c < W[n])
		B3[n][c] = B3[n-1][c]; 
	else 
		B3[n][c] = max(B3[n-1][c], B3[n-1][c-W[n]]+P[n]);
	
	return B3[n][c];
}

int ZeroOnePack_4(int n, int c)//优化的动态规划算法，使用2个一维数组代替二维数组，pre[j]和cur[j]均初始化为0 
{
	//pre[j]相当于ZeroOnePack_3()中的B3[i-1][j]，cur[j]相当于B3[i][j] 
	//为简化代码，没有把i==n的情形单独拿出来处理，若需要单独处理第n个物品，可参考ZeroOnePack_3()
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			if (j < W[i] || pre[j] > pre[j-W[i]] + P[i])
				cur[j] = pre[j]; 
			else
				cur[j] = pre[j-W[i]] + P[i];
		}
		for (int j=1; j<=c; j++)//复制上一行的数据到当前行 
		{
			pre[j] = cur[j]; 
		}
	}

	return cur[c];
}

int ZeroOnePack_5(int n, int c)//优化的动态规划算法，一维数组存储记录，F[j]初始化为0  
{
	//为简化代码，没有把i==n的情形单独拿出来处理，若需要单独处理第n个物品，可参考ZeroOnePack_3()
 	for (int i=1; i<=n; i++)
	{//须先求出列坐标j较大的F[j]，故让循环变量j的值从大到小递减
		for (int j=c; j>=W[i]; j--)
		{//当(j < W[i] || F[j] > F[j-W[i]] + P[i])时，F[j]的值不变
			if (F[j] < F[j-W[i]] + P[i])
				F[j] = F[j-W[i]] + P[i];
		}
	}
	
	return F[c];
}

int Show_3(int n, int c) //利用数组B3[][]，输出物品装载情况，并返回实际装载量，X[i]初始化为0 
{
	for (int i=n; i>0; i--)
	{
		if (B3[i][c] == B3[i-1][c-W[i]] + P[i])//装载了第i个物品 
		{
			X[i] = 1;
			c -= W[i];
		}
	}
	
	int s = 0;
	for (int i=1; i<=n; i++)
	{
		if (X[i])
		{
			s += W[i];
			cout << i << ": " << W[i] << " " << P[i] << endl;
		}
	}	
	return s;
} 

void Show(int i, int j)  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量
{
	if (i == 0)
		return;
		
	if (B3[i][j] == B3[i-1][j-W[i]] + P[i])//装载了第i个物品 
	{
		Show(i-1, j-W[i]);
		cout << i << ": " << W[i] << " " << P[i] << endl;
	}
	else //未装载第i个物品 
	{
		Show(i-1, j);
	}
} 


