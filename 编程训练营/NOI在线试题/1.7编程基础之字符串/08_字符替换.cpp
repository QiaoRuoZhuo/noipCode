/*
	Name: 08_字符替换
	Copyright: 
	Author: 
	Date: 01-09-17 10:21
	Description: 08_字符替换
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
把一个字符串中特定的字符全部用给定的字符替换，得到一个新的字符串。
输入
只有一行，由一个字符串和两个字符组成，中间用单个空格隔开。字符串是待替换的字符串，字符串长度小于等于30个字符，且不含空格等空白符；
接下来一个字符为需要被替换的特定字符；
接下来一个字符为用于替换的给定字符。
输出
一行，即替换后的字符串。
样例输入
hello-how-are-you o O
样例输出
hellO-hOw-are-yOu
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 31;  
char S[N];    
  
int main()   
{  
	char a, b;
    cin >> S >> a >> b;  
    for (int i=0; S[i]!='\0'; i++)  
    {  
        if (S[i] == a)
        	cout << b;
        else
        	cout << S[i];
    }  
    cout << endl;
    
    return 0;     
}   
