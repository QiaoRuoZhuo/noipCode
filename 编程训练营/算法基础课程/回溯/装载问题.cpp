/*
  Name: 
  Copyright: 
  Author: 巧若拙 
  Date: 07-03-17 10:29
  Description: 
1.问题描述：
有一批共有n个集装箱要装上两艘载重量分别为 c1 和 c2 的轮船，其中集装箱 i 的重量为 w[i], 且重量之和小于(c1 + c2)。
装载问题要求确定是否存在一个合理的装载方案可将这 n 个集装箱装上这两艘轮船。如果有，找出一种装载方案。
例如，当n=3,c1=c2=50,且w=[10,40,40]时，可将集装箱1和集装箱2装上一艘轮船，而将集装箱3装在第二艘轮船；
如果w=[20,40,40],则无法将这3个集装箱都装上轮船。
容易证明，如果一个给定的装载问题有解，则采用如下的策略可以得到最优装载方案。
   1.首先将第一艘轮船尽可能装满。
   2.将剩余的集装箱装上第二艘轮船。
将第一艘轮船尽可能的装满等价于选取全体集装箱的子集，使该子集中集装箱的重量之和最接近 c1。
因此，等价于一个特殊的　0-1　背包问题。 因此是一棵子集树。
    max(w1x1+w2x2+...+wixi) 
   (w1x1+w2x2+...+wixi)<= c1;
    xi @{0,1},1<=i<=n
下面讨论用回溯法设计解装载问题O(2n)计算时间算法。在某些情况下该算法优于动态规划算法。
注：该问题只能应用于有且只有两艘轮船的情况。
 
2 算法设计  
用回溯法解装载问题时，用子集树表示其解空间显然是最合适的。
可行性约束函数可剪去不满足约束条件(w1x1+w2x2+...+wixi)<= c1）的子树。
在子集树的第t层的节点t处，用cw记当前的装载重量，即cw=(w1x1+w2x2+...+wtxt)，
当cw>c1时，以节点t为根的子树中所有节点都不满足约束条件，因而该子树中解均为不可行解，故可将该子树剪去。
函数Sum(int t)计算结点t的子树结点之和。 
在递归算法中，我们先分析装载t号集装箱的情形，再分析不装载t号集装箱的情形，这样回溯到上一层时，
X[t]再次归零，同时 cw也不包含W[t]，以便讨论完上层结点后，再次分析结点t。
每次决定是否递归调用Backtrace(t+1)的条件是(cw <= c1 && cw+Sum(t) > bestw)，即还可以继续装，并且可能会得到更好的解。
当然，为了减少不必要的重复条件判断，在分析左子树（即装载了t号集装箱）时，只需判断是否超载；
而在分析右子树（即未装载t号集装箱）时，只需判断是否可能获得最优解。 
 
在非递归算法中，我们构造一个循环while(X[t]<2)，来确保能分析是否装载t结点的两种情形，通过设置X[t]=2;来跳出循环。
两种情况都分析完后，通过语句X[t--] = 0; 来卸掉t号集装箱并回溯到上层结点。 

3. 复杂度分析：
因为装载问题解空间的子集树中叶子节点的数目为2^n，因而最坏情况下时间复杂度为O(2^n)。
*/
#include<iostream>
#include<cmath>

using namespace std;

const int N = 4; //集装箱的个数
int W[N] = {4, 5, 3, 2};
int X[N]; //解向量
int bestX[N]; //最优解解向量 
int bestw, cw;//cw记录分析到当前结点时，船1的装载重量，bestw记录已经求出的最大装载重量
int c1 = 10, c2 = 7;

int Sum(int t);//结点t的子树结点之和 
void Backtrace(int t); //递归回溯 
void Backtrace_2(); //非递归回溯 

int main() 
{
    Backtrace(0);
   // Backtrace_2();
  
    cout << "船1的最优装载量：" << bestw << endl;
    cout << "船1的最优解：";
    for (int i=0; i<N; i++)
	{
	 	cout << bestX[i] << " ";
	}
	cout << endl;
	
	//求剩余集装箱重量 
	int s2 = 0;
	for (int i=0; i<N; i++)
	{
	 	if (bestX[i] == 0)
	 	   s2 += W[i];
	}
	
	if (s2 > c2)
		cout << "无法将剩余集装箱装入船2，问题无解" << endl;
	else
        cout << "可将剩余集装箱装入船2，问题有解" << endl;  
   
    system("pause");
    return 0;
}

int Sum(int t)//结点t的子树结点之和 
{
    int s = 0;
    for (int i=t+1; i<N; i++)
	{
	 	s += W[i];
	}
    return s;
}

void Backtrace(int t) //递归回溯，相当于二叉树后序遍历 
{
    if(t == N)
    {
        if(cw > bestw)
		{
			bestw = cw;
			for(int i=0; i<N; i++)
			{
				bestX[i] = X[i];
			}
		}
    }
    else
    {
	 	//先分析装载t号集装箱的情形，注意要还原到未装该物品的情形 
 		if(cw+W[t] <= c1)//还可以继续装（肯定可能会得到更好的解，否则来不到这一层，早被剪枝了） 
 		{
			X[t] = 1;
			cw += W[t];
			Backtrace(t+1);
			cw -= W[t];
	    }	
	 	//再分析不装t号集装箱的情形，相当于把结点t的数据还原了 
	    X[t] = 0;
		if(cw+Sum(t) > bestw)//可能会得到更好的解（装都没装，判断是否超载也是白判断，放到下一层再做判断） 
			Backtrace(t+1);
    }
}

void Backtrace_2() //非递归回溯 
{
	int t = 0; //第一个顶点入栈
	
	while(t >= 0)
	{
		while(X[t] < 2)//X[t]默认初始化为0 
		{
			if (X[t] == 0)//先分析装载t号集装箱的情形
			{
				X[t] = 1;
				cw += W[t];
			}
			else //再分析不装载t号集装箱的情形
			{
 	            X[t] = 2; //跳出循环用，其实此时未装载t号集装箱
				cw -= W[t];
			}
			
			if(cw <= c1) //未超载
			{ 
				if(t == N-1)
				{
				    if(cw > bestw)
				    {
				        bestw = cw;
				        for(int i=0; i<N; i++)
				        {
				            bestX[i] = (X[i] == 1) ? 1 : 0;
				        }
				    }
				}
				else if(cw+Sum(t) > bestw)//可能会得到更好的解  
				{
				     t++;
				}
			}
		}
		X[t--] = 0; //卸掉t号集装箱并回溯
	}
}

