/*
	Name: 中位数median 
	Author: 巧若拙 
	Description: 
描述
给定n（n为奇数且小于1000）个整数，整数的范围在0-m（0<m<2^31）之间，请使用二分法求这n个整数的中位数。
所谓中位数，是指将这n个数排序之后，排在正中间的数。
输入
第一行是两个整数n和m。
第二行是用空格隔开的n个整数 
输出
一个中位数 
样例输入
5 10
3 7 2 5 4 
样例输出
4
*/
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
  
using namespace std;  
  
const int MAXN = 1000;  
int A[MAXN];  
  
int main()   
{  
	int n, m;
    cin >> n >> m;  
    for (int i=0; i<n; i++)  
        cin >> A[i];  
    
    int mid, count, left = 0, right = m; 
    while (left <= right)  
    {  
        mid = (left + right) / 2;  
        count = 0;
        for (int i=0; i<n; i++)
        {
			if (A[i] >= mid)//记录不小于mid的整数数量
				count++; 
		}
        if (count > n/2)    
            left = mid + 1;  
        else  
            right = mid - 1;  
        
     //   cout << mid << " " << left << " " << right << " " << count << " " << n/2 << endl;
    }  
      
    cout << right << endl;   
      
    return 0;  
}  
