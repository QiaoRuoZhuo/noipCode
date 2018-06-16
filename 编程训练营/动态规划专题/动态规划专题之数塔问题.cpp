/*
	Name: 动态规划专题之数塔问题 
	Author: 巧若拙 
	Description:7625_三角形最佳路径问题
描述：如下所示的由正整数数字构成的三角形: 
7 
3 8 
8 1 0 
2 7 4 4 
4 5 2 6 5 

从三角形的顶部到底部有很多条不同的路径。对于每条路径，把路径上面的数加起来可以得到一个和，和最大的路径称为最佳路径。
你的任务就是求出最佳路径上的数字之和。 
注意：路径上的每一步只能从一个数走到下一层上和它最近的下边（正下方）的数或者右边（右下方）的数。

输入
第一行为三角形高度100>=h>=1，同时也是最底层边的数字的数目。
从第二行开始，每行为三角形相应行的数字，中间用空格分隔。
输出
最佳路径的长度数值。
样例输入
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
或
1
8
样例输出
30
或
8
*/
#include<iostream>  
#include<cstring>
  
using namespace std;  
  
const int MAX = 100;   
int map[MAX][MAX];  
int B1[MAX][MAX]; //备忘录，记录从位置(x,y)到达底行所获得的最大值
int B2[MAX][MAX]; //动态规划，记录从位置(x,y)到达底行所获得的最大值
int pre[MAX]; //pre[j]相当于B2[i+1][j] 
int cur[MAX]; //cur[j]相当于B2[i][j]
int F[MAX];//记录当前行的最优解
int bestP; //记录最优解 
  
void DFS(int n, int x, int y, int curP);//n表示行数，x,y表示当前位置坐标，curP表示目前已走路径上的权值和 
int DP_1(int n, int x, int y);//n表示行数，计算从位置(x,y)到达底行所获得的最大值 
int DP_2(int n); //动态规划（逆推法）
int DP_3(int n); //动态规划（降维优化1）
int DP_4(int n); //动态规划（降维优化2） 
int DP_5(int n); //动态规划（利用原数据）
void PrintPath(int n); //输出最佳路径
void PrintPath_2(int n); //输出最佳路径
  
int main()   
{  
    int n;  
    cin >> n;  
    for (int i=0; i<n; i++)  
    {  
        for (int j=0; j<=i; j++)  
        {  
            cin >> map[i][j];  
        }  
    }  
     
    //回溯算法，需要用到全局变量map[MAX][MAX]，另有bestP初始化为0
    DFS(n, 0, 0, map[0][0]);  
    cout << bestP << endl;  
    
	//记忆化搜索（备忘录算法），需要用到全局变量map[MAX][]，另有B1[MAX][]初始化为-1
	memset(B1, -1, sizeof(B1)); //先初始化B1的值全为-1  
    cout << DP_1(n, 0, 0) << endl;  
    
    //动态规划（逆推法），需要用到全局变量B2[MAX][]
    cout << DP_2(n) << endl;  
    
    //动态规划（逆推法），需要用到全局变量pre[]和cur[] 
    cout << DP_3(n) << endl;  
    
    //动态规划（逆推法），需要用到全局变量F[]
    cout << DP_4(n) << endl;  
    
    PrintPath(n); //输出最佳路径
    
    //动态规划（逆推法），需要用到全局变量map[MAX][]
    cout << DP_5(n) << endl;  
    
    PrintPath_2(n); //输出最佳路径
      
    return 0;  
}  

void DFS(int n, int x, int y, int curP)//n表示行数，x,y表示当前位置坐标，curP表示目前已走路径上的权值和 
{  
    if (x == n-1)
    {
		if (curP > bestP)
			bestP = curP;
	}
	else
	{
		DFS(n, x+1, y, curP+map[x+1][y]); //向正下方走 
		DFS(n, x+1, y+1, curP+map[x+1][y+1]); //向右下方走 
	}
}  

int DP_1(int n, int x, int y)//n表示行数，计算从位置(x,y)到达底行所获得的最大值 
{  
    if (B1[x][y] != -1)  
		return B1[x][y];
 	
	if (x == n-1)
		B1[x][y] = map[x][y];
	else
		B1[x][y] = map[x][y] + max(DP_1(n,x+1,y), DP_1(n,x+1,y+1));
	
    return B1[x][y]; 
}  

int DP_2(int n) //动态规划（逆推法） 
{  
	for (int j=0; j<n; j++)  //最底层的最大元素和就等于元素值 
		B2[n-1][j] = map[n-1][j];
    for (int i=n-2; i>=0; i--) //从右下角斜向上走，最终到达顶点，刚好得到答案  
    {  
        for (int j=i; j>=0; j--)
        {  
            B2[i][j] = map[i][j] + max(B2[i+1][j], B2[i+1][j+1]);  
        }  
    }  
    return B2[0][0];  
} 

int DP_3(int n) //动态规划（降维优化1） 
{  
    for (int j=0; j<n; j++)  //最底层的最大元素和就等于元素值 
		pre[j] = map[n-1][j];
    for (int i=n-2; i>=0; i--) //从右下角斜向上走，最终到达顶点，刚好得到答案  
    {  
        for (int j=i; j>=0; j--)   
        {  
            cur[j] = map[i][j] + max(pre[j], pre[j+1]);  
        } 
		for (int j=i; j>=0; j--)   
        {  
            pre[j] = cur[j];  
        }  
    }  
    return pre[0];  
} 

int DP_4(int n) //动态规划（降维优化2） 
{  
    for (int j=0; j<n; j++)  //最底层的最大元素和就等于元素值 
		F[j] = map[n-1][j];
    for (int i=n-2; i>=0; i--) //从右下角斜向上走，最终到达顶点，刚好得到答案  
    {  
        for (int j=0; j<=i; j++)   
        {  
            F[j] = map[i][j] + max(F[j], F[j+1]);  
        } 
    }  
    return F[0];  
} 

int DP_5(int n) //动态规划（利用原数据） 
{  
    for (int i=n-2; i>=0; i--) //从右下角斜向上走，最终到达顶点，刚好得到答案  
    {  
        for (int j=i; j>=0; j--)   
        {  
            map[i][j] += max(map[i+1][j], map[i+1][j+1]);  
        }  
    }  
    return map[0][0];  
} 

void PrintPath(int n) //输出最佳路径 
{  
	int j = 0; 
    for (int i=0; i<n-1; i++) //输出前n-1行 
    {  
		cout << map[i][j] << "->"; //输出上一行元素 
        if (B2[i+1][j] < B2[i+1][j+1]) //向右下方走，否则向正下方走 
        {  
            j++;
        }  
    }  
    //输出底层元素   
    cout << map[n-1][j] << endl;  
}  

void PrintPath_2(int n) //输出最佳路径 
{  
    int i = 0, j = 0; 
      
    for (int k=1; k<n; k++) //输出前n-1行   
    {  
        if (map[i+1][j] > map[i+1][j+1]) //向正下方走  
        {  
            cout << map[i][j] - map[i+1][j] << "->";  
            i++;  
        }   
        else //向右下方走  
        {  
            cout << map[i][j] - map[i+1][j+1] << "->";  
            i++;  
            j++;  
        }   
    }  
    //输出底层元素   
    cout << map[i][j] << endl;  
}  
