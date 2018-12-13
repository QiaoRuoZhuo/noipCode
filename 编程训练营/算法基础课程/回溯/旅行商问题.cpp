/*
  Name: 旅行商问题
  Copyright: 
  Author: 巧若拙 
  Date: 09-03-17 15:33
  Description: 
  问题描述：
旅行商问题（Traveling Salesman Problem,TSP）是旅行商要到若干个城市旅行，各城市之间的费用是已知的，为了节省费用，旅行商决定从所在城市出发，到每个城市旅行一次后返回初始城市，问他应选择什么样的路线才能使所走的总费用最短？此问题可描述如下：设G=(V,E)是一个具有边成本cij的有向图，cij的定义如下，对于所有的i和j，cij>0,若<i,j>不属于E，则cij=∞。令|V|=n，并假设n>1。 G的一条周游路线是包含V中每个结点的一个有向环，周游路线的成本是此路线上所有边的成本和。
问题分析：
旅行商问题要从图G的所有周游路线中求取最小成本的周游路线，而从初始点出发的周游路线一共有(n-1)!条，即等于除初始结点外的n-1个结点的排列数，因此旅行商问题是一个排列问题。排列问题比子集合的选择问题通常要难于求解得多，这是因为n个物体有n!种排列，只有 个子集合(n!>O( ))。通过枚举(n-1)!条周游路线，从中找出一条具有最小成本的周游路线的算法，其计算时间显然为O(n!)。
*/
#include<iostream>
#include<string>

using namespace std;

const int N = 4; //图中顶点的个数
const int MAXINT = 9999999; //自定义的最大整数代表无穷大 

int map[N][N]={0,20,6,4,
               20,0,5,10,
               6,5,0,15,
               4,10,15,0};//邻接矩阵
int X[N]; //解向量
int bestX[N]; //最优解解向量 
int d = 0; //当前路径长度
int bestd = MAXINT; //最优的路径长度 

void Swap(int &a, int &b); //交换两个数的值 
bool OK(int i, int j);//检查当前顶点是否合法
void Backtrace(int t); //递归回溯 
void Backtrace_2(); //非递归回溯 

int main() 
{
 	for (int i=0; i<N; i++) //设置初始的顶点顺序 
	{
	 	X[i] = i;
	}
    Backtrace(1);
  // Backtrace_2();
  
    cout << "2最短路径为：" << bestd << "，解向量为；";
    for (int i=0; i<N; i++)
	{
	 	cout << bestX[i] << " ";
	}
	cout << endl;
	
    system("pause");
    return 0;
}

void Swap(int &a, int &b)
{
    //a ^= b ^= a ^= b; 
    int temp = a;
    a = b;
    b = temp;
}

bool OK(int i, int j)//检查当前顶点是否合法
{
    return (map[i][j] < MAXINT) && (d + map[i][j] < bestd);
}

void Backtrace(int t) //递归回溯 
{
    if(t == N-1)//最后一个顶点 
    {
        if (OK(X[t-1], X[t]))
        {
	        d += map[X[t-1]][X[t]];
	        if(OK(X[t], X[0]))
	        {
		        bestd = d + map[X[t]][X[0]];
				for(int i=0; i<N; i++)
				{
					bestX[i] = X[i];
				}
				cout << "最短路径为：" << bestd << "，解向量为；";
				for (int i=0; i<N; i++)
				{
				 	cout << bestX[i] << " ";
				}
				cout << endl;
            }
            d -= map[X[t-1]][X[t]];
        }
    }
    else
    {
        for(int i=t; i<N; i++)
        {
	 		if (OK(X[t-1], X[i]))//如果满足约束条件，则分析X[i]结点 
	        {
		        Swap(X[t], X[i]); //先把满足条件的结点X[i]换到下标为t处 
				d += map[X[t-1]][X[t]]; 
				Backtrace(t+1);
				//下层结点分析完后，再换回来，继续分析下一个可能的结点X[i] 
				d -= map[X[t-1]][X[t]];
				Swap(X[t], X[i]);
	        }
        }
    }
}
