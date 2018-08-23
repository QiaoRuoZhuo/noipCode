/*
	Name: 模拟报数游戏
	Copyright: 
	Author: 
	Date: 19-08-18 10:01
	Description: 模拟报数游戏过程。
游戏规则：按顺序报数，但是要跳过3的倍数或包含数字3的数。假设某个班级共40人，每个同学都正确，请输出他们报数的过程（即输出数字，用空格隔开）。

*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int n = 0, s = 0;
	while (1)
	{
		n++;
		if (n%3==0 || n%10==3 || n/10%10==3 || n/100%10==3 || n/1000%10==3)
			continue;
		cout << n << " ";
		if (++s == 40)
			break;
	}
	
	return 0;
}
