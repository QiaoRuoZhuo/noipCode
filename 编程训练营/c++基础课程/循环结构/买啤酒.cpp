/*
	Name: 买啤酒 
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: 买啤酒
	丹丹买了n瓶啤酒，3个空瓶可以换1瓶啤酒，请问丹丹最多可以喝到多少瓶啤酒？
	例如：当n=5时，丹丹可以喝到5+1+1=7瓶酒。 
	扩展：若剩下2个空瓶时，可以向老板借1个空瓶，换来1瓶啤酒后再把空瓶还回去，又该如何计算呢？ 
*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int n, s;
	cin >> n; 
	s = n;
	while (n >= 3)//只要够3个空瓶，就能换来啤酒 
	{
		s += n / 3;
		n = n % 3 + n / 3; //剩下的酒瓶和换来的酒瓶 
	}
	cout << s << endl;;
	cout << s + (n==2) << endl;//剩下2个空瓶时，可以向老板借1个空瓶，换来1瓶啤酒后再把空瓶还回去
	
	return 0;
}
