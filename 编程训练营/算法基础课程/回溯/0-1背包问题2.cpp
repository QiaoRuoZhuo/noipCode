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
a. 物品有n种，背包容量为tc，创建一个物品类，分别用w和p存储物品的重量和价格，
设置对象数组A[N]存储各个物品的重量和价格信息，
设置对象c和best分别记录背包当前存储物品的信息，和已经获得的最优解信息， 
x[i]标记第i种物品是否装入背包，用bestx[i]存储第i种物品的最优装载方案；
b. 用递归函数Backtrace(t)来实现回溯法搜索子集树（形式参数t表示递归深度）：
① 若t == N，则算法搜索到一个叶结点，判断当前总价值是否最优：
1> 若c.p>best.p，更新当前最优解（即best=c），更新装载方案（即bestx[i]=x[i]( 0≤i < n)）；
② 对物品i装与不装两种情况进行讨论，先分析装t号物品的情形，再分析不装t号物品的情形，这样回溯到上一层时，
X[t]再次归零，同时c不包含A[t]，以便讨论完上层结点后，再次分析结点t。 
if(c.w <= tc && c.p+Sum(t) > best.p) Backtrace(t+1);继续进行装载；
③ 若已测试完所有装载方案，外层调用就全部结束。
c. 主函数调用一次Backtrace(0)即可完成整个回溯搜索过程，
最终得到的bestp和bestx[i]即为所求最大总价值和最优装载方案。 

在非递归回溯中，我们用X[t]的值表示是第几次访问结点t，刚开始X[t]==0，
如果t == N，表示t为叶子结点的子孙（即不存在t号物品），判断已装载的物品是否为最优解，然后直接回溯。
否则先分析装t号物品的情形，并令X[t] = 1;c.w += A[t].w;c.p += A[t].p;
再分析不装t号物品的情形，并令X[t] = 2;c.w += A[t].w;c.p += A[t].p;这样cw和cp的值就已经还原了
两种情况都分析完后X[t]==2，通过语句X[t--] = 0; 来卸掉t号集装箱并回溯到上层结点。  

3. 复杂度分析：
因为装载问题解空间的子集树中叶子节点的数目为2^n，因而最坏情况下时间复杂度为O(2^n)。
 
*/
#include<iostream>
#include<cmath>

using namespace std;

class Goods
{
public:
    Goods(int _w=0, int _p=0) {w = _w; p = _p;}
    friend int Sum(int t);//结点t的子树结点价格之和 
    friend void Backtrace(int t); //递归回溯 
	friend void Backtrace_2(); //非递归回溯 

	int w, p; //分别存储物品的重量和价格
};

const int N = 4; //物品的个数
Goods A[N] = {Goods(4,5),Goods(1,7),Goods(5,9),Goods(5,7)};
int X[N]; //解向量
int bestX[N]; //最优解解向量 
Goods c, best;//分别记录背包当前存储物品的信息和已经获得的最优解信息 
int tc = 10; //背包总容量 

int main() 
{
    Backtrace(0);
    //Backtrace_2();
  
    cout << "背包的最大价值：" << best.p << "(" << best.w << ")" << endl;
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
	 	s += A[i].p;
	}
    return s;
}

void Backtrace(int t) //递归回溯 
{
    if(t == N)
    {
        if(c.p > best.p)
		{
			best = c;
			for(int i=0; i<N; i++)
			{
				bestX[i] = X[i];
			}
		}
    }
    else
    {
	 	//先分析装t号物品的情形，注意要还原到未装该物品的情形 
 		if(c.w+A[t].w <= tc)//还可以继续装（肯定可能会得到更好的解，否则来不到这一层，早被剪枝了） 
 		{
			X[t] = 1;
			c.w += A[t].w;
			c.p += A[t].p;
			Backtrace(t+1);
			c.w -= A[t].w;
			c.p -= A[t].p;
	    }	
	 	//再分析不装t号物品的情形，相当于把结点t的数据还原了 
	    X[t] = 0;
		if(c.p+Sum(t) > best.p)//可能会得到更好的解（装都没装，判断是否超载也是白判断，放到下一层再做判断） 
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
		    if(c.p > best.p)
		    {
		        best = c;
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
		    c.w += A[t].w;
		    c.p += A[t].p;
		    if(c.w <= tc) //未超载
   	            t++;
		}
		else if (X[t] == 1)//再分析不装t号物品的情形，这样cw和cp的值就已经还原了 
		{
		    X[t] = 2;
		    c.w -= A[t].w;
		    c.p -= A[t].p;
		    if(c.p+Sum(t) > best.p)//可能会得到更好的解
			    t++; 
		}
		else //表示 X[t] == 2，已经分析完毕，该回溯到上一层结点了 
		{
		 	X[t--] = 0; //卸掉t号集装箱并回溯
		}
	}
}
