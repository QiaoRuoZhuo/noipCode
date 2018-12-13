/*
	Name: 1756_八皇后
	Copyright: 
	Author: 
	Date: 13-07-17 19:49
	Description: 1756_八皇后
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！
这就是著名的八皇后问题。 
对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a=b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。
已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
输出
输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
样例输入
2
1
92
样例输出
15863724
84136275
*/
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

const int N = 8; //皇后的个数
int cel[N];//记录n个皇后的列坐标 
bool b[N]; //b[j]==0表示列j可用
bool c[N+N]; //c[j]==0表示左上-右下斜线可用, i - cel[i] == j - cel[j]
bool d[N+N]; //d[j]==0表示右上-左下斜线可用  i + cel[i] == j + cel[j]
int sum = 0;//保存可以放置的方案数
string lib[93]; //保存92个结果 

void Backtrace(int r); //递归回溯，r表示第r行 
void Backtrace_2(int r);

int main() 
{
	Backtrace(0); //先生成字符串序列，并存储到lib中 
    int n, b;
    
    cin >> n;
    while (n-- > 0)
    {
		cin >> b;
		cout << lib[b] << endl;
	}
   
    return 0;
}

void Backtrace(int r) //递归回溯，r表示第r行 
{
    if(r == N)
    {
        sum++;
        for(int i=0; i<N; i++)
        {
            lib[sum] += cel[i] + 1 + '0';
        }
       // cout << lib[sum] << endl;
    }
    else
    {
        for(int j=0; j<N; j++)//可能的列号 
        {
			if((!b[j])&& (!c[r-j+N]) && (!d[r+j])) //c[i-j+N]是为了确保下标不越界 
			{
				cel[r] = j;
				b[j] = 1;   //宣布占领列j 
				c[r-j+N] = 1; //宣布占领两条斜线 
				d[r+j] = 1;
				Backtrace(r+1); //继续递归放置下一个皇后 
				//还原，以便回溯 
				b[j] = 0;  
				c[r-j+N] = 0; 
				d[r+j] = 0;
			}
        }
    }
}
