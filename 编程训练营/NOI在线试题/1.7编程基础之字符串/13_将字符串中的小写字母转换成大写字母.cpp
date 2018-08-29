/*
	Name: 13_将字符串中的小写字母转换成大写字母
	Copyright: 
	Author: 
	Date: 01-09-17 17:11
	Description:13_将字符串中的小写字母转换成大写字母
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符串，将其中所有的小写字母转换成大写字母。

输入
输入一行，包含一个字符串（长度不超过100，可能包含空格）。
输出
输出转换后的字符串。
样例输入
helloworld123Ha
样例输出
HELLOWORLD123HA 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 81;  
char S[N];
  
int main()   
{  
	gets(S);  
    for (int i=0; S[i]!='\0'; i++)  
    {  
		if (islower(S[i]))
        	cout << char(S[i]-32);
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
} 
