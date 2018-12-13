/*
	Name: 
	Copyright: 
	Author: 
	Date: 11-07-17 14:47
	Description: 156:LETTERS
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
A single-player game is played on a rectangular board divided in R rows and C columns.
 There is a single uppercase letter (A-Z) written in every position in the board.
Before the begging of the game there is a figure in the upper-left corner of the board (first row, first column). 
In every move, a player can move the figure to the one of the adjacent positions (up, down,left or right). 
Only constraint is that a figure cannot visit a position marked with the same letter twice.
The goal of the game is to play as many moves as possible.
Write a program that will calculate the maximal number of positions in the board the figure can visit in a single game.
输入
The first line of the input contains two integers R and C, separated by a single blank character, 1 <= R, C <= 20.
The following R lines contain C characters each. Each line represents one row in the board.
输出
The first and only line of the output should contain the maximal number of position in the board the figure can visit.
翻译：
描述：给出一个R*C的大写字母矩阵，开始的位置为左上角，你可以向上下左右四个方向移动，但不能访问同一字母两次。
问最多可以移动几个位置，即最多可以访问几个字母。 
输入：第一行，输入字母矩阵的行数R和列数C，1 <= R, C <= 20。
接着输出R行C列字母矩阵。
输出：最多可以访问的字母个数。
 
样例输入
3 6
HFDFFB
AJHGDH
DGAGEH
样例输出
6

算法思想：
典型的回溯算法，从起点开始，先后向东南西北四个方向前进，能前进则一直前进，不能前进则返回上一格，换个方向继续前进，直到所有方向都不能前进为止。
定义一个全局变量m用来记录最多可以访问的字母个数，用数组letter[26]判断某个字母是否已经被访问；
为避免下标越界，采用了用letter[map[x][y]-'A']表示大写字母map[x][y]的技巧。
*/

#include<iostream>
#include<cstdio>

using namespace std;
 
const int N = 20; 
char map[N][N];
bool letter[26]; //判断26个字母中某个字母是否已经被访问 
int X[4]={0,1,0,-1}, Y[4]={1,0,-1,0}; //向东南西北四个方向移动行坐标和列坐标的变化值 
int m = 0;//最多访问字母数 
int R, C; 

void DFS(int r, int c, int s);

int main() 
{
	cin >> R >> C;
	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
		{
			cin >> map[i][j];
		}
	}
	
	letter[map[0][0]-'A'] = 1; //标注起点的字母已经被访问过 
	DFS(0, 0, 1);
	
	cout << m << endl;
	
    return 0;
}

void DFS(int r, int c, int s) 
{
    if (s > m) //更新最多步数 
    	m = s;
    
    for (int i=0; i<4; i++)//分别向东南西北前进一格，循环结束则退回上一格 
	{
		int x = r + X[i];
		int y = c + Y[i];
		
		if (x >= 0 && x < R && y >= 0 && y < C && !letter[map[x][y]-'A'])//满足条件则继续前进 
		{
			letter[map[x][y]-'A'] = 1;
			DFS(x, y, s+1);
			letter[map[x][y]-'A'] = 0;
		}
	} 
}

