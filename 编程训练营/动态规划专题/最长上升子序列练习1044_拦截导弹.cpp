/*
	Name: 1044_拦截导弹
	Author: 巧若拙 
	Description: 1044_拦截导弹  1999年NOIP全国联赛提高组
题目描述 Description
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。
但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入描述 Input Description
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）
输出描述 Output Description
输出这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

样例输入 Sample Input
389 207 155 300 299 170 158 65 
样例输出 Sample Output
6(最多拦截导弹数)
2（要拦截所有导弹最少要配备的系统数）

数据范围及提示 Data Size & Hint
导弹的高度<=30000，导弹个数<=20
分析：
第一问很简单，就是求最长不上升子序列，第二问用贪心的方法来做，
*/
#include <iostream>

using namespace std;

const int MAX = 20; 
int A[MAX];
int S[MAX]; //记录到元素i为止的最长上升子序列的长度 
int H[MAX]; //记录第k套系统的最小拦截高度 

void DP(int n); //顺序查找 

int main() 
{
	int n = 0;
	while (cin >> A[n])
	{
		n++;
	}
	
	DP(n);
	
    return 0;
}

void DP(int n) //顺序查找 
{
	int ans1 = 1;  
	
	for (int i=0; i<n; i++)
	{
		for (int j=i-1; j>=0; j--)//逆序查找不大于A[i]，且最长的元素，找到后更新S[i]和m的值
		{
			if (A[i] <= A[j] && S[j] > S[i])
			{
				S[i] = S[j];
			}
		}
		S[i]++;
		if (S[i] > ans1) 
			ans1 = S[i];
	}
	
	//贪心法求系统数量
	int ans2 = 1, k = 0; 
	H[0] = A[0];
	for (int i=1; i<n; i++)
	{
		//贪心法求系统数量，每次都用拦截高度最小的那套来拦截，若超出已有系统的最小高度，则增加一套新的系统
		for (k=0; k<ans2; k++)//ans2表示目前系统的总数量，H[k]表示第k套系统的最小拦截高度，k越小，该系统的最小拦截高度越低 
		{
			if (H[k] >= A[i]) //更新第k套系统的最小拦截高度
			{
				H[k] = A[i];
				break;
			}	
		}
		
		if (k == ans2) //若超出已有系统的最小高度，则增加一套新的系统，初始化其最小拦截高度为A[i] 
			H[ans2++] = A[i];
	}
	cout << ans1 << endl << ans2 << endl ;
}

