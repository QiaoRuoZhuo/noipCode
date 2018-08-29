/*
	Name: 05_输出亲朋字符串
	Copyright: 
	Author: 
	Date: 01-09-17 08:55
	Description: 05_输出亲朋字符串
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
编写程序，求给定字符串s的亲朋字符串s1。 
亲朋字符串s1定义如下：给定字符串s的第一个字符的ASCII值加第二个字符的ASCII值，得到第一个亲朋字符； 
给定字符串s的第二个字符的ASCII值加第三个字符的ASCII值，得到第二个亲朋字符；
依此类推，直到给定字符串s的倒数第二个字符。
亲朋字符串的最后一个字符由给定字符串s的最后一个字符ASCII值加s的第一个字符的ASCII值。
输入
输入一行，一个长度大于等于2，小于等于100的字符串。字符串中每个字符的ASCII值不大于63。
输出
输出一行，为变换后的亲朋字符串。输入保证变换后的字符串只有一行。
样例输入
1234
样例输出
cege
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 101;  
char S[N]; 
  
int main()   
{  
	gets(S); //小心字符串中包含空格，回车：ASCII码13，换行：ASCII码10，空格：ASCII码32 
	int n = strlen(S);
	char t = S[0];
    for (int i=0; i<n-1; i++)  
    {  
        S[i] += S[i+1];
    }  
    S[n-1] += t;
    cout << S << endl;
    
    return 0;     
}   
