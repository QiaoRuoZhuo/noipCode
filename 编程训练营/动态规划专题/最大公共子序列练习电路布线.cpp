/*
  Name: 电路布线
  Author:巧若拙 
  Description: 电路布线
【问题描述】
在一块电路板的上、下两端分别有n个接线柱。根据电路设计，要求用导线（i，π(i)）将上端接线柱i与下端接线柱π(i)相连。
其中，π(i)，1<=i<=n是{1，2，…，n}的一个排列。导线（i，π(i)）称为该电路板上的第i条连线。对于任何1<=i π(j)。
在制作电路板时，要求将这n条连线分布到若干绝缘层上。在同一层上的连线不相交。
你的任务是要确定将哪些连线安排在第一层上，使得该层上有尽可能多的连线。
换句话说，就是确定导线集Nets={ i，π(i)，1<=i<=n}的最大不相交子集。
【输入形式】
输入文件第一行为整数n；第二行为用一个空格隔开的n个整数，表示π(i)。
【输出形式】
输出文件第一行为最多的连线数m，第2行到第m+1行输出这m条连线（i，π(i)）。
【输入样例】
10
1 8
2 7
3 4
4 2
5 5
6 1
7 9
8 3
9 10
10 6
【输出样例】
4

算法1：int MNS(int i, int j);//自顶向下的备忘录算法
设置一个备忘录数组s[N+1][N+1]，s[i][j]表示从上接线柱1-i发出的导线连接到下接线柱1-j，能生成的不相交导线的最大条数。 
利用原问题的递归关系，使用递归函数来求解。
状态方程：当i=1时，s[1][j] = (j<c[1]) ? 0 : 1;
当i>1时，若j<c[i]，则s[i][j] = s[i-1][j]; 否则s[i][j] = max(s[i-1][c[i]-1]+1, s[i-1][j]);

算法2：int MNS_2(int n);//自底向上的动态规划算法 
从i=1开始，依次记录每一个s[i][j]，最后获得最优解s[N][N]。

算法3：int MNS_3(int n);//优化的动态规划算法 
是对算法2的优化，算法2中用到的备忘录数组s[N+1][N+1]占空间较大，实际上下一行数据是利用上一行的数据生成的，
与更早的数据没有关系，于是可以用两个一维数组pre[N+1]和cur[N+1]代替s[N+1][N+1]。

算法32：int MNS_32(int n);//优化的动态规划算法 
是对算法3的优化，算法3中用两个一维数组pre[N+1]和cur[N+1]分别表示利用前(i-1)和i个上接线柱所能生成的最好结果，
仔细观察我们可以发现，cur[j]只与pre[c[i]-1]+1和pre[j]有关，故可以只用一个一维数组F[i]记录结果，
其中赋值前后的F[i]分别相当于pre[i]和cur[i]。 这样可以减少很多计算。 

最后写了一个函数void Traceback(int n); //输出满足条件的导线 
该函数需要用到备忘录数组s[N+1][N+1]，故只能对算法1和算法2产生的结果有效。 

算法4：与算法2相似，但思路更清晰明了的一种算法。算法的逻辑，与最长公共子序列很相似。 
设a[i][j]为上端接线柱i与下端接线柱j前的最大不相交子集，则：
若i与j相连，则a[i][j] = a[i-1][j-1] + 1 
若i与j不相连，则a[i][j] = max(a[i][j-1], a[i-1][j])
说明：算法2虽然代码更复杂，但是它做了分类判断，减少了很多不必要的计算，效率更高。  

算法5：对算法4的改进：分阶段讨论，避免不必要的计算。
与算法2相类似，对下端的接线柱j进行了分段讨论：分成j<c[i], j==c[i]和j>c[i]三个区间，分别求a[i][j]的值，效率更高。 

算法6：int MNS_4(int n);//将问题转化为求最长不下降序列
注意到电线上端的接线柱已经按顺序排列，问题可以转化为求数组c[N+1]的最长不下降序列 
*/
#include<iostream>
#include<string>

using namespace std;

int MNS(int i, int j);//自顶向下的备忘录算法
int MNS_2(int n);//自底向上的动态规划算法 
void Traceback_1(int n); //输出满足条件的导线 
void Traceback_2(int n); //输出满足条件的导线 
void Traceback_3(int n); //输出满足条件的导线 
int MNS_3(int n);//优化的动态规划算法 
int MNS_32(int n);//优化的动态规划算法 
int MNS_4(int n);//另一种思路的动态规划算法 
int MNS_5(int n);//对算法4的改进：分阶段讨论，避免不必要的计算 
int MNS_6(int n);//将问题转化为求最长不下降序列

const int N = 10;
//int c[N+1] = {0,8,7,4,2,5,1,9,3,10,6};
int c[N+1] = {0,2,8,1,9,3,5,10,6,7,4};
int s[N+1][N+1];
int a[N+1][N+1];
int b[N+1][N+1];
int pre[N+1]; //上一行记录
int cur[N+1]; //当前行记录 
int F[N+1];//表示从上接线柱1-i发出的导线生成的最好结果 
int S[N+1]; //记录到元素i为止的最长上升子序列的长度 

int main()
{  
    cout << MNS(N, N) << endl;
    cout << MNS_2(N) << endl;
    cout << MNS_3(N) << endl;
    cout << MNS_32(N) << endl;
    cout << MNS_4(N) << endl;
    cout << MNS_5(N) << endl;
    cout << MNS_6(N) << endl;
    Traceback_1(N);
    Traceback_2(N);
    Traceback_3(N);
    
    return 0;  
}  

int MNS(int i, int j)//自顶向下的备忘录算法 
{
 	if (s[i][j] > 0)
 	   return s[i][j];
 	   
    if (i == 1) //处理第一根导线 
    {
        s[i][j] = (j < c[i]) ? 0 : 1;
    }
    else
    {
	 	s[i][j] = MNS(i-1, j);
	 	if (j >= c[i] && MNS(i-1, c[i]-1)+1 > s[i][j])
	 	   s[i][j] = s[i-1][c[i]-1] + 1; //s[i-1][c[i]-1]在if语句中记录过了 
	}

	return s[i][j];
}

int MNS_2(int n)//自底向上的动态规划算法 
{
 	//先处理第一根导线
 	for (int j=1; j<c[1]; j++)
 		s[1][j] = 0;
    for (int j=c[1]; j<=n; j++)
 		s[1][j] = 1;
 	//然后处理中间的导线	
    for (int i=2; i<n; i++)
    {
	 	for (int j=1; j<c[i]; j++)
	 	{
 			s[i][j] = s[i-1][j];
		}
		for (int j=c[i]; j<=n; j++)
		{
 			s[i][j] = (s[i-1][c[i]-1]+1 > s[i-1][j]) ? s[i-1][c[i]-1]+1 : s[i-1][j]; 
		}
		
	}
	
	//再处理最后一根导线
	s[n][n] = (s[n-1][c[n]-1]+1 > s[n-1][n]) ? s[n-1][c[n]-1]+1 : s[n-1][n]; 
	return s[n][n];
}

void Traceback_1(int n) //输出满足条件的导线 
{
    int j = n;
    for (int i=n; i>1; i--)
    {
	 	if (s[i][j] > s[i-1][j])
	 	{
			cout << i << " - " << c[i] << endl;
            j = c[i] - 1;
        }
	}
	if (j >= c[1])
	{
        cout << 1 << " - " << c[1] << endl;
    }
}

void Traceback_2(int n) //输出满足条件的导线 
{
    int j = n;
    for (int i=n; i>1; i--)
    {
	 	if (a[i][j] > a[i-1][j])
	 	{
			cout << i << " - " << c[i] << endl;
            j = c[i] - 1;
        }
	}
	if (j >= c[1])
	{
        cout << 1 << " - " << c[1] << endl;
    }
}

void Traceback_3(int n) //输出满足条件的导线 
{
    int j = n;
    for (int i=n; i>1; i--)
    {
	 	if (b[i][j] > b[i-1][j])
	 	{
			cout << i << " - " << c[i] << endl;
            j = c[i] - 1;
        }
	}
	if (j >= c[1])
	{
        cout << 1 << " - " << c[1] << endl;
    }
}

int MNS_3(int n)//优化的动态规划算法 
{
 	//先处理第一根导线
 	for (int j=1; j<c[1]; j++)
 		pre[j] = 0;
    for (int j=c[1]; j<=n; j++)
 		pre[j] = 1;
 	//然后处理中间的导线	
    for (int i=2; i<n; i++)
    {   //处理当前行cur 
	 	for (int j=1; j<c[i]; j++)
	 	{
 			cur[j] = pre[j];
		}
		for (int j=c[i]; j<=n; j++)
		{
 			cur[j] = (pre[c[i]-1]+1 > pre[j]) ? pre[c[i]-1]+1 : pre[j];
		}
		//复制当前行信息cur到pre 
		for (int j=1; j<=n; j++)
	 	{
 			pre[j] = cur[j];
		} 
	} 
	//再处理最后一根导线
	cur[n] = (pre[c[n]-1]+1 > pre[n]) ? pre[c[n]-1]+1 : pre[n];
	return cur[n];
}

int MNS_32(int n)//优化的动态规划算法，使用一个一维数组来记录结果 
{
 	//先处理第一根导线（F[i]默认均为0) 
    for (int j=c[1]; j<=n; j++)
 		F[j] = 1;
 	//然后处理中间的导线	
    for (int i=2; i<n; i++)
    {   //处理当前行，赋值前后的F[i]分别相当于pre[i]和cur[i]
		for (int j=c[i]; j<=n; j++)
		{
			if (F[j] < F[c[i]-1]+1)
 				F[j] = F[c[i]-1]+1;
		}
	} 
	//再处理最后一根导线
	if (F[n] < F[c[n]-1]+1)
 		F[n] = F[c[n]-1]+1;
	return F[n];
}

int MNS_4(int n)//另一种思路的动态规划算法，与最长公共子序列很相似 
{
    for (int i=1; i<=n; i++)
    {
	 	for (int j=1; j<=n; j++)
	 	{
			if (j == c[i])
 				a[i][j] = a[i-1][j-1] + 1;
 			else
 				a[i][j] = max(a[i-1][j], a[i][j-1]);
		}
	}
	
	return a[n][n];
}

int MNS_5(int n)//对算法4的改进：分阶段讨论，避免不必要的计算 
{
    for (int i=1; i<=n; i++)
    {
		for (int j=1; j<c[i]; j++)//在接线柱c[i]的左侧区域，最优解与不包含接线柱i的一致 
	 	{
			b[i][j] = b[i-1][j];
		}
		
		b[i][c[i]] = b[i-1][c[i]-1] + 1;
		
	 	for (int j=c[i]+1; j<=n; j++)//在接线柱c[i]的右侧区域，最优解可能包含接线柱i，也可能不包含i 
	 	{
			b[i][j] = max(b[i-1][j], b[i][j-1]);
		}
	}
	
	return a[n][n];
}

int MNS_6(int n)//将问题转化为求最长不下降序列
{
	S[1] = 1; //默认到元素i为止的最长上升子序列的长度为1 
	for (int i=2; i<=n; i++)
	{
		int m = 0;
		for (int j=i-1; j>0; j--)//逆序查找不大于A[i]，且最长的元素
		{
			if (c[i] > c[j] && S[j] > m)
			{
				m = S[j];
			}
		}
		S[i] = m + 1;
	}
	int len = S[n]; 
	for (int i=n-1; i>0; i--)
	{
		if (S[i] > len)
		{
			len = S[i];
		}
	}
	
	return len;
}
