/*
	Name: 1818_红与黑
	Copyright: 
	Author: 
	Date: 15-07-17 15:57
	Description: 1818_红与黑
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。
请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
输入
包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。
在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
1）‘.’：黑色的瓷砖；
2）‘#’：白色的瓷砖；
3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
当在一行中读入的是两个零时，表示输入结束。
输出
对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
样例输入
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0
样例输出
45

算法思想：广搜 
*/
#include<iostream>
#include<cstdio>

using namespace std;

const int MAX = 20; 
char map[MAX][MAX];
bool lib[MAX][MAX]; //标记该点是否已经来过 
int DicX[4] = {0, 1, 0, -1}; //向东南西北四个方向移动，x坐标相当于行坐标 
int DicY[4] = {1, 0, -1, 0}; //向东南西北四个方向移动，y坐标相当于列坐标 
int w, h, sum;
int x0, y0;

void BFS(int x, int y); //广搜

int main() 
{
	cin >> w >> h;
    while (w != 0 && h != 0)
    {
		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
			{
				cin >> map[i][j];
				lib[i][j] = 0;
				if (map[i][j] == '@')
				{
					x0 = i;
					y0 = j;
				}
			}
		}
		sum = 1;
		lib[x0][y0] = 1;
		BFS(x0, y0);
		cout << sum << endl;
		cin >> w >> h;
	}
	
    return 0;
}

void BFS(int x, int y) //广搜
{
	int Q[MAX*MAX][2]; //用来存储节点坐标的队列 
	int nx, ny, r = 0, f = 0;
	
	Q[r][0] = x;
	Q[r++][1] = y;
	
	while (r > f)
	{
		x = Q[f][0];
		y = Q[f++][1];
		for (int i=0; i<4; i++)
		{
			nx = x + DicX[i];
		    ny = y + DicY[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && !lib[nx][ny] && map[nx][ny] == '.')
			{
				sum++;
				lib[nx][ny] = 1; //走过了就不能再来 
				Q[r][0] = nx;
				Q[r++][1] = ny;
			}
		}
	}
}
