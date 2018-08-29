/*
	Name: 14_大小写字母互换
	Copyright: 
	Author: 
	Date: 01-09-17 17:06
	Description: 14_大小写字母互换
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
把一个字符串中所有出现的大写字母都替换成小写字母，同时把小写字母替换成大写字母。

输入
输入一行：待互换的字符串。
输出
输出一行：完成互换的字符串（字符串长度小于80）。
样例输入
If so, you already have a Google Account. You can sign in on the right. 
样例输出
iF SO, YOU ALREADY HAVE A gOOGLE aCCOUNT. yOU CAN SIGN IN ON THE RIGHT. 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 81;  
char S[N];   
char *A="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *B="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char L[255]; 
  
int main()   
{  
	for (int i=0; A[i]!='\0'; i++)//获取转化关系表 
	{
		L[A[i]] = B[i];
	}  
	gets(S);  
    for (int i=0; S[i]!='\0'; i++)  
    {  
		if (isalpha(S[i]))
        	cout << L[S[i]];
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
} 
