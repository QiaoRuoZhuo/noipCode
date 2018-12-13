/*
	Name: 
	Copyright: 
	Author: 6266_取石子游戏
	Date: 12-07-17 21:07
	Description: 6266_取石子游戏
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有两堆石子,两个人轮流去取.每次取的时候,只能从较多的那堆石子里取,并且取的数目必须是较少的那堆石子数目的整数倍.最后谁能够把一堆石子取空谁就算赢. 
比如初始的时候两堆石子的数目是25和7 

25 7	-->	11 7	-->	4 7	  -->4 3   -->1 3	-->	1 0
选手1取	 选手2取	选手1取	 选手2取  选手1取

最后选手1（先取的）获胜，在取的过程中选手2都只有唯一的一种取法。 
给定初始时石子的数目，如果两个人都采取最优策略，请问先手能否获胜。


输入
输入包含多数数据。每组数据一行，包含两个正整数a和b，表示初始时石子的数目。
输入以两个0表示结束。
输出
如果先手胜，输出"win"，否则输出"lose"
样例输入
34 12
15 24
0 0
样例输出
win
lose
提示
假设石子数目为(a,b)且a >= b,如果[a/b] >= 2则先手必胜,如果[a/b]<2,那么先手只有唯一的一种取法.
[a/b]表示a除以b取整后的值.

算法思想：根据提示可以快速判断是否出现当前玩家必胜的局面，如果出现立即输出结果，否则递归进入下一层。
由于是尾递归，完全可以用迭代来代替递归。 
*/
#include<iostream>
#include<cstdio>

using namespace std;

void DFS(int a, int b, int t); //递归回溯，t表示第t次拿子 
void Fun(int a, int b);//非递归算法 

int main() 
{
	int a, b;
	scanf("%d%d", &a, &b);
	while (a != 0 || b != 0)
	{
		if (a < b) //确保a >= b 
		{
			swap(a, b);
		}
		if (a/b >= 2)
		{
			cout << "win" << endl;
		}
		else
		{
		//	DFS(a, b, 1);
		    Fun(a, b);
		}
		
		scanf("%d%d", &a, &b);
	}
	
    return 0;
}

void DFS(int a, int b, int t) //递归回溯，t表示第t次拿子 
{
	if (a%b == 0 || a/b >= 2) //当前玩家必胜 
	{
		if (t % 2 == 1)
		{
			cout << "win" << endl;
		}
		else
		{
			cout << "lose" << endl;
		}
	}
	else
	{
		DFS(b, a-b, t+1); //先手只有唯一的一种取法
	}
}

void Fun(int a, int b)
{
	int c, t = 1;
	while (a%b != 0 && a/b < 2)
	{
		c = b;
		b = a - b;
		a = c;
		t++;
	}
	if (t % 2 == 1)
	{
		cout << "win" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}
}

