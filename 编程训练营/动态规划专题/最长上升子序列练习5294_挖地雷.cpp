/*
	Name: 数塔问题练习5294_挖地雷
	Author: 巧若拙 
	Description:5294_挖地雷
题目描述 Description
在一个地图上有N个地窖（N<=20），每个地窖中埋有一定数量的地雷。同时，给出地窖之间的连接路径。
当地窖及其连接的数据给出之后，某人可以从第一个地窖开始挖地雷，然后可以沿着指出的连接往下挖（仅能选择一条路径），当无连接时挖地雷工作结束。
设计一个挖地雷的方案，使某人能挖到最多的地雷。

输入描述 Input Description
第1行只有一个数字，表示地窖的个数N。
第2行有N个数，分别表示每个地窖中的地雷个数。
第3行至第N+1行表示地窖之间的连接情况：
第3行有n-1个数（0或1），表示第一个地窖至第2个、第3个、…、第n个地窖有否路径连接。
如第3行为1 1 0 0 0 … 0，则表示第1个地窖至第2个地窖有路径，至第3个地窖有路径，至第4个地窖、第5个、…、第n个地窖没有路径。
第4行有n-2个数，表示第二个地窖至第3个、第4个、…、第n个地窖有否路径连接。
… …
第n+1行有1个数，表示第n-1个地窖至第n个地窖有否路径连接。（为0表示没有路径，为1表示有路径）。

输出描述 Output Description
第一行表示挖得最多地雷时的挖地雷的顺序，各地窖序号间以一个空格分隔，不得有多余的空格。
第二行只有一个数，表示能挖到的最多地雷数。

样例输入 Sample Input
5
10 8 4 7 6
1 1 1 0
0 0 0
1 1
1
样例输出 Sample Output
1 3 4 5
27
*/
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int MAX = 20;   
int map[MAX+1][MAX+1];  
int W[MAX+1]; //记录每个地窖中的地雷个数
int F[MAX+1]; //记录从第i个地窖开始最多可以挖出的地雷数 
int F2[MAX+1]; //记录从第i个地窖开始最多可以挖出的地雷数
int next[MAX+1]; //记录地窖i的后续地窖编号 
  
int DP(int n); //动态规划（逆推法）
void PrintPath(int pos); //输出最佳路径
int DP_2(int n, int i); //备忘录算法
  
int main()   
{  
    int n;  
    cin >> n;  
    for (int i=1; i<=n; i++)  
    {  
        cin >> W[i];
    }  
    
    for (int i=1; i<n; i++)  
    {  
        for (int j=i+1; j<=n; j++)  
        {  
            cin >> map[i][j];  
        }  
    } 
    
    //动态规划算法 
	int pos = DP(n);  
    PrintPath(pos); //输出最佳路径
    cout << F[pos] << endl;
    
    //备忘录算法
	pos = n;  
	F2[n] = W[n];
	for (int i=1; i<n; i++)//因为入口有多个，必须一一计算 
    {  
        if (F2[pos] < DP_2(n, i))
        	pos = i;
    } 
    PrintPath(pos); //输出最佳路径
    cout << F2[pos] << endl; 
      
    return 0;  
}  

int DP(int n) //动态规划（逆推法），返回最佳起点下标 
{  
    F[n] = W[n];
	for (int i=n-1; i>0; i--)
	{
		for (int j=i+1; j<=n; j++)//寻找最佳路径 
		{
			if (map[i][j] && F[i] < F[j])
			{
				F[i] = F[j];
				next[i] = j;
			}
		}
		F[i] += W[i];
	} 
	
	int m = n;
	for (int i=1; i<n; i++)//找到最佳起点下标 
    {  
        if (F[i] > F[m])
            m = i;
    }  
    
    return m;
} 
int DP_2(int n, int i) //备忘录算法 
{  
    if (F2[i] != 0)
    	return F2[i];
    
    if (i == n)
    {
		F2[i] = W[n];
	}
	else
	{
		int t, m = 0;
		for (int j=i+1; j<=n; j++)
		{
			if (map[i][j])
			{
				t = DP_2(n, j);
				if (m < t)
				{
					m = t;
					next[i] = j;
				}
			}
		}
		F2[i] = m + W[i];
	}
    
    return F2[i];
} 

void PrintPath(int pos) //输出最佳路径 
{  
	cout << pos;
    for(pos=next[pos]; pos!=0; pos=next[pos])
    {
		cout << " " << pos;
	}
    cout << endl;
}  

