/*
	Name: 爱因斯坦的阶梯
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: 爱因斯坦的阶梯。
爱因斯坦出了一道这样的数学题：有一条长阶梯，
若每步跨2阶，则最后剩一阶，若每步跨3 阶，则最后剩2阶，若每步跨5阶，则最后剩4阶，若每步跨6阶则最后剩5阶。
只有每次跨7阶，最后才正好一阶不剩。请问至少有多少阶梯？
*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int n = 0;
	while (1)
	{
		n += 7;
		if (n%2==1 && n%3==2 && n%5==4 && n%6==5)
			break;
	}
	
	cout << n << endl;
	
	return 0;
}
