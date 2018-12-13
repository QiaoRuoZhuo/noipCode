/*
	Name: 1792_迷宫
	Copyright: 
	Author: 
	Date: 13-07-17 21:30
	Description: 1792_迷宫
查看 提交 统计 提问
总时间限制: 3000ms 内存限制: 65536kB
描述
一天Extense在森林里探险的时候不小心走入了一个迷宫，迷宫可以看成是由n * n的格点组成，每个格点只有2种状态，.和#，前者表示可以通行后者表示不能通行。同时当Extense处在某个格点时，他只能移动到东南西北(或者说上下左右)四个方向之一的相邻格点上，Extense想要从点A走到点B，问在不走出迷宫的情况下能不能办到。如果起点或者终点有一个不能通行(为#)，则看成无法办到。
输入
第1行是测试数据的组数k，后面跟着k组输入。每组测试数据的第1行是一个正整数n (1 <= n <= 100)，表示迷宫的规模是n * n的。
接下来是一个n * n的矩阵，矩阵中的元素为.或者#。再接下来一行是4个整数ha, la, hb, lb，描述A处在第ha行, 第la列，
B处在第hb行, 第lb列。注意到ha, la, hb, lb全部是从0开始计数的。
输出
k行，每行输出对应一个输入。能办到则输出“YES”，否则输出“NO”。
样例输入
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
样例输出
YES
NO
*/
#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 101; 
char map[MAX][MAX];
bool lib[MAX][MAX]; //标记该点是否已经来过 
int DicX[4] = {0, 1, 0, -1}; //向东南西北四个方向移动，x坐标相当于行坐标 
int DicY[4] = {1, 0, -1, 0}; //向东南西北四个方向移动，y坐标相当于列坐标 
int n, x0, y0, x1, y1;

bool DFS(int x, int y); 

int main() 
{
	int k;
	cin >> k;
	while (k-- > 0)
	{
		cin >> n;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cin >> map[i][j];
				lib[i][j] = 0; 
			}
		}
		cin >> x0 >> y0 >> x1 >> y1;
		
		if (map[x0][y0]=='#' || map[x0][y0]=='#')//果起点或者终点有一个不能通行(为#)，则看成无法办到。
		{
			cout << "NO" << endl;
			continue;
		}
		
		lib[x0][y0] = 1;
		if (DFS(x0, y0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
    return 0;
}

bool DFS(int x, int y) //x和y分别表示当前行坐标和列坐标，找到终点，返回真
{
	if (x == x1 && y == y1)
	{
		return true;
	}
	
	int nx, ny;
	bool flag = false;
	for (int i=0; i<4; i++)
	{
		nx = x + DicX[i];
	    ny = y + DicY[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !lib[nx][ny] && map[nx][ny] == '.')
		{
			lib[nx][ny] = 1; //走过了就不能再来 
			flag = DFS(nx, ny);
		}
	
		if (flag) //找到终点，返回真 
			return true;
	}
	return false;	
}
