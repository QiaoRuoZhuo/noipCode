/*
  Name: 0-1背包问题
  Copyright: 
  Author: 巧若拙 
  Date: 07-03-17 15:30
  Description: 
给定n中物品和一个容量为c的背包，物品i的重量为Wi,其价值为Vi,
0-1背包问题是如何选择装入背包的物品（物品不可分割），使得装入背包的物品的价值为最大。

1.题目分析：
考虑到每种物品只有2种选择，即装入背包或不装入背包，并且物品数和背包容量已给定，
要计算装入背包物品的最大价值和最优装入方案，可用回溯法搜索子集树的算法进行求解。

2.算法设计：
a. 物品有n种，背包容量为C，分别用p[i]和w[i]存储第i种物品的价值和重量，用
x[i]标记第i种物品是否装入背包，用bestx[i]存储第i种物品的最优装载方案；
b. 用递归函数Backtrace(t)来实现回溯法搜索子集树（形式参数t表示递归深度，相当于二叉树的后序遍历）：
① 若t == N，则算法搜索到一个叶结点，判断当前总价值是否最优：
1> 若cp>bestp，更新当前最优总价值为当前总价值（即bestp=cp），更新
装载方案（即bestx[i]=x[i]( 1≤i≤n)）；
② 对物品i装与不装两种情况进行讨论，先分析装t号物品的情形，再分析不装t号物品的情形，这样回溯到上一层时，
X[t]再次归零，同时cp不包含P[t]，cw也不包含W[t]，以便讨论完上层结点后，再次分析结点t。 
if(cw <= c && cp+s > bestp) Backtrace(t+1);继续进行装载；
③ 若已测试完所有装载方案，外层调用就全部结束。
c. 主函数调用一次Backtrace(0)即可完成整个回溯搜索过程，
最终得到的bestp和bestx[i]即为所求最大总价值和最优装载方案。 

在非递归回溯中，我们用X[t]的值表示是第几次访问结点t，刚开始X[t]==0，
如果t == N，表示t为叶子结点的子孙（即不存在t号物品），判断已装载的物品是否为最优解，然后直接回溯。
否则先分析装t号物品的情形，并令X[t] = 1;cw += W[t];cp += P[t];
再分析不装t号物品的情形，并令X[t] = 2;cw -= W[t];cp -= P[t];这样cw和cp的值就已经还原了
两种情况都分析完后X[t]==2，通过语句X[t--] = 0; 来卸掉t号集装箱并回溯到上层结点。 


3. 复杂度分析：
因为装载问题解空间的子集树中叶子节点的数目为2^n，因而最坏情况下时间复杂度为O(2^n)。
 
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 4; //物品的个数
int W[N] = {3, 3, 5, 5};//物品的重量 
int P[N] = {5, 7, 9, 7};//物品的价值 
int X[N]; //解向量
int bestX[N]; //最优解解向量 
int cw, bestw;//cw记录分析到当前结点时，背包的总重量，bestw记录最大价值对应的总重量 
int cp, bestp;//cp记录分析到当前结点时，背包的总价值，bestp记录已经求出的最大价值
int c = 10; //背包容量 

int Sum(int t);//结点t的子树结点价格之和 
void Backtrace(int t); //递归回溯 
void Backtrace_2(); //非递归回溯 

int main() 
{
    Backtrace(0);
   //Backtrace_2();
  
    cout << "背包的最大价值：" << bestp << "(" << bestw << ")" << endl;
    cout << "背包的最优解：";
    for (int i=0; i<N; i++)
	{
	 	cout << bestX[i] << " ";
	}
	cout << endl;
   
    system("pause");
    return 0;
}

int Sum(int t)//结点t的子树结点的最大价值和 
{
 	int s = 0;
    for (int i=t+1; i<N; i++)
	{
	 	s += P[i];
	}
    return s;
}

void Backtrace(int t) //递归回溯 
{
    if(t == N) //如果是叶子结点 
    {
        if(cp > bestp)
		{
			bestw = cw;
			bestp = cp;
			for(int i=0; i<N; i++)
			{
				bestX[i] = X[i];
			}
		}
    }
    else
    {
 		//先分析装t号物品的情形，注意要还原到未装该物品的情形 
 		if(cw+W[t] <= c)//还可以继续装（肯定可能会得到更好的解，否则来不到这一层，早被剪枝了） 
 		{
			X[t] = 1;
			cw += W[t];
			cp += P[t];
			Backtrace(t+1);
			cw -= W[t];
			cp -= P[t];
	    }	
	 	//再分析不装t号物品的情形，相当于把结点t的数据还原了 
	    X[t] = 0;
		if(cp+Sum(t) > bestp)//可能会得到更好的解（装都没装，判断是否超载也是白判断，放到下一层再做判断） 
			Backtrace(t+1);
    }
}

void Backtrace_2() //非递归回溯，用X[t]的值表示是第几次访问结点t 
{
	int t = 0; //第一个顶点入栈
	
	while(t >= 0)
	{
	    if(t == N)//叶子结点的子孙 
		{
		    if(cp > bestp)
		    {
		        bestw = cw;
		        bestp = cp;
		        for(int i=0; i<N; i++)
		        {
		            bestX[i] = (X[i] == 1) ? 1 : 0;
		        }
		    }
		    t--; //回溯
		}
		else if (X[t] == 0)//先分析装t号物品的情形
		{
		    X[t] = 1;
		    cw += W[t];
		    cp += P[t];
		    if(cw <= c) //未超载
   	            t++;
		}
		else if (X[t] == 1)//再分析不装t号物品的情形，这样cw和cp的值就已经还原了 
		{
		    X[t] = 2;
		    cw -= W[t];
		    cp -= P[t];
		    if(cp+Sum(t) > bestp)//可能会得到更好的解 
			    t++; 
		}
		else //表示 X[t] == 2，已经分析完毕，该回溯到上一层结点了 
		{
		 	X[t--] = 0; //卸掉t号集装箱并回溯
		}
	}
}

