/*
	Name: 动态规划专题之最长上升子序列
	Author: 巧若拙 
	Description: 1759_最长上升子序列
描述：一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。对于给定的一个序列(a1, a2, ..., aN)，
我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，这里1 <= i1 < i2 < ... < iK <= N。
比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。
这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8).

你的任务，就是对于给定的序列，求出最长上升子序列的长度。
输入
输入的第一行是序列的长度N (1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。
输出
最长上升子序列的长度
样例输入
7
1 7 3 5 9 4 8
样例输出
4

算法分析：
算法1：记忆化搜索。
用S[i]记录到元素i为止的最长上升子序列的长度，自顶向下，递归计算各子问题的解，逆序查找并返回满足条件的最长子序列的长度。 

算法2：与记忆化搜索相对应的动态规划算法，采用自底向上的思路，依次计算S[i]。 
若当前处理元素为A[i]，此时最长上升子序列应该按下列方法求出：
在A[0...i-1]中，找出一个比A[i]小且最长的上升子序列，作为A[i]的前驱。
我们用S[i]记录到元素i为止的最长上升子序列的长度。
为了提高搜索的效率，我们在寻找比A[i]小且最长的S[j]时，采用逆序查找的方法，这样能最快的找到S[j]。 

算法3：也是动态规划，但是处理的方向和算法2刚好相反。
若当前处理元素为A[i]，此时最长上升子序列应该按下列方法求出：
在A[i+1...n-1]中，找出一个比A[i]大且最长的上升子序列，作为A[i]的后继。
我们用S[i]记录到元素i为止的最长上升子序列的长度，注意这个长度是从后往前累计的。

算法4：算法3返回的不是最长上升子序列的长度，而是其第一个元素的下标，目的是为了方便输出该最长上升子序列，
我们可以在其基础上进行适当修改，输出该最长上升子序列。

算法5：不是动态规划，采用了二分插入的思想来维护一个元素值尽可能小的递增子序列，以确保能得到最长子序列。 
需要注意的是算法5虽然能够获得最长子序列的长度，但是不一定能获得正确的子序列。
因为它总是把后来遇到的较小元素来替换S[]中第一个比它大的元素。 
在算法2中，我们是在A[0...i-1]中，用线性扫描的方法查找最大的S[j]，这样总时间复杂度是O(n^2)。
注意到上升子序列是一个有序序列，我们可以用二分搜索的方法把时间复杂度降低到O(nlogn)。
与前面4个算法不同，算法5中S[i]记录的不是A[i]对应的子序列的长度，而是子序列本身（不一定是正确的子序列，但长度确实等于最大长度）。 
为了能获得更长的上升子序列，我们总是让S[k]的值尽可能小。
因此每遇到子序列长度相同，但是元素值更小的S[k]，我们就要将其插入到递增数组S[]中，覆盖原来的S[k]元素。 
设当前已经求出的最长上升子序列长度为m。先判断A[i]与S[m]。若A[i]>S[m]，则将A[i]接在S[m]后将得到一个更长的上升子序列，代码为S[++m] = A[i];
否则，在S[1...m]中，二分查找最大的j，满足S[j]<A[i]。令k=j+1，则有S[j]<A[i]<S[k]，令S[k]=A[i]，即得到新的上升子序列S，注意此时S的长度不变。
最后，数组S的长度m即为所要求的最长上升子序列的长度。
*/
#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 1001; 
int A[MAX];
int S1[MAX]; //记录到元素i为止的最长上升子序列的长度 
int S2[MAX]; //记录到元素i为止的最长上升子序列的长度 
int S3[MAX]; //记录到元素i为止的最长上升子序列的长度 
int S4[MAX]; //记录到元素i为止的最长上升子序列的长度 
int S5[MAX+1]; //记录最长上升子序列，下标从1开始 

int DP_1(int i); //记忆化搜索 
int DP_2(int n); //与记忆化搜索相对应的动态规划算法 
int DP_3(int n); //动态规划：逆序搜索，返回最长上升子序列第一个元素的下标 
int DP_4(int n); //动态规划：逆序搜索，返回最长上升子序列长度
int DP_5(int n); //顺序处理，二分插入 
int Pos(int low, int high, int x);//二分查找，返回第一个比x大的元素下标 
void Print(int len, int i);//递归输出子序列 
void Print2(int n); //输出序列 
void Print3(int n); //输出序列 

int main() 
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> A[i];
	}
		
	int maxLen = DP_1(n-1);//记忆化搜索，需要用到全局变量A[MAX]，另有S1[MAX]初始化为0。
	for (int i=n-2; i>=0; i--)//递减比递增效率应该要高些 
	{
		if (maxLen < S1[i]) 
			maxLen = S1[i];
	} 
	cout << maxLen << endl;
	Print(maxLen, n-1);
	cout << endl;
	
	cout << DP_2(n) << endl;//顺序处理，需要用到全局变量A[MAX]，另有S2[MAX]初始化为0。
	
	int pos = DP_3(n);//逆序处理，返回最长上升子序列第一个元素的下标，需要用到全局变量A[MAX]，另有S3[MAX]初始化为0。 
	cout << S3[pos] << endl;
	Print2(n);
	Print3(n);
	
	cout << DP_4(n) << endl;//逆序处理，返回最长上升子序列长度,需要用到全局变量A[MAX]，另有S4[MAX]初始化为0。
 
	cout << DP_5(n) << endl;//顺序处理，二分插入，需要用到全局变量A[MAX]，另有S4[MAX]初始化为0。
 
    return 0;
}

int DP_1(int i) //记忆化搜索 
{
	if (S1[i] != 0) //若已记录子问题的解，直接返回该解 
		return S1[i];
	if (i == 0) //递归出口 
	{
		S1[i] = 1;
	}
	else
	{
		int len = 0;
		for (int j=i-1; j>=0; j--)
		{
			if (len < DP_1(j) && A[i] > A[j])//逆序查找满足条件的最长子序列的尾元素，并更新S1[i]的值  
				len = DP_1(j);
		}
		S1[i] = len + 1;
	}
	return S1[i];
}

int DP_2(int n) //与记忆化搜索相对应的动态规划算法 
{
	for (int i=0; i<n; i++)
	{ 
		int len = 0;
		for (int j=i-1; j>=0; j--)//逆序查找满足条件的最长子序列的尾元素，并更新S2[i]的值 
		{
			if (A[i] > A[j] && len < S2[j])
				len = S2[j];
		}
		S2[i] = len + 1;
	}
	
	int maxLen = S2[n-1]; //记录最长上升子序列的长度 
	for (int i=n-2; i>=0; i--)//递减比递增效率应该要高些 
	{
		if (maxLen < S2[i]) 
			maxLen = S2[i];
	}
	
	return maxLen;
}

int DP_3(int n) //动态规划：逆序搜索，返回最长上升子序列第一个元素的下标 
{
	int pos = n - 1; //记录最长上升子序列最后一个元素的下标 
	
	for (int i=n-1; i>=0; i--)
	{
		int len = 0; //记录A[i]的后继子序列的长度 
		for (int j=i+1; j<n; j++)//在A[i]后面的元素中查找最大的len 
		{
			if (A[j] > A[i] && S3[j] > len) //注意是上升，而不是不下降，不能写A[i] >= A[j] 
				len = S3[j];
		}
		S3[i] = len + 1; 
		
		if (S3[i] > S3[pos])//记录最长上升子序列第一个元素的下标 
			pos = i;
	}
	
	return pos;
}

int DP_4(int n) //逆序搜索，返回最长上升子序列长度 
{
	int maxLen = 0; //记录最长上升子序列的长度 
	
	for (int i=n-1; i>=0; i--)
	{
		for (int j=i+1; j<n; j++)//在A[i]后面的元素中查找最大的S4[j]
		{
			if (A[j] > A[i] && S4[j] > S4[i])
				S4[i] = S4[j];
		}
		S4[i]++; 
		if (maxLen < S4[i]) 
			maxLen = S4[i];
	}
	
	return maxLen;
}

int DP_5(int n) //顺序搜索，二分插入 
{
	int m = 0; //记录最长不下降子序列的长度 
	
	S5[++m] = A[0]; //下标从1开始 
	for (int i=1; i<n; i++)
	{
		if (A[i] > S5[m])//直接接在后面并使子序列长度增1 
		{
			S5[++m] = A[i];
		}
		else //二分查找，并插入到适当位置（第一个比A[i]大的元素） 
		{
			S5[Pos(1, m-1, A[i])] = A[i];
		}
	}
	
	return m;
}

int Pos(int low, int high, int x)//二分查找，返回第一个比x大的元素下标 
{
	int mid;
	
	while (low <= high)
	{
		mid = (low + high)/2;
		if (S5[mid] > x)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	return low;//此时S5[low] > x
}

void Print(int len, int i)//递归输出子序列 
{
	if (len == 0)
		return;
	while (S1[i] != len) //不能写S1[i]<len，因为有可能出现长度相同的子序列 
	{
		i--;
	}
	Print(len-1, i-1);
	cout << A[i] << " ";
}

void Print2(int n)
{
	int pos = DP_3(n);
	int len = S3[pos]; //子序列的长度 
	for (int i=pos; len>0; i++) //总共输出len个元素 
	{
		if (S3[i] == len)  
		{
			cout << A[i] << " ";
			len--;
		}
	}
	cout << endl;
}

void Print3(int n)
{
	int pos = DP_3(n);
	int i, j;
	for (i=pos; i<n;) //总共输出len个元素 
	{
		cout << A[i] << " ";
		for (j=i+1; j<n; j++)
		{
			if (S3[j] == S3[i]-1)
				break;
		}
		i = j;
	}
	cout << endl;
}

