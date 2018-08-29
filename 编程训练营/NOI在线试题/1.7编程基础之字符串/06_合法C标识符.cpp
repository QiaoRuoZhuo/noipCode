/*
	Name: 06_合法C标识符
	Copyright: 
	Author: 
	Date: 01-09-17 09:08
	Description: 06_合法C标识符
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个不包含空白符的字符串，请判断是否是C语言合法的标识符号（注：题目保证这些字符串一定不是C语言的保留字）。
C语言标识符要求：
1. 非保留字；
2. 只包含字母、数字及下划线（“_”）。
3. 不以数字开头。
输入
一行，包含一个字符串，字符串中不包含任何空白字符，且长度不大于20。
输出
一行，如果它是C语言的合法标识符，则输出yes，否则输出no。
样例输入
RKPEGX9R;TWyYcp
样例输出
no
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 21;  
char S[N]; 
  
int main()   
{  
	gets(S); //小心字符串中包含空格，回车：ASCII码13，换行：ASCII码10，空格：ASCII码32 
	int n = strlen(S);
	bool flag = 1;
	if (!(S[0]=='_' || isalpha(S[0])))
	{
		flag = 0;
	}
	else
	{
		for (int i=1; i<n; i++)  
	    {  
	        if (!(S[i]=='_' || isalnum(S[i])))
	        {
				flag = 0;
				break;
			}
	    }  
	}
    if (flag)
    	cout << "yes" << endl;
    else
    	cout << "no" << endl;
    
    return 0;     
}   
