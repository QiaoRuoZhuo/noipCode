/*  
    Name: 666_放苹果  
    Author: 巧若拙  
描述  
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。  
输入  
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。  
输出  
对输入的每组数据M和N，用一行输出相应的K。  
样例输入  
1  
7 3  
样例输出  
8  
 
算法分析： 
有2种思路，一种是确保后面的盘子中苹果不比前面的少，另一种是确保后面的盘子中苹果不比前面的多。 
第2种思路递归深度较少，但代码复杂些，特别要注意第n个盘子能放苹果的数量范围。  
*/    
#include<iostream>    
#include<cstdio>    
    
using namespace std;    
    
const int MAX = 10;     
int A1[MAX+1], A2[MAX+1];    
int M, N, s1, s2;    
    
void DFS_1(int m, int n); //m表示共m个苹果，n表示第n个盘子    
    
int main()     
{    
    int t;    
    cin >> t;    
    for (int k=0; k<t; k++)    
    {    
        cin >> M >> N;    
          
        s1 = 0;   
        DFS_1(M, 1);    
        cout << s1 << endl;  
    }    
        
    return 0;    
}    
  
void DFS_1(int m, int n) //m表示共m个苹果，n表示第n个盘子     
{    
    if (n == N)    
    {    
        s1++;    
    }    
    else    
    {    
        for (A1[n]=A1[n-1]; A1[n]+A1[n]<=m; A1[n]++)    
        {   //确保剩下的苹果不比当前盘子中的少     
            DFS_1(m-A1[n], n+1); 
        }    
    }       
}  

 
  
