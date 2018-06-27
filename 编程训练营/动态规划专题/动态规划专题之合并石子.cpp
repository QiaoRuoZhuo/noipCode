/*
	Name: 动态规划专题之石子合并
	Author: 巧若拙 
	Description: 
在一个操场上摆放着一排N堆石子。现要将石子有次序地合并成一堆。规定每次只能选相邻的2堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的得分。
试设计一个算法，计算出将N堆石子合并成一堆的最小得分。
输入描述 Input Description
第一行是一个数N。1≤N≤100
以下N行每行一个数A，表示石子数目。1≤A≤200
输出描述 Output Description
共一个数，即N堆石子合并成一堆的最小得分。
样例输入 Sample Input
7
13 7 8 16 21 4 18
样例输出 Sample Output
239
*/
#include<iostream>

using namespace std;

const int INT_MAX = 2147483647;
const int MAX = 1000;

int A[MAX+1];//记录每堆石子的数量 
int Sum[MAX+1];//记录前n堆石子的数量 
int B[MAX+1][MAX+1];//记录第i个矩阵至第j个矩阵的最优解
int S[MAX+1][MAX+1];//记录从哪里断开的才可得到矩阵的最优解
bool flag[MAX+1]; //记录A[i]是否已经被输出过 

int StonesCombined(int i, int j);//自顶向下，使用备忘录数组的动态规划算法  
int StonesCombined_2(int n);//自底向上的动态规划算法：递增括号中石子堆数量 
int StonesCombined_3(int n);//自底向上的动态规划算法：逆序扫描  
int StonesCombined_4(int n);//自底向上的动态规划算法：顺序扫描  
void Traceback(int i, int j);//根据s[][]记录的各个子段的最优解，将其输出

int main()
{
	int n = 0;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> A[i];
		Sum[i] = Sum[i-1] + A[i];
	}
		
  // cout << StonesCombined(1, n) << endl;//自顶向下，使用备忘录数组的动态规划算法 
    cout << StonesCombined_2(n) << endl;//自底向上的动态规划算法 
    Traceback(1, n);
    cout << endl;
    
    return 0;
}

int StonesCombined(int i, int j)//自顶向下，使用备忘录数组的动态规划算法  
{
 	if (B[i][j] != 0) //默认为0
        return B[i][j];
	if (i == j)
		return 0;
	int t, m = INT_MAX;
	for (int k=i; k<j; k++)
	{
	 	t = StonesCombined(i, k) + StonesCombined(k+1, j) + Sum[j] - Sum[i-1];
	 	if (t < m)
	 	{
	        m = t;
	        S[i][j] = k;
        }
	} 
	return B[i][j] = m;
}

int StonesCombined_2(int n)//自底向上的动态规划算法：递增括号中石子堆数量  
{
	for (int len=2; len<=n; len++)//括号里矩阵的数量（长度）
	{
	 	for (int i=1; i<=n-len+1; i++)//左边界 
	 	{
		 	int j = i + len - 1; //右边界 
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]初始化为0 
			{
			 	t = B[i][k] + B[k+1][j] + Sum[j] - Sum[i-1];
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

int StonesCombined_3(int n)//自底向上的动态规划算法：逆序扫描  
{
	for (int i=n-1; i>0; i--)//左边界 
	{
	 	for (int j=i+1; j<=n; j++)//右边界 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]初始化为0 
			{
			 	t = B[i][k] + B[k+1][j] + Sum[j] - Sum[i-1];
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

int StonesCombined_4(int n)//自底向上的动态规划算法：顺序扫描  
{
	for (int j=2; j<=n; j++)//右边界 
	{
	 	for (int i=j-1; i>0; i--)//左边界 
	 	{
		 	int t, m = INT_MAX;
		 	for (int k=i; k<j; k++)//B[i][i]初始化为0 
			{
			 	t = B[i][k] + B[k+1][j] + Sum[j] - Sum[i-1];
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
        cout << A[i] << " ";
        flag[i] = 1;
    }
    Traceback(S[i][j]+1, j);
    if (flag[j] == 0)
    {
        cout << A[j];
        flag[j] = 1;
    }
    cout << ")";
}
