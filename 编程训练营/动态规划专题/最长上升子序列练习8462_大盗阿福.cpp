/*
	Name: 8462_大盗阿福
	Copyright: 
	Author: 
	Date: 26-06-18 21:40
	Description: 8462_大盗阿福
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
阿福是一名经验丰富的大盗。趁着月黑风高，阿福打算今晚洗劫一条街上的店铺。

这条街上一共有 N 家店铺，每家店中都有一些现金。阿福事先调查得知，只有当他同时洗劫了两家相邻的店铺时，街上的报警系统才会启动，然后警察就会蜂拥而至。

作为一向谨慎作案的大盗，阿福不愿意冒着被警察追捕的风险行窃。他想知道，在不惊动警察的情况下，他今晚最多可以得到多少现金？

输入
输入的第一行是一个整数 T (T <= 50) ，表示一共有 T 组数据。
接下来的每组数据，第一行是一个整数 N (1 <= N <= 100, 000) ，表示一共有 N 家店铺。第二行是 N 个被空格分开的正整数，表示每一家店铺中的现金数量。每家店铺中的现金数量均不超过 1000 。
输出
对于每组数据，输出一行。该行包含一个整数，表示阿福在不惊动警察的情况下可以得到的现金数量。
样例输入
2
3
1 8 2
4
10 7 6 14
样例输出
8
24
提示
对于第一组样例，阿福选择第 2 家店铺行窃，获得的现金数量为 8 。
对于第二组样例，阿福选择第 1 和 4 家店铺行窃，获得的现金数量为 10 + 14 = 24 。

算法分析：
算法1：与6045_开餐馆是同一类题目，相当于各店距离大于1 
算法2：算法1是直接套用了6045_开餐馆的代码，实际上本题比6045_开餐馆要简单些，代码可以更简洁。
算法3：仔细分析题意，可以得到一个类似斐波那契数列的算法 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
const int MAX = 100000; 
long long A[MAX+1]; //各点位置坐标 
long long P[MAX+1]; //各点餐馆利润 
long long B[MAX+1]; //B[i]表示给定前i家店铺的情况下的最优解（不一定抢劫第i家店）
long long B2[MAX+1]; //B2[i]表示给定前i家店铺的情况下的最优解（不一定抢劫第i家店）
long long B3[MAX+1]; //B3[i]表示必须抢劫第i家店铺的情况下的最优解 
 
long long DP_1(int n, int d);
long long DP_2(int n);
long long DP_3(int n);
 
int main() 
{
	int d = 1, n, t;
	cin >> t;
	for (int i=0; i<t; i++)
	{
		cin >> n;
		for (int j=1; j<=n; j++)
		{
			A[j] = j; //各店铺坐标 
			cin >> P[j];
		}
		//memset(B, 0, sizeof(B));
//		cout << DP_1(n, d) << endl;
//		memset(B2, 0, sizeof(B2));
//		cout << DP_2(n, d) << endl;
		memset(B3, 0, sizeof(B3));
		cout << DP_3(n) << endl;
	}
	
    return 0;
}
 
long long DP_1(int n, int d) //动态规划：直接套用了6045_开餐馆的代码
{
	B[1] = P[1]; //只在位置1开餐馆 
	for (int i=2; i<=n; i++)
	{
		B[i] = max(B[i-1], P[i]); //比较不在位置i开餐馆和只在位置i开餐馆的大小  
		for (int j=i-1; j>0; j--)//寻求利润最大的开餐馆方法 
		{
			if (A[i] - A[j] > d && B[i] < B[j]+P[i])//找到第一个满足条件的就可以跳出循环了 
			{
				B[i] = B[j]+P[i];
				break;
			}
		}
	}
	
	return B[n];
}

long long DP_2(int n) //动态规划：类似数塔问题 
{
	B2[1] = P[1]; //只抢劫第一家店 
	for (int i=2; i<=n; i++)
	{
		B2[i] = max(B2[i-1], B2[i-2]+P[i]);//B2[i]表示给定前i家店铺的情况下的最优解（不一定抢劫第i家店） 
	}
	
	return B2[n];
}

long long DP_3(int n) //动态规划：类似斐波那契数列
{
	int maxP = max(P[1], P[2]);
	B3[1] = P[1]; //只抢劫第1家店 
	B3[2] = P[2]; //只抢劫第2家店 
	for (int i=3; i<=n; i++)
	{
		B3[i] = max(B3[i-2], B3[i-3]) + P[i]; //B3[i]表示必须抢劫第i家店铺的情况下的最优解 
		if (maxP < B3[i]) //存储最优解 
			maxP = B3[i];
	}
	
	return maxP;
}
 
