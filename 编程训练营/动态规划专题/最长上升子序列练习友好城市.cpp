/*
	Name: 友好城市
	Author:巧若拙 
	Description: 友好城市 
【问题描述】 
　　Palmia国有一条横贯东西的大河，河有笔直的南北两岸，岸上各有位置各不相同的N个城市。
北岸的每个城市有且仅有一个友好城市在南岸，而且不同城市的友好城市不相同。 
　　每对友好城市都向政府申请在河上开辟一条直线航道连接两个城市，但是由于河上雾太大，政府决定避免任意两条航道交叉，以避免事故。
编程帮助政府做出一些批准和拒绝申请的决定，使得在保证任意两条航线不相交的情况下，被批准的申请尽量多。 
【输入格式】 
　　第1行，一个整数N(1<=N<=5000)，表示城市数。 
　　第2行到第n+1行，每行两个整数，中间用1个空格隔开，分别表示南岸和北岸的一对友好城市的坐标。(0<=xi<=10000) 
【输出格式】 
　　仅一行，输出一个整数，政府所能批准的最多申请数。 
【输入样例】 
　　7 
　　22 4 
　　2 6 
　　10 3 
　　15 12 
　　9 8 
　　17 17 
　　4 2 
【输出样例】 
　　4

算法分析： 
首先可以把一边河岸排一下序。于是样例就变成了这样：
南岸 北岸
2	6
4	2
9	8
10	3
15	12
17	17
22	4
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct num{
    int a;
    int b;
};

bool compare(const num &x,const num &y)
{
    return (x.a <= y.a);
}

const int MAX = 5001; 
struct num A[MAX];//分别存储南北岸友好城市的坐标 
int S2[MAX]; //记录到元素i为止的最长上升子序列的长度 

int DP_2(int n); //顺序处理 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i].a >> A[i].b;
	}
	
	sort(A, A+n, compare);//先对南岸城市排序 
	
	cout << DP_2(n) << endl;//顺序处理，获得最长上升子序列 
	
    return 0;
}

int DP_2(int n) //顺序搜索 
{
	int maxLen = 0; //记录最长上升子序列的长度 
	
	for (int i=0; i<n; i++)
	{ 
		for (int j=i-1; j>=0; j--)//逆序查找不大于A[i]，且最长的元素，找到后更新S[i]的值
		{
			if (A[i].b > A[j].b && S2[j] > S2[i])
				S2[i] = S2[j];
		}
		S2[i]++; //因为S[i]初始化为0，故长度应增1 
		if (maxLen < S2[i]) 
			maxLen = S2[i];
	}
	
	return maxLen;
}
