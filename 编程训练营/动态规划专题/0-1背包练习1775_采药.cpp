/*
	Name: 1775_采药
	Author: 巧若拙 
	Description: 
辰辰是个很有潜能、天资聪颖的孩子，他的梦想是称为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。
医师为了判断他的资质，给他出了一个难题。医师把他带到个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同的草药，
采每一株都需要一些时间，每一株也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，
你应该可以让采到的草药的总价值最大。”

如果你是辰辰，你能完成这个任务吗？
输入
输入的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），T代表总共能够用来采药的时间，M代表山洞里的草药的数目。
接下来的M行每行包括两个在1到100之间（包括1和100）的的整数，分别表示采摘某株草药的时间和这株草药的价值。
输出
输出只包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。
样例输入
70 3
71 100
69 1
1 2
样例输出
3
算法分析：这是一个典型的0-1背包问题，可设采药的时间相当于物品的重量。
除了回溯算法会超时以外，其他算法均能AC。 
*/
#include<iostream>
#include<cstring>

using namespace std;

const int MAXC = 1000; //背包最大容量 
const int MAXN = 100; //物品的最大个数
int W[MAXN+1];//物品的重量 
int P[MAXN+1];//物品的价值 
int B2[MAXN+1][MAXC+1]; //备忘录，记录给定n个物品装入容量为c的背包的最大价值 
int B3[MAXN+1][MAXC+1]; //动态规划中记录给定i个物品装入容量为j的背包的最大价值 
int pre[MAXC+1]; //记录上一行元素值
int cur[MAXC+1]; //记录当前行元素值
int F[MAXC+1]; //动态规划中记录给定n个物品装入容量为j的背包的最大价值
int cw, cp;//在回溯算法中分别记录给定t个物品时，已装物品的总重量和总价值
int bestPrice; //在回溯算法中记录目前已知的最大总价值，初始化为0 

int Sum(int n, int t);//累计第t+1到n个物品的总价值
void ZeroOnePack_1(int n, int c, int t);//回溯算法求0-1背包问题 
int ZeroOnePack_2(int n, int c);//记忆化搜索（备忘录算法）求0-1背包问题 
int ZeroOnePack_3(int n, int c);//动态规划：二维数组存储记录
int ZeroOnePack_4(int n, int c);//优化的动态规划算法，使用2个一维数组代替二维数组
int ZeroOnePack_5(int n, int c);//优化的动态规划算法，一维数组存储记录

int main() 
{
	int n, c;
	cin >> c >> n;
	
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
	//记录前i(1<=i<n)个物品装入容量为0-c的背包的最大价值 
 	for (int i=1; i<n; i++)
	{
		for (int j=1; j<W[i]; j++)//背包容量不够，不能装下第i件物品 
			B3[i][j] = B3[i-1][j];
		for (int j=W[i]; j<=c; j++)//背包容量足够，可以选择装或不装第i件物品 
			B3[i][j] = max(B3[i-1][j], B3[i-1][j-W[i]] + P[i]);
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
	{//须先求出列坐标j较大的F5[j]，故让循环变量j的值从大到小递减
		for (int j=c; j>=W[i]; j--)
		{//当(j < W[i] || F[j] > F[j-W[i]] + P[i])时，F[j]的值不变
			if (F[j] < F[j-W[i]] + P[i])
				F[j] = F[j-W[i]] + P[i];
		}
	}
	
	return F[c];
}

