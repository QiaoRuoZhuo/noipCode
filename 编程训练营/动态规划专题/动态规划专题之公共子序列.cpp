/*
	Name: 1808_公共子序列
	Copyright: 
	Author: 
	Date: 21-06-18 09:25
	Description: 1808_公共子序列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
我们称序列Z = < z1, z2, ..., zk >是序列X = < x1, x2, ..., xm >的子序列当且仅当存在 严格上升 的序列< i1, i2, ..., ik >，使得对j = 1, 2, ... ,k, 有xij = zj。比如Z = < a, b, f, c > 是X = < a, b, c, f, b, c >的子序列。

现在给出两个序列X和Y，你的任务是找到X和Y的最大公共子序列，也就是说要找到一个最长的序列Z，使得Z既是X的子序列也是Y的子序列。
输入
输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。
输出
对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。
样例输入
abcfbc         abfcab
programming    contest 
abcd           mnp
样例输出
4
2
0
*/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int N = 200;
int B[N+1][N+1];
int B1[N+1][N+1];
int pre[N+1]; //pre[j]相当于B1[i-1][j]   
int cur[N+1]; //cur[j]相当于B1[i][j] 
string X, Y; 

int LCSLength(int i, int j);//自顶向下的备忘录算法
int LCSLength_1(int n, int m);//动态规划 
int LCSLength_2(int n, int m);//动态规划 
void PrintLCS(int i, int j);

int main()
{  
    while (cin >> X >> Y)
    {
		memset(B, 0, sizeof(B));
		memset(pre, 0, sizeof(pre));
    	cout << LCSLength(X.length(), Y.length()) << endl;
    	cout << LCSLength_1(X.length(), Y.length()) << endl;
    	cout << LCSLength_2(X.length(), Y.length()) << endl;
    	PrintLCS(X.length(), Y.length());
	}
    
   
    return 0;  
}  

int LCSLength(int i, int j)//自顶向下的备忘录算法
{
	if (B[i][j] != 0)
		return B[i][j];
	
	if (i == 0 || j == 0) 
		B[i][j] = 0;
	else if (X[i-1] == Y[j-1])
		B[i][j] = LCSLength(i-1, j-1) + 1;
	else
		B[i][j] = max(LCSLength(i-1, j), LCSLength(i, j-1));
 
	return B[i][j];
}

int LCSLength_1(int n, int m)//动态规划 
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (X[i-1] == Y[j-1])
				B1[i][j] = B1[i-1][j-1] + 1;
			else
				B1[i][j] = max(B1[i-1][j], B1[i][j-1]);
		}
	}
 
	return B1[n][m];
}

int LCSLength_2(int n, int m)//优化的动态规划算法，用2个一维数组代替二维数组  
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (X[i-1] == Y[j-1])
				cur[j] = pre[j-1] + 1;
			else
				cur[j] = max(pre[j], cur[j-1]);
		}
		for (int j=1; j<=m; j++)
		{
			pre[j] = cur[j];
		}
	}
 
	return pre[m];
}


void PrintLCS(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (X[i-1] == Y[j-1])
    {
        PrintLCS(i-1, j-1);
        cout << "x[" << i-1 << "]= " << X[i-1] << " : "<< "y[" << j-1 << "]= " << Y[j-1] << endl;
    }
    else if(B[i-1][j] > B[i][j-1])//先向上层走 
        PrintLCS(i-1, j);
    else                          //再向左边走 
        PrintLCS(i, j-1);
}
