/*
	Name: 求最大数 
	Copyright: 
	Author: 
	Date: 06\09\18 09:44
	Description: 输入一串由字符","隔开的实数，输出其中的最大实数 
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

double MaxNum(const string s);//输出最大实数 

int main() 
{ 
	string s;
	
	cin >> s;
	cout << MaxNum(s) << endl;
	
	return 0;	
} 

double MaxNum(const string s)//输出最大实数 
{
	bool xiaoshu = false;
	double sum = 0, x = 0.1, max = -99999999, f = 1;//f代表正负号 
	int n = s.length();
	
	for (int i=0; i<n; i++)
	{
		if (s[i] == ',')
		{
			sum *= f;
			max = (sum > max) ? sum : max;
			xiaoshu = false;
			sum = 0;
			x = 0.1;
			f = 1;
		}
		else if (s[i] == '-')
			f = -1;
		else if (s[i] == '.')
			xiaoshu = true;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (!xiaoshu) //计算整数部分 
			{
				sum = sum * 10 + (s[i]-'0');
			}
			else//累计小数部分 
			{
				sum += x * (s[i]-'0');
				x *= 0.1;
			}
		}
	}
	//处理最后一个数字 
	sum *= f;
	max = (sum > max) ? sum : max;
	return max;
}
