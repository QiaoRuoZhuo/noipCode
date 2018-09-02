/*
  Name: 循环赛日程表
  Copyright: 
  Author: 
  Date: 18-04-17 10:18
  Description: 设有n=2k个选手参加比赛，要求设计一个满足一下要求的比赛日程表:
（1）每个选手必须与其他的n-1个选手个比赛一次；
（2）每个选手每天只能赛一次 。
按此要求可以把比赛日程表设计成一个n行n-1列的二维表，其中第i行第j列表示第i个选手在 第j天比赛的选手。

分别设计了递归分治法和迭代法两种算法，无论哪种算法，都首先初始化第1列，以便复制到其他表格。
设计一个复制表格的函数，把左上角坐标为(x1,y1)，大小为n的表格复制到左上角坐标为(x2,y2)的表格上。
 
算法1：用递归分治法安排循环赛日程表 
如果表格大于1，则将表格对分为两半，分别递归地处理左上角和左下角表格；然后“合并”已经处理好的表格，
即把左上角表格复制到右下角，把左下角表格复制到右上角。 否则直接复制表格。 

算法2：用迭代法安排循环赛日程表 
外层循环让表格大小t从1开始成倍增加，内层循环从上往下依次处理每一块大小为t*2的表格，
即把左上角表格复制到右下角，把左下角表格复制到右上角。
每处理完一块表格，左上角行坐标x向下跳跃2*t行。 
*/
#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

const int N = 40;
int A[N][N];

void Table(int n);//用迭代法安排循环赛日程表 
void Table_2(int n);//用迭代法安排循环赛日程表 
void PrintTable(int x, int y, int n);

int main() 
{
 	int n = 8;
 	
//	Table(n);//用迭代法安排循环赛日程表 
	Table_2(n);//用迭代法安排循环赛日程表 	
 	PrintTable(0, 0, n);//输出左上角坐标为(x1,y1)，大小为n的表格
 	
    return 0;
}

void Table(int n)//用迭代法安排循环赛日程表 
{
	A[0][0] = 1; //先确定左上角元素，其他位置元素由它来生成 
	for (int t=1; t<n; t*=2)
	{
		for (int i=0; i<t; i++)//利用左上方阵构造右上方阵
		{
			for (int j=0; j<t; j++)
			{
				A[i][j+t] = A[i][j] + t; //利用元素之间的差值来生成新元素 
			}
		} 
		
		for (int i=0; i<t; i++)//对称交换构造下半部分方阵
		{
			for (int j=0; j<t; j++)
			{
				A[i+t][j] = A[i][j+t]; //左下方阵等于右上方阵 
				A[i+t][j+t] = A[i][j]; //右下方阵等于左上方阵 
			}
		} 
	}
}

void Table_2(int n)//用迭代法安排循环赛日程表 
{
	A[0][0] = 1; //先确定左上角元素，其他位置元素由它来生成 
	for (int t=1; t<n; t*=2)
	{
		for (int i=0; i<t; i++)//利用左上方阵构造左下方方阵
		{
			for (int j=0; j<t; j++)
			{
				A[i+t][j] = A[i][j] + t; //利用元素之间的差值来生成新元素 
			}
		} 
		
		for (int i=0; i<t; i++)//对称交换构造右半部分方阵
		{
			for (int j=0; j<t; j++)
			{
				A[i][j+t] = A[i+t][j]; //右上方阵等于左下方阵 
				A[i+t][j+t] = A[i][j]; //右下方阵等于左上方阵 
			}
		} 
	}
}

void PrintTable(int x, int y, int n)//输出左上角坐标为(x1,y1)，大小为n的表格
{
    for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << A[x+i][y+j] << " ";
		}
		cout << endl;
	}
	cout << endl;	 
}


