/*
	Name: 编辑距离 
	Copyright: 
	Author: 
	Date: 21-06-18 14:11
	Description: 
设A和B是2个字符串。要用最少的字符操作将字符串A转换为字符串B。
这里所说的字符操作包括 (1)删除一个字符； (2)插入一个字符； (3)将一个字符改为另一个字符。
将字符串A变换为字符串B所用的最少字符操作数称为字符串A到B的编辑距离，记为 d(A,B)。
试设计一个有效算法，对任给的2 个字符串A和B，计算出它们的编辑距离d(A,B)。
Input
  输入的第一行是字符串A，文件的第二行是字符串B。
Output
  程序运行结束时，将编辑距离d(A,B)输出。
Sample Input
fxpimu
xwrs
Sample Output
5
*/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int INF = 2000;
const int N = 200;
int B[N+1][N+1];
int B1[N+1][N+1];
string X, Y; 

int LCSLength(int i, int j);//自顶向下的备忘录算法
int LCSLength_1(int n, int m);//动态规划 
void PrintLCS(int i, int j);

int main()
{  
    while (cin >> X >> Y)
    {
		for (int i=0; i<=N; i++)
			for (int j=0; j<=N; j++)
				B[i][j] = INF;
		
    	cout << LCSLength(X.length(), Y.length()) << endl;
    	
    	memset(B1, 0, sizeof(B1));
    	cout << LCSLength_1(X.length(), Y.length()) << endl;
    	PrintLCS(X.length(), Y.length());
	}
    
   
    return 0;  
}  

int LCSLength(int i, int j)//自顶向下的备忘录算法
{
	if (B[i][j] != INF)
		return B[i][j];
	
	if (i == 0) //字符串X的长度为0，插入j个字符 
		B[i][j] = j;
	else if (j == 0) //字符串Y的长度为0，删除i个字符 
		B[i][j] = i;
	else if (X[i-1] == Y[j-1])//两字符相同，无需编辑 
		B[i][j] = LCSLength(i-1, j-1);
	else  //两字符不同，从插入，删除和修改3个操作中挑选编辑距离最短的，再加1 
		B[i][j] = min(min(LCSLength(i-1, j), LCSLength(i, j-1)), LCSLength(i-1, j-1)) + 1;
 
	return B[i][j];
}

int LCSLength_1(int n, int m)//动态规划 
{
	for (int i=1; i<=n; i++)//字符串Y的长度为0，删除i个字符 
		B1[i][0] = i;
	for (int j=1; j<=m; j++)//字符串X的长度为0，插入j个字符 
		B1[0][j] = j;
		
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (X[i-1] == Y[j-1])
				B1[i][j] = B1[i-1][j-1];
			else
				B1[i][j] = min(min(B1[i-1][j], B1[i][j-1]), B1[i-1][j-1]) + 1;
		}
	}
 
	return B1[n][m];
}

void PrintLCS(int i, int j)//竟然不正确，不知为何？ 
{
    if (i == 0 || j == 0)
        return;
    if (X[i-1] == Y[j-1])
    {
        PrintLCS(i-1, j-1);
        cout << "不变：" << "X[" << i << "]= " << X[i-1] << endl;
    }
    else if(B[i][j] == B[i-1][j-1]+1)
    {
		PrintLCS(i-1, j-1);
		cout << "修改：x[" << i << "]= " << X[i-1] << " : "<< "y[" << j << "]= " << Y[j-1] << endl;
    } 
    else if(B[i][j] == B[i-1][j]+1)//插入字符 
    {
		PrintLCS(i-1, j);
		cout << "插入：" << "y[" << j << "]= " << Y[j-1] << endl;
    }
    else //删除字符 
    {
		PrintLCS(i, j-1);
		cout << "删除：" << "X[" << i << "]= " << X[i-1] << endl;
    } 
}

