/*
	Name: 查找最接近目标数的数 
	Author: 巧若拙 
	Description: 
描述
给定大小为n的有序数组A，输入一个数key，在数组A中查找最接近key的元素（当最接近的数有2个时，输出值较大的一个） 
输入
第一行是两个整数n和key。
第二行是用空格隔开的n个整数 
输出
最接近的元素值 
样例输入
5 4
1 3 5 7 9
样例输出
5
*/
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
  
using namespace std;  
  
const int MAXN = 1000;  
int A[MAXN];  
  
int main()   
{  
	int n, key;
    cin >> n >> key;  
    for (int i=0; i<n; i++)  
        cin >> A[i];  
    
    if (key <= A[0])
    	cout << A[0] << endl;
    else if (key >= A[n-1])
    	cout << A[n-1] << endl;
	else
	{
		int mid, left = 0, right = n; 
	    while (left <= right)  
	    {  
	        mid = (left + right) / 2;  
	        if (key > A[mid])    
	            left = mid + 1;  
	        else  
	            right = mid - 1;  
	    }  
	    if (A[left]-key <= key-A[right])//当最接近的数有2个时，输出值较大的一个
	    	cout << A[left] << endl;
	    else
	    	cout << A[right] << endl; 
	} 
    	
    return 0;  
}  
