/*
	Name: 06_笨小猴
	Copyright: 
	Author: 巧若拙 
	Date: 15-08-17 21:51
	Description: 06_笨小猴
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，
如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。
输入
只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
输出
共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。
样例输入
样例 #1：
error

样例 #2：
olimpic
样例输出
样例 #1：
Lucky Word
2

样例 #2：
No Answer
0
提示
单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3-1=2，2是质数。
单词olimpic中出现最多的字母i出现了2次，出现次数最少的字母出现了1次，2-1=1，1不是质数。

算法分析：
要注意有些字母出现次数为0，需要排除。在求最值时，要利用单词长度小于100的条件，给最小值初始化为100，同时要小心最大值和最小值相等的情形。 
*/
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int A[26]={0};
	string B;
	cin >> B;
	int n = B.length();
	for (int i=0; i<n; i++)//累计字母数量 
	{
		A[B[i]-'a']++;
	}
	
	int min=100, max=1;
	for (int i=0; i<26; i++)//同时查找最大值和最小值 
	{
		if (A[i] == 0)
			continue;
			
		if (A[i] > max)
			max = A[i];
		else if (A[i] < min)
			min = A[i];
	} 
	
	int m = max - min;
	if (m < 2) //注意m不大于0的情形 
	{
		cout << "No Answer" << endl << 0 << endl;
		return 0;
	}
	for (int i=2; i<m; i++)
	{
		if (m % i == 0)
		{
			cout << "No Answer" << endl << 0 << endl;
			return 0;
		}
	}
	cout << "Lucky Word" << endl << m << endl;
	
	return 0;	
} 
