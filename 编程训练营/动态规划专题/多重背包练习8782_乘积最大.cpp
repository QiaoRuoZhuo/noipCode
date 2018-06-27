/*
	Name: 8782_乘积最大
	Copyright: 
	Author: 
	Date: 27-06-18 09:17
	Description: 8782_乘积最大
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
今年是国际数学联盟确定的“2000——世界数学年”，又恰逢我国著名数学家华罗庚先生诞辰90周年。在华罗庚先生的家乡江苏金坛，组织了一场别开生面的数学智力竞赛的活动，你的一个好朋友XZ也有幸得以参加。活动中，主持人给所有参加活动的选手出了这样一道题目：

设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，使得这K+1个部分的乘积能够为最大。

同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子：

有一个数字串：312，当N=3，K=1时会有以下两种分法：

1)  3*12=36

2)  31*2=62

这时，符合题目要求的结果是：31*2=62

现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。

输入
程序的输入共有两行：
第一行共有2个自然数N，K（6≤N≤40，1≤K≤6）
第二行是一个长度为N的数字串。
输出
输出所求得的最大乘积（一个自然数）。（保证最终答案不超过int范围）
样例输入
4 2
1231
样例输出
62
*/
#include<iostream>
#include<string>

using namespace std;

const int N = 10;
long long A[N+1][N+1]; //A[i][j]表示从第i位到第j位数字串所组成的自然数 
long long B1[N+1][N+1];//B[i][j]表示将i个乘号插入到前j位数字串中所得的最大值 
long long B2[N+1][N+1];
long long F[N+1];

long long MaxMul_1(int i, int j);//自顶向下的备忘录算法
long long MaxMul_2(int n, int m);//动态规划 
long long MaxMul_3(int n, int m);//动态规划：降维优化
void Show(int i, int j); //递归输出乘号分布情况  

int main()
{  
	int n, m;
	long long s;
	
	cin >> m >> n;//数字串长度和乘号数量 
	cin >> s;//数字串是一个很大的整数 
    
    for (int i=m; i>0; i--)//分离数位 
    {
		A[i][i] = s % 10;
		s /= 10;
	}
	//使用动态规划算法获取自然数A[i][j] 
    for (int i=m-1; i>0; i--) //左边界 
    {
		for (int j=i+1; j<=m; j++)//右边界 
		{
			A[i][j] = A[i][j-1] * 10 + A[j][j];
		}
	}
	
	cout << MaxMul_1(n, m) << endl;//自顶向下的备忘录算法
	cout << MaxMul_2(n, m) << endl;//自底向上的动态规划算法 
	cout << MaxMul_3(n, m) << endl;//动态规划：降维优化
	
	Show(n, m);//递归输出乘号分布情况  
   
    return 0;  
} 

long long MaxMul_1(int i, int j)//自顶向下的备忘录算法，只记录了需要的子问题解 
{
	if (B1[i][j] != 0)  
        return B1[i][j];  
    if (i == 0) //不加乘号  
        return A[1][j];  
        
    int bestP = 0;  
    for (int k=i; k<j; k++)  
    {  
        if (bestP < MaxMul_1(i-1, k) * A[k+1][j])  
            bestP = MaxMul_1(i-1, k) * A[k+1][j];  
    }  
      
    return B1[i][j] = bestP;   
}

long long MaxMul_2(int n, int m)//动态规划：类似多重背包的穷举算法 
{
	for (int j=1; j<=m; j++) //预处理不加乘号的情形
	 	B2[0][j] = A[1][j];
	 	
	for (int i=1; i<=n; i++)//给定i个乘号
	{
		for (int j=i+1; j<=m; j++) //给定长度为j的数字串
		{
			int bestP = 0;
			for (int k=i; k<j; k++) //第i个乘号放在第k个数字后面，即第i个乘号右侧的自然数为A[k+1][j]
			{
				if (bestP < B2[i-1][k] * A[k+1][j]) 
					bestP = B2[i-1][k] * A[k+1][j]; 
			} 
			B2[i][j] = bestP;
		} 
	} 
	
	return B2[n][m];
}

long long MaxMul_3(int n, int m)//动态规划：降维优化
{
	for (int j=1; j<=m; j++) //预处理不加乘号的情形
	 	F[j] = A[1][j];
	 	
	for (int i=1; i<=n; i++)//给定i个乘号
	{
		for (int j=m; j>i; j--) //给定长度为j的数字串
		{
			int bestP = 0;
			for (int k=i; k<j; k++) //第i个乘号放在第k个数字后面，即第i个乘号右侧的自然数为A[k+1][j]
			{
				if (bestP < F[k] * A[k+1][j]) 
					bestP = F[k] * A[k+1][j]; 
			} 
			F[j] = bestP;
		} 
	} 
	
	return F[m];
}

void Show(int i, int j)//递归输出乘号分布情况   
{  
    if (i == 0)  //没有乘号了，直接输出数字串 
    {
		cout << A[1][j];
		return;  
	}
    //因为B1[][]并未记录所有子问题解，故不能用它来递归输出乘号分布情况  
    for (int k=i; k<j; k++)//k递增或递减均可     
    {    
        if (B2[i][j] == B2[i-1][k] * A[k+1][j])//第i个乘号放在第k个数字后面，即第i个乘号右侧的自然数为A[k+1][j]  
        {  
            Show(i-1, k);  //i-1个乘号插入到长度为k的数字串中 
            cout << " * " << A[k+1][j];  
            break;  
        }  
    }  
}  
