/* 
  Name: 整数划分问题 
  CAuthor: 巧若拙  
  Description: 所谓整数划分，是指把一个正整数n写成如下形式： 
n=m1+m2+...+mi; （其中mi为正整数，并且1 <= mi <= n），则{m1,m2,...,mi}为n的一个划分。 
如果{m1,m2,...,mi}中的最大值不超过m，即max(m1,m2,...,mi)<=m，则称它属于n的一个m划分。 
这里我们记n的m划分的个数为f(n,m); 
 例如当n=4时，有5个划分，{4},{3,1},{2,2},{2,1,1},{1,1,1,1}; 
 注意4=1+3 和 4=3+1被认为是同一个划分。 
该问题是求出n的所有划分个数，即f(n, n)。

算法设计： 
 因为整数划分问题满足最优子结构和子问题重叠特征，故可以用动态规划算法来解。
 进一步仔细观察，就是一个完全背包问题，求所有可能的方案。 
*/  
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int N = 400;  
int F[N]; //备忘录，记录n的m划分的个数  

int CompletePack_4(int n, int c);//优化的动态规划算法，一维数组存储记录 
  
int main()   
{  
    int n = 12;  
      
    for (n=1; n<=22; n++)  
    {  
		memset(F, 0, sizeof(F));    
        cout << CompletePack_4(n, n) << endl;  
    }  
    
    return 0;  
} 

int CompletePack_4(int n, int c)//进一步优化的动态规划算法，用1个一维数组代替二维数组
{
	F[0] = 1;
 	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=c; j++) //j不比i小，能够形成新的组合 
		{
			F[j] += F[j-i];
		}
	}
	
	return F[c];
} 
