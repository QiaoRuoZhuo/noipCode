/*
	Name: 猴子吃桃问题
	Copyright: 
	Author: 
	Date: 22-01-18 14:19
	Description: 猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，
	还不瘾，又多吃了一个第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
	以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。
	求第一天共摘了多少。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int Fun(int n);

int main() 
{
	cout << Fun(1) << endl;
	
	int n = 1;
	for (int i=9; i>0; i--)
		n = (n+1)*2;
	cout << n << endl;
		
    return 0;
}

int Fun(int n)
{
	if (n == 10)
		return 1;
	return (Fun(n+1) + 1) * 2;
}
