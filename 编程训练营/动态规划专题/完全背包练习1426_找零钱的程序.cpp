/*
	Name: 1426_找零钱的程序
	Author: 巧若拙
	Description:
现在假设你是个店员,为了方便/准确/最优的找零钱,你设计了一个程序.该程序应该实现如下功能:
第一行输入客户所给你金额
第二行输入客户消费的总金额
第三行输出应找的总零钱是多少
第四行输出各种面额的张数(总金额之和要与第三行的数相等,并且要求货币总张数是最少的方案输出)

注:为了简单,假设上述中的金额都是整数,现规定金额的面值为100,50,20,10,5,1元.并且假定客户的金额总是大于所需支付的总金额.

数据类型用int整数表示．
输入描述 Input Description
第一行输入一个整数(表示客户所付的金额),如100
第二行输入一个整数(表示商品的总计金额),如25

输出描述 Output Description
第一行输出 应找的零钱,如75
第二行输出 金额面值1*张数1+金额面值2+张数2+....+金额面值N*张数N=总零钱数:.(面值较大的零钱优先排在前面，如５０元比２０元大，应排在前面)

样例输入 Sample Input
样例输入1:
100
25
样例输入2:
95
2

样例输出 Sample Output
样例输出1:(面值较大的零钱优先排在前面)
75
50*1+20*1+5*1=75
样例输出2:(面值较大的零钱优先排在前面)
93
50*1+20*2+1*3=93 

算法思路：
典型的完全背包问题，可以用B2[i][j]表示给定i种货币表示j元的最少张数。
由于要输出具体的解，故应该用二维数组算法，记录每种货币使用的张数，然后使用递归算法，输出详解。 
*/
#include<iostream>
#include<cstring>

using namespace std;
  
const int MAXC = 10000; //找钱的最大数额 
const int MAXN = 6; //钞票的面值种类 
  
int A[MAXN+1] = {0,100,50,20,10,5,1};  
int B2[MAXN+1][MAXC+1]; //B2[i][j]表示给定i种货币表示j元的最少张数
  
int CompletePack_2(int n, int c);//动态规划:F[i][j] = min(F[i-1][j], F[i][j-A[i]] + 1)
void Show(int i, int j);  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量
  
int main()  
{  
    int m, n;  
      
    cin >> m >> n;
    cout << m - n << endl;
    memset(B2, MAXC, sizeof(B2));
	for (int i=0; i<=MAXN; i++)
		B2[i][0] = 0;
		
    CompletePack_2(MAXN, m - n); 
    Show(MAXN, m - n); 
    cout << '=' << m - n << endl;
      
    return 0;  
}  

int CompletePack_2(int n, int c)//动态规划:F[i][j] = min(F[i-1][j], F[i][j-A[i]] + 1)
{
 	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c; j++)
		{
			if (j < A[i] || B2[i-1][j] < B2[i][j-A[i]] + 1) 
				B2[i][j] = B2[i-1][j];
			else  //用了一张面值为A[i]的钞票 
				B2[i][j] = B2[i][j-A[i]] + 1;
		}
	}
	
	return B2[n][c];
}

void Show(int i, int j)  //i和j分别表示正在处理的第i个物品和此时背包的剩余容量
{
	if (j == 0 || i == 0)
		return;
	
	if (B2[i][j] == B2[i-1][j]) 
	{
		Show(i-1, j); //未装载第i个物品 
	}
	else
	{
		for (int k=j/A[i]; k>0; k--)
		{
			if (B2[i][j] == B2[i-1][j-k*A[i]] + k) //装载了k个物品i
			{
				if (j-k*A[i] > 0)
				{
					Show(i-1, j-k*A[i]);
					cout << '+';
				}
				cout <<	A[i] << '*' << k;
				return;
			}
		}
	}
} 
