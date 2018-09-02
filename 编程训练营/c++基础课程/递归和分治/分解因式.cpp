/*
	Name: 分解因式 
	Copyright: 
	Author: 
	Date: 16-01-18 10:52
	Description: 
*/
#include<iostream>    
#include<cstdio>   
#include<cmath>  
#include<cstdlib> 
    
using namespace std;    
    
const int MAX = 10;     
int A1[MAX+1], A2[MAX+1];    
int M, N, s1, s2;    
    
void DFS_1(int n, int min);
int DFS_2(int n, int i); 
    
int main()     
{    
    int t;    
    cin >> t;    
    for (int k=0; k<t; k++)    
    {    
        cin >> N;    
          
        s1 = 0;   
        DFS_1(N, 2); //最小的因子是2   
        cout << s1 << endl;  
        
        cout << DFS_2(N, N) << endl;  
    }    
        
    return 0;    
}   

void DFS_1(int n, int min) //回溯法 
{
	if (n == 1)
	{
		s1++;
		return;
	}
	for (int i=min; i<=n; i++)
	{
		if (n % i == 0)
		{//确保因子按非递减排列 
			DFS_1(n/i, i);
		}
	}
} 

int DFS_2(int n, int i)
{
	if (n == 1)  //拆分数为1，结束拆分，方案数加1 
	    return 1;
	else if (i == 1) //因子为1，避免无限循环，跳出 
	    return 0;
    else if (n % i == 0) //拆分n，因子可能为i，也可能比i小 
	    return DFS_2(n/i, i) + DFS_2(n, i-1);  
    else //i不是因子可，计算比i小的因子 
		return DFS_2(n, i-1);  
} 
