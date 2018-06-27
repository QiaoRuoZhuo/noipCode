/*
	Name: 3546_矩阵链乘法
	Author: 巧若拙 
	Description: 
题目描述 Description
给定有n个要相乘的矩阵构成的序列（链）<A1,A2,A3,.......,An>，要计算乘积A1A2.....An。一组矩阵是加全部括号的。
矩阵链加括号对运算的性能有很大影响。
仅当两个矩阵A和B相容（即A的列数等于B的行数），才可以进行相乘运算。如果A是一个p×q矩阵，B是q×r矩阵，结果C是p×r的矩阵。
计算C的时间由乘法运算次数决定的，次数为p×q×r。
矩阵链乘法问题可表述为：给定n个矩阵构成的一个链<A1，A2，A3.......，An>，其中i=1,2,3,4.....,n，矩阵Ai的维数为Pi-1 ×Pi，
对乘积A1A2A3.....An，以一种最小标量乘法次数的方式进行加全部括号。
输入描述 Input Description
如果有n个数组，则第一行输入n+1个整数值
输出描述 Output Description
所有的数组以一种最小标量乘法次数的方式进行加全部括号。
样例输入 Sample Input
1 2 3 4 
样例输出 Sample Output
((A1A2)A3)
数据范围及提示 Data Size & Hint
n<=100  1<=Ai<=50
*/
#include<iostream>

using namespace std;

const int INT_MAX = 2147483647;
const int MAX = 100;

int P[MAX+1];//P[i-1]和P[i]分别记录了矩阵A[i]的行数和列数 
int B[MAX+1][MAX+1];//记录第i个矩阵至第j个矩阵的最优解
int S[MAX+1][MAX+1];//记录从哪里断开的才可得到矩阵的最优解
bool flag[MAX+1]; //记录A[i]是否已经被输出过 

int MatrixChain(int i, int j);//自顶向下，使用备忘录数组的动态规划算法  
int MatrixChain_2(int n);//自底向上的动态规划算法：递增括号中矩阵数量 
int MatrixChain_3(int n);//自底向上的动态规划算法：逆序扫描  
int MatrixChain_4(int n);//自底向上的动态规划算法：顺序扫描  
void Traceback(int i,int j);//根据s[][]记录的各个子段的最优解，将其输出

int main()
{
	int n = 0;
	while (cin >> P[n])
		n++;
    n--;
   // MatrixChain(1, n);//自顶向下，使用备忘录数组的动态规划算法 
    MatrixChain_4(n);//自底向上的动态规划算法 
    Traceback(1, n);
    cout << endl;
    
    return 0;
}

int MatrixChain(int i, int j)//自顶向下，使用备忘录数组的动态规划算法  
{
 	if (B[i][j] != 0) //默认为0
        return B[i][j];
	if (i == j)
		return 0;
	int t, m = INT_MAX;
	for (int k=i; k<j; k++)
	{
	 	t = MatrixChain(i, k) + MatrixChain(k+1, j) + P[i-1] * P[k] * P[j];
	 	if (t < m)
	 	{
	        m = t;
	        S[i][j] = k;
        }
	} 
	return B[i][j] = m;
}

int MatrixChain_2(int n)//自底向上的动态规划算法：递增括号中矩阵数量  
{
	for (int len=2; len<=n; len++)//括号里矩阵的数量（长度）
	{
	 	for (int i=1; i<=n-len+1; i++)
	 	{
		 	int j = i + len - 1;
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]初始化为0 
			{
			 	t = B[i][k] + B[k+1][j] + P[i-1] * P[k] * P[j];
			 	if (t < m)
			 	{
			        m = t;
			        S[i][j] = k;
		        }
			} 
			B[i][j] = m;
		}
	}
	
	return B[1][n];
}

int MatrixChain_3(int n)//自底向上的动态规划算法：逆序扫描  
{
	for (int i=n-1; i>0; i--)//左边界 
	{
	 	for (int j=i+1; j<=n; j++)//右边界 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]初始化为0 
			{
			 	t = B[i][k] + B[k+1][j] + P[i-1] * P[k] * P[j];
			 	if (t < m)
			 	{
			        m = t;
			        S[i][j] = k;
		        }
			} 
			B[i][j] = m;
		}
	}
	
	return B[1][n];
}

int MatrixChain_4(int n)//自底向上的动态规划算法：顺序扫描  
{
	for (int j=2; j<=n; j++)//右边界 
	{
	 	for (int i=j-1; i>0; i--)//左边界 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]初始化为0 
			{
			 	t = B[i][k] + B[k+1][j] + P[i-1] * P[k] * P[j];
			 	if (t < m)
			 	{
			        m = t;
			        S[i][j] = k;
		        }
			} 
			B[i][j] = m;
		}
	}
	
	return B[1][n];
}

void Traceback(int i,int j)//根据s[][]记录的各个子段的最优解，将其输出
{
    if (i == j)
	   return ;
    
    cout << "(";
    Traceback(i, S[i][j]);
    if (flag[i] == 0)
    {
        cout << "A" << i;
        flag[i] = 1;
    }
    Traceback(S[i][j]+1, j);
    if (flag[j] == 0)
    {
        cout << "A" << j;
        flag[j] = 1;
    }
    cout << ")";
}
