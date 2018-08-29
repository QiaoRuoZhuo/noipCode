/*
	Name:07_配对碱基链 
	Copyright: 
	Author: 
	Date: 01-09-17 10:15
	Description: 07_配对碱基链
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
脱氧核糖核酸（DNA）由两条互补的碱基链以双螺旋的方式结合而成。而构成DNA的碱基共有4种，
分别为腺瞟呤（A）、鸟嘌呤（G）、胸腺嘧啶（T）和胞嘧啶（C）。我们知道，在两条互补碱基链的对应位置上，
腺瞟呤总是和胸腺嘧啶配对，鸟嘌呤总是和胞嘧啶配对。你的任务就是根据一条单链上的碱基序列，给出对应的互补链上的碱基序列。
输入
一个字符串，表示一条碱基链。这个字符串只含有大写字母A、T、G、C，分别表示腺瞟呤、胸腺嘧啶、鸟嘌呤和胞嘧啶。字符串长度不超过255。
输出
一个只含有大写字母A、T、G、C的字符串，为与输入的碱基链互补的碱基链。
样例输入
ATATGGATGGTGTTTGGCTCTG
样例输出
TATACCTACCACAAACCGAGAC
*/
#include <iostream>
#include <cstdio>
#include <cstring>
  
using namespace std;  
  
const int N = 256;  
char S[N];  
char T[255];  
  
int main()   
{  
    T['A'] = 'T'; T['T'] = 'A'; T['G'] = 'C'; T['C'] = 'G';  //设置配对关系
    gets(S);  
    for (int i=0; S[i]!='\0'; i++)  
    {  
        cout << T[S[i]];
        system("pause");
    }  
    cout << endl;
    
    return 0;     
}   
