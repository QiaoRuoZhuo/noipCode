/*
	Name: 口算题生成器 
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: 为一年级小朋友设计一个自动生成和批改10以内加法的程序。
总共生成6道题目，每次随机产生2个[1,9]的整数，并要求它们的和不大于10，否则重新生成它们。
输出提示语：* + * = ，等待学生输入答案。
若答案正确，输出"正确"并记10分；否则输出"错误，正确答案为*"，不计分。
最后输出总分并结束程序。
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
	srand(time(NULL));
	
	int a, b, c, ans, n = 0, s = 0;
	while (1)
	{
		a = rand() % 9 + 1;
		b = rand() % 9 + 1;
		c = a + b;
		if (c > 10)
			continue;
			
		printf("%d + %d = ", a, b);
		cin >> ans;
		if (ans == c)
		{
			s += 10;
			cout << "正确！" << endl;
		}
		else
		{
			cout << "不正确！正确答案是；" << c << endl;
		}
		
		if (++n == 6)
			break;
	}
	
	cout << "你的总分为；" << s << endl;
	
	return 0;
}
