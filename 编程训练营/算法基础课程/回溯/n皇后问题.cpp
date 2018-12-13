/*
  Name: n皇后问题
  Copyright: 
  Author: 巧若拙 
  Date: 07-03-17 09:09
  Description: 
一、问题描述：
在n×n格的棋盘上放置彼此不受攻击的n个皇后。
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n后问题等价于再n×n的棋盘上放置n个皇后，任何2个皇后不放在同一行或同一列或同一斜线上。

输入：
    给定棋盘的大小n (n ≤ 13)
输出：
    输出有多少种放置方法。

二、解题思路：
要解决N皇后问题，其实就是要解决好怎么放置这n个皇后，每一个皇后与前面的所有皇后不能在同一行或同一列或同一斜线上，
在这里我们可以以行优先，就是说皇后的行号按顺序递增，只考虑第i个皇后放置在第i行的哪一列，
所以在放置第i个皇后的时候，可以从第1列判断起，如果可以放置在第1个位置，则跳到下一行放置下一个皇后。
如果不能，则跳到下一列...直到最后一列，如果最后一列也不能放置，则说明之前的皇后放置有问题，
则回溯到上一个皇后，把其换到下一个可能位置。此即是回溯法的精髓所在。
当第n个皇后放置成功后，即得到一个可行解，此时再回到上一个皇后重新放置寻找下一个可行解...
如此后，即可找出一个n皇后问题的所有可行解。

三、复杂度分析：
每一行都有n个位置可以放置，一共有n^n中可能性。因而最坏情况下时间复杂度为O(n^n)。
似乎比穷举法要高，但是由于回溯法不测试死结点的分支，它的平均时间复杂度要低于穷举法。 
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 4; //皇后的个数
int c[N];//记录n个皇后的列坐标 
int sum = 0;//保存可以放置的方案数

bool OK(int t);//检查当前皇后的列坐标是否合法 
void Backtrace(int t); //递归回溯 
void Backtrace_2(); //非递归回溯 

int main() 
{
   Backtrace(0);
  // Backtrace_2();
   
   system("pause");
   return 0;
}

bool OK(int t)//检查当前皇后的列坐标是否合法 
{
    for(int i=0; i<t; i++)
    {
        if(c[i] == c[t] || t-i == abs(c[t]-c[i]))      
			return false;       
    }
    return true;
}

void Backtrace(int t) //递归回溯 
{
    if(t == N)
    {
        sum++;
        cout << "方案" << sum << ": ";
        for(int i=0; i<N; i++)
        {
            cout << c[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for(int i=1; i<=N; i++)
        {
			c[t] = i;
            if(OK(t))
				Backtrace(t+1);
        }
      //  c[t] = 0;   //列坐标还原并回溯（由于c[t]每次都从0开始取值，故列坐标无需还原）
    }
}

void Backtrace_2() //非递归回溯 
{
	int t = 0; //第一个顶点入栈
	
	while(t >= 0)
	{
		while(c[t]++ < N)//c[t]默认初始化为0 
		{
			if (OK(t)) //c[t]可行才进入下一步 
			{
				if(t == N-1)
				{
					sum++;
					cout << "方案" << sum << ": ";
					for(int i=0; i<N; i++)
					{
						cout << c[i] << " ";
					}
					cout << endl;
				}
				else
				{
					t++;
				}
			}
		}
		c[t--] = 0; //列坐标还原并回溯
	}
}
