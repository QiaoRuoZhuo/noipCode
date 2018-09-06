/*
	Name: 十进制数转二进制 
	Copyright: 
	Author: 
	Date: 06\09\18 09:44
	Description: 十进制整数转换成二进制整数采用“除2倒取余”法，十进制小数转换成二进制小数采用“乘2顺取整”法。
具体做法是：将小数部分乘以2，然后取出积的整数部分，剩下的小数部分继续乘以2，然后取积的整数部分。
如此进行，直到积的小数部分为0，或者达到所要求的精度为止。 
	输入一个十进制数，根据规定的精度，输出相应的二进制数。 
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

string Convert(double a, int p);//输出相应的二进制数

int main() 
{
	double a;
	
	cin >> a;
	cout << Convert(a, 3) << endl;
	
	return 0;	
} 

string Convert(double a, int p)//输出相应的二进制数
{
	int z = int(a);
	double x = a - z;
	string b;
	
	if (z == 0)
		b = "0";
	while (z > 0)
	{
		b = char(z%2+'0') + b;
		z /= 2;
	}
	if (p == 0) //精度为0，不输出小数部分 
		return b;
		
	b += ".";
	while (p > 0)
	{
		b += char(int(x * 2)+'0');
		x = x * 2 - int(x * 2);
		p--;
	}
	return b;
}
