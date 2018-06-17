/* 
    Name: 分组背包问题 
    Copyright:  
    Author:  
    Date: 28-07-17 16:25 
    Description:  
分组背包问题 ：在n种物品中选取若干件放在容量为c的背包里，分别用P[i]和W[i]存储第i种物品的价值和重量。 
这些物品被划分为若干组，每组中的物品互相冲突，最多选一件。求解怎么装物品可使背包里物品总价值最大。 
         
输入 
第一行3个数n，c和t，表示共有n种物品，背包总容量为c，共有t组  
接下来n行，每行3个数Wi，Pi和Ti，分别表示第i种物品的重量，价值和所属组号  
输出 
一个整数，表示背包里物品最大总价值 
 
样例输入 
6 10 3 
2 1 1 
3 3 1 
4 8 2 
6 9 2 
2 8 3 
3 9 3 
样例输出 
20   
 
算法分析：分组背包问题是0-1背包问题的一个扩展。 
我们首先需要把各个物品分类存储到t组中，这里有两种方法。 
方法一是使用一个二维数组A[MAXT+1][MAXN+1]存储数据，其中A[i][0]的值表示第i组物品的数量，A[i][k]=r表示第i组的第k个元素是物品r。 
这种方法简明易懂，但是由于事先不知道各组有多少个物品，所以需要预先设置较大的空间，有可能造成很大的空间浪费。 
另一个比较好的方案是使用链表来存储各组物品数据，设置一个链表数组，来存储每组物品，每添加一个物品，就在链表中插入一个结点，这样不会浪费空间。 
分组背包和0-1背包问题几乎一样，只不过最外层循环的含义变成了共t组物品，可以在前i组物品中选择，每组最多选一个。 
第二层循环的含义与0-1背包是一模一样的，然后多了第三层循环，要求在第i组物品中选择一个能取得最优解的物品（或一个也不选）。 
和0-1背包问题一样，既可以使用二维数组来存储最优解，B[i][j]表示给定前i组物品装入容量为j的背包的最大价值。  
也可以进行降维优化，使用一维数组数组来存储最优解。  
*/  
#include<iostream>  
#include<cmath>  
  
using namespace std;  
  
class Node //结点类   
{  
    public:  
        int num;  
        Node *next;  
          
        Node(int n=0)  
        {  
            num = n;  
            next = NULL;  
        }  
};  
  
class List //链表类   
{  
    public:  
        Node *first;  
          
        List()  
        {  
            first = new Node();  
        }  
          
        void Insert(int n) //头插法   
        {  
            Node *s = new Node(n);  
            s->next = first->next;  
            first->next = s;  
        }  
};  
  
const int MAXC = 6000; //背包最大容量   
const int MAXN = 200; //物品的个数  
const int MAXT = 100; //物品的组别   
int W[MAXN+1];//物品的重量   
int P[MAXN+1];//物品的价值   
int A[MAXT+1][MAXN+1];//A[i][k]=r表示第i组的第k个元素是物品r   
List T[MAXT+1]; //使用链表存储第i组的物品   
int B1[MAXT+1][MAXC+1]; //记录给定t组物品装入容量为c的背包的最大价值  
int B2[MAXT+1][MAXC+1]; //记录给定t组物品装入容量为c的背包的最大价值  
int B3[MAXT+1][MAXC+1]; //记录给定t组物品装入容量为c的背包的最大价值  
int F1[MAXC+1]; //记录装入容量为c的背包的最大价值  
int F2[MAXC+1]; //记录装入容量为c的背包的最大价值  
int F3[MAXC+1]; //记录装入容量为c的背包的最大价值  
  
int GroupPack_1(int t, int c);//分组背包问题：二维数组记录最优解  
int GroupPack_2(int t, int c);//分组背包问题：一维数组记录最优解  
int GroupPack_3(int t, int c);//分组背包问题：一维数组记录最优解  
int GroupPack_4(int t, int c);//分组背包问题：链表存储分组物品，二维数组记录最优解  
int GroupPack_5(int t, int c);//分组背包问题：链表存储分组物品，一维数组记录最优解  
  
int main()   
{  
    int n, c, t, p;  
    cin >> n >> c >> t;  
      
    for (int i=1; i<=n; i++)//不计下标为0的元素   
    {  
        cin >> W[i] >> P[i] >> p;  
        A[p][++A[p][0]] = i; //A[p][0]用来存储第p组物品的数量   
        T[p].Insert(i); //因为每组物品的数量未知，使用链表存储第p组物品，比用二维数组要更节省空间   
    }  
      
    //for (int i=1; i<=t; i++)  
//  {  
//      Node *pn = T[i].first->next;  
//      while (pn != NULL)  
//      {  
//          cout << pn->num << " ";   
//          pn = pn->next;  
//      }  
//      cout << endl;  
//  }  
      
    cout << GroupPack_1(t, c) << endl;  
    cout << GroupPack_2(t, c) << endl;  
    cout << GroupPack_3(t, c) << endl;  
    cout << GroupPack_4(t, c) << endl;  
    cout << GroupPack_5(t, c) << endl;  
      
    return 0;  
}  
  
int GroupPack_1(int t, int c)//分组背包问题：二维数组记录最优解  
{  
    int bestP, r;  
      
    for (int i=1; i<=t; i++)//共t组物品，可以在前i组物品中选择，每组最多选一个   
    {  
        for (int j=c; j>0; j--) //由于是二维数组存储0-1背包解，此处j递增或递减均可   
        {  
            bestP = B1[i-1][j]; //默认为不取第i组的物品   
            for (int k=1; k<=A[i][0]; k++) //在第i组物品中选择一个能取得最优解的物品（或一个也不选）   
            {  
                r = A[i][k]; //第i组的第k个元素是物品r  
                if (j >= W[r] && bestP < B1[i-1][j-W[r]] + P[r])  
                    bestP = B1[i-1][j-W[r]] + P[r];  
            }  
            B1[i][j] = bestP;  
        }  
    }  
      
    return B1[t][c];  
}  
  
int GroupPack_2(int t, int c)//与GroupPack_3完全一致，可不用，或请学生改进成GroupPack_3（去掉变量bestP)   
{  
    int bestP;  
      
    for (int i=1; i<=t; i++)//共t组物品，可以在前i组物品中选择，每组最多选一个   
    {  
        for (int j=c; j>0; j--)//由于是一维数组存储0-1背包解，j必须递减   
        {  
            bestP = F1[j]; //默认为不取第i组的物品   
            for (int k=1; k<=A[i][0]; k++) //在第i组物品中选择一个能取得最优解的物品（或一个也不选）   
            {  
                int r = A[i][k]; //第i组的第k个元素是物品r  
                if (j >= W[r] && bestP < F1[j-W[r]] + P[r])  
                    bestP = F1[j-W[r]] + P[r];  
            }  
            F1[j] = bestP;  
        }  
    }  
      
    return F1[c];  
}  
  
int GroupPack_3(int t, int c)//分组背包问题：一维数组记录最优解  
{  
    for (int i=1; i<=t; i++)//共t组物品，可以在前i组物品中选择，每组最多选一个   
    {  
        for (int j=c; j>0; j--)//由于是一维数组存储0-1背包解，j必须递减   
        {  
            for (int k=1; k<=A[i][0]; k++) //在第i组物品中选择一个能取得最优解的物品（或一个也不选）   
            {  
                int r = A[i][k]; //第i组的第k个元素是物品r  
                if (j >= W[r] && F2[j] < F2[j-W[r]] + P[r])  
                    F2[j] = F2[j-W[r]] + P[r];  
            }  
        }  
    }  
      
    return F2[c];  
}  
  
int GroupPack_4(int t, int c)//分组背包问题：链表存储分组物品，二维数组记录最优解  
{  
    int bestP, r;  
      
    for (int i=1; i<=t; i++)//共t组物品，可以在前i组物品中选择，每组最多选一个   
    {  
        for (int j=c; j>0; j--) //由于是二维数组存储0-1背包解，此处j递增或递减均可   
        {  
            bestP = B3[i-1][j]; //默认为不取第i组的物品   
            for (Node *p=T[i].first->next; p!=NULL; p=p->next)  
            {  
                r = p->num; //物品r属于第i组  
                if (j >= W[r] && bestP < B3[i-1][j-W[r]] + P[r])  
                    bestP = B3[i-1][j-W[r]] + P[r];  
            }  
            B3[i][j] = bestP;  
        }  
    }  
      
    return B3[t][c];  
}  
  
int GroupPack_5(int t, int c)//分组背包问题：链表存储分组物品，一维数组记录最优解  
{  
    for (int i=1; i<=t; i++)//共t组物品，可以在前i组物品中选择，每组最多选一个   
    {  
        for (int j=c; j>0; j--)//由于是一维数组存储0-1背包解，j必须递减   
        {  
            for (Node *p=T[i].first->next; p!=NULL; p=p->next)  
            {  
                int r = p->num; //物品r属于第i组  
                if (j >= W[r] && F3[j] < F3[j-W[r]] + P[r])  
                    F3[j] = F3[j-W[r]] + P[r];  
            }  
        }  
    }  
      
    return F3[c];  
}  
