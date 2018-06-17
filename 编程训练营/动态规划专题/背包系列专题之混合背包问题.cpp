/*  
    Name: 混合背包问题   
    Copyright:   
    Author:  巧若拙  
    Date: 07-06-18 09:33  
    Description:   
混合背包问题 ：在n种物品中选取若干件放在容量为c的背包里，分别用P[i]和W[i]存储第i种物品的价值和重量。  
有的物品只可以取一次（01背包），有的物品可以取无限次（完全背包），有的物品可以取的次数有一个上限（多重背包）  
求解怎么装物品可使背包里物品总价值最大。  
          
输入  
第一行2个数n和c，表示共有n种物品，背包总容量为c   
接下来n行，每行3个数Wi，Pi和Ni，分别表示第i种物品的重量，价值和最大数量（若Ni=0，则表示此物品可取无限次）   
输出  
一个整数，表示背包里物品最大总价值  
  
样例输入  
3 10  
2 1 0  
3 3 1  
4 5 4  
样例输出  
11    
  
算法分析：  
考虑到0-1背包是多重背包问题的一个特例，所以混合背包问题可以分为完全背包和多重背包两种情况分析。  
只需要判断Ni的值，然后分别使用完全背包和多重背包的算法来写代码就行了。  
我们可以用2个一维数组记录最优解，也可以进一步优化，使用1个一维数组记录最优解。 
因为即使是完全背包问题，实际上选择物品的数量也是有限的， 
因此全部当作多重背包来解，代码结构更简洁，但是因为使用了三重循环，完全背包的效率降低。    
*/    
#include<iostream>    
#include<cmath>    
    
using namespace std;    
    
const int MAXC = 6000; //背包最大容量     
const int MAXN = 2000; //物品的个数    
int W[MAXN+1];//物品的重量     
int P[MAXN+1];//物品的价值     
int N[MAXN+1];//物品的最大数量      
int pre[MAXC+1]; //pre[j]相当于B[i-1][j]   
int cur[MAXC+1]; //cur[j]相当于B[i][j]  
int F[MAXC+1]; //记录装入容量为c的背包的最大价值    
int F2[MAXC+1]; //记录装入容量为c的背包的最大价值    
int F3[MAXC+1]; //记录装入容量为c的背包的最大价值    
    
int MixPack_1(int n, int c);//混合背包问题：2个一维数组记录最优解    
int MixPack_2(int n, int c);//混合背包问题：一维数组记录最优解    
int MixPack_3(int n, int c);//混合背包问题：全部当作多重背包来解，代码结构更简洁，但是完全背包的效率降低   
int MixPack_4(int n, int c);//混合背包问题：全部当作多重背包来解，使用了朴素的穷举算法   
    
int main()     
{    
    int n, c;    
    cin >> n >> c;    
        
    for (int i=1; i<=n; i++)//不计下标为0的元素     
    {    
        cin >> W[i] >> P[i] >> N[i];    
    }    
        
    cout << MixPack_1(n, c) << endl;    
    cout << MixPack_2(n, c) << endl;    
    cout << MixPack_3(n, c) << endl;   
    cout << MixPack_4(n, c) << endl;   
        
    return 0;    
}    
  
int MixPack_1(int n, int c)//混合背包问题：2个一维数组记录最优解    
{    
    for (int i=1; i<=n; i++)    
    {    
        if (N[i] == 0) //完全背包    
        {     
            //cur[j]表示给定i个物品的情况下，背包容量为j时的最优解   
            //pre[j]表示给定i-1个物品的情况下，背包容量为j时的最优解   
            for (int j=1; j<=c; j++)  
            {  
                if (j < W[i] || pre[j] > cur[j-W[i]] + P[i])  
                    cur[j] = pre[j];   
                else  
                    cur[j] = cur[j-W[i]] + P[i];  
            }  
            for (int j=1; j<=c; j++)  
            {  
                pre[j] = cur[j];   
            }  
        }    
        else //多重背包（包含0-1背包）     
        {    
            //cur[j]表示给定i个物品的情况下，背包容量为j时，对物品进行第k次选择时所能获得的最优解   
            //pre[j]表示给定i个物品的情况下，背包容量为j时，对物品进行第k-1次选择时所能获得的最优解    
            for (int k=0; k<N[i]; k++)  
            {  
                for (int j=1; j<=c; j++)  
                {  
                    if (j < W[i] || pre[j] > pre[j-W[i]] + P[i])  
                        cur[j] = pre[j];   
                    else  
                        cur[j] = pre[j-W[i]] + P[i];  
                }  
                for (int j=1; j<=c; j++)  
                {  
                    pre[j] = cur[j];   
                }  
            }    
        }    
    }    
        
    return pre[c];    
}     
    
int MixPack_2(int n, int c)//混合背包问题：1个一维数组记录最优解    
{    
    for (int i=1; i<=n; i++)    
    {    
        if (N[i] == 0) //完全背包    
        {   //须先求出列坐标j较小的元素，故让循环变量j的值从小到大递增   
            for (int j=W[i]; j<=c; j++)    
            {//当(j < W[i] || F[j] > F[j-W[i]] + P[i])时，F[j]的值不变    
                if (F[j] < F[j-W[i]] + P[i])    
                    F[j] = F[j-W[i]] + P[i];    
            }    
        }    
        else //多重背包（包含0-1背包）     
        {    
            for (int k=0; k<N[i]; k++)//对第i种物品进行N[i]次选择     
            {//须先求出列坐标j较大的元素，故让循环变量j的值从大到小递减    
                for (int j=c; j>=W[i]; j--)    
                {//当(j < W[i] || F[j] > F[j-W[i]] + P[i])时，F[j]的值不变    
                    if (F[j] < F[j-W[i]] + P[i])    
                        F[j] = F[j-W[i]] + P[i];    
                }    
            }    
        }    
    }    
        
    return F[c];    
}    
  
int MixPack_3(int n, int c)//混合背包问题：全部当作多重背包来解，代码结构更简洁，但是完全背包的效率降低   
{    
    int maxNum = 0; //记录对第i种物品进行0-1选择的最多次数   
    for (int i=1; i<=n; i++)    
    {    
        maxNum = c / W[i]; //即使是完全背包，也最多选择maxNum次   
        if (N[i] > 0 && maxNum > N[i]) //非完全背包    
        {     
            maxNum = N[i];  
        }    
        for (int k=maxNum; k>0; k--)//对第i种物品进行maxNum次0-1选择     
        {//须先求出列坐标j较大的元素，故让循环变量j的值从大到小递减    
            for (int j=c; j>=W[i]; j--)    
            {//当(j < W[i] || F[j] > F[j-W[i]] + P[i])时，F[j]的值不变    
                if (F2[j] < F2[j-W[i]] + P[i])    
                    F2[j] = F2[j-W[i]] + P[i];    
            }    
        }    
    }    
        
    return F2[c];    
}    
  
int MixPack_4(int n, int c)//混合背包问题：全部当作多重背包来解，使用了朴素的穷举算法      
{    
    int s, bestP;    
    int maxNum = 0; //记录对第i种物品选择的最多次数       
        
    for (int i=1; i<=n; i++)    
    {    
        for (int j=c; j>=W[i]; j--) //类似于0-1背包问题，j只能递减    
        {    
            //朴素的穷举思想，计算第i个物品装k个时，获得多少价值，存储最大价值到B[i][j]     
            bestP = s = 0;    
            maxNum = c / W[i]; //即使是完全背包，也最多选择maxNum个     
            if (N[i] > 0 && maxNum > N[i]) //非完全背包        
            {         
                maxNum = N[i];      
            }      
            for (int k=maxNum; k>0; k--)    
            {    
                if (k*W[i] <= j)    
                {    
                    s = F3[j-k*W[i]] + k*P[i];     
                    if (s > bestP)    
                        bestP = s;    
                }    
            }    
            if (F3[j] < bestP) //有更好的解才更新     
                F3[j] = bestP;    
        }    
    }    
        
    return F3[c];    
}    

