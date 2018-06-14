/*
	Name: 2046_骨牌铺方格
	Copyright: 
	Author: 
	Date: 14-06-18 13:51
	Description: 描述：在2×n的一个长方形方格中,用一个1× 2的骨牌铺满方格,输入n ,输出铺放方案的总数。例如n=3时,为2× 3方格，骨牌的铺放方案有三种,如下图：
 
输入：输入数据由多行组成，每行包含一个整数n,表示该测试实例的长方形方格的规格是2×n (0<n<=50)。
输出：对于每个测试实例，请输出铺放方案的总数，每个实例的输出占一行。

样例输入
1
3
2
样例输出
1
3
2
*/
#include<iostream>  
#include<cmath>  
  
using namespace std;  
  
const int MAXN = 51;  
long long F2[MAXN] = {0, 1, 2};//Fibonacci数列  
  
long long Fun_2(int n);//动态规划：自底而上  
long long Fun_3(int n);//动态规划：降维优化
  
int main()   
{  
    int n, a;  
	
	//Fun_2(MAXN); //动态规划，先记录所有子问题的解 
	while (cin >> n)  
    {  
        //cout << F2[n] << endl;
    	cout << Fun_3(n) << endl;
    }  
      
    return 0;  
}  
  
long long Fun_2(int n)//动态规划：自底而上  
{  
    for (int i=3; i<=n; i++)  
    {  
        F2[i] = F2[i-1] + F2[i-2];  
    }  
      
    return F2[n];  
}  

long long Fun_3(int n)//动态规划：降维优化 
{  
	long long cur, pre1, pre2;
	
	if (n == 1 || n == 2)
		cur = n;  
	pre1 = 1, pre2 = 2; //初始化 	
    for (int i=3; i<=n; i++) //自底向上，迭代更新变量值 
    {  
		cur = pre1 + pre2;  
        pre1 = pre2;
        pre2 = cur;
    }  
      
    return cur;  
}  
