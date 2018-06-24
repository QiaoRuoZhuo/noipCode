/*
	Name: 6049_买书
	Copyright: 
	Author: 
	Date: 24-06-18 15:23
	Description: 6049_买书
描述
小明手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。
问小明有多少种买书方案？（每种书可购买多本）
输入
一个整数 n，代表总共钱数。（0 <= n <= 1000）
输出
一个整数，代表选择方案种数
样例输入
样例输入1：
20
样例输入2：
15
样例输入3：
0
样例输出
样例输出1：
2
样例输出2：
0
样例输出3：
0 
*/
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int N = 1001; 
int A[5] = {0,10,20,50,100};   
long long F[N]; //备忘录，记录方案数量 

long long CompletePack_2(int n, int c); //将完全背包转化为0-1背包 
long long CompletePack_4(int n, int c);//优化的动态规划算法，一维数组存储记录 
  
int main()   
{  
    int n;  
      
    cin >> n; 
    cout << CompletePack_2(4, n) << endl;  
    
    return 0;  
} 

long long CompletePack_4(int n, int c)//进一步优化的动态规划算法，用1个一维数组代替二维数组
{
	F[0] = 1;
 	for (int i=1; i<=n; i++)
	{
		for (int j=A[i]; j<=c; j++) //j不比i小，能够形成新的方案 
		{
			F[j] += F[j-A[i]];
		}
	}
	
	return F[c];
} 

long long CompletePack_2(int n, int c) //将完全背包转化为0-1背包 
{
	F[0] = 1;
 	for (int i=1; i<=n; i++)
	{
		for (int j=c; j>=A[i]; j--) //将完全背包转化为0-1背包 
		{
			for (int k=j/A[i]; k>0; k--)
				F[j] += F[j-k*A[i]];
		}
	}
	
	return F[c];
}
