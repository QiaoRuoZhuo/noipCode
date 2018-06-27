/*  
  Name:  最大连续子序列之和练习最大m子段和问题  
  Author: 巧若拙  
  Description: 最大m子段和问题  
给定由 n个整数（可能为负整数）组成的序列a1，a2，a3，……，an，以及一个正整数 m，要求确定序列 a1，a2，a3，……，an的 m个不相交子段，  
使这m个子段的总和达到最大，求出最大和。  
输入： 
每个测试用例将以两个整数m和n开始, 紧随其后的是n个整数a1，a2，a3，……，an。直到读入文件结束。 
输出： 
在一行上输出题目描述中所说的最大和。 
输入示例： 
1 3  
1 2 3 
2 6 
-1 4 -2 3 -2 3 
输出示例： 
6 
8 
  
算法思路：   
经典的动态规划优化的问题。设f(i, j)表示前j个数划分成i段，且包括第j个数的最大m子段和，那么有dp方程：  
　　　　f(i, j) = max { f(i, j-1) + A[j], max {f(i-1, k) + A[j]}(k = i-1 ... j-1)}  
也就是说第j个数要么自己划到第i段，要么和前一个数一起划到第i段里面，转移是O(n)的，总复杂度O(n * n * m)。  
　　  
算法1：int MaxMSubSum(int i, int j);//自顶向下的备忘录算法   
设置一个备忘录数组b[M+1][N+1]，b[i][j]表示把总长度为j的序列分成i个子段后，这i个子段的总和（其中第i个子段包含元素A[j]）  
利用原问题的递归关系，使用递归函数来求解。最后遍历b[m][j]，找出最优解。  
  
算法2：int MaxMSubSum_2(int m, int n);//自底向上的动态规划算法    
从i=1开始，依次记录每一个b[i][j]，最后获得最大规模的b[m][n]。  
和算法1一样，最后遍历b[m][j]，找出最优解。  
  
算法3：int MaxMSubSum_3(int m, int n);//优化的动态规划算法   
是对算法2的优化，算法2中用到的备忘录数组b[M+1][N+1]占空间较大，实际上下一行数据是利用上一行的数据生成的，  
与更早的数据没有关系，于是可以用两个一维数组 cur[N+1] 和 pre[N+1]代替b[M+1][N+1]。 
其中 cur[j]和 pre[j]分别代替b[i][j]和b[i-1][j]。  
 
算法4：int MaxMSubSum_4(int m, int n);//优化的动态规划算法   
是对算法3的优化，算法3中用cur[j]和 pre[j]分别代替b[i][j]和b[i-1][j]，严格地把算法2翻译成算法3的形式， 
在计算cur[j]时需要遍历pre[k]，从中找出最大值，然后再简单地用cur[j]来更新pre[j]的值。 
思考更进一步，如果我们用pre[j]表示将数组A[1...j]分成i-1个子段的最大和，子段中不一定包含A[j]，cur[j]的含义不变， 
则在每次计算cur[j]时不需要需要遍历pre[k]，只需比较pre[j-1]和cur[j-1]即可。 
同时，我们在更新pre[j]时，要从第i子段包含或不包含A[j]中取较大值，即当更新后的pre[j]=cur[j]时表示包含A[j]， 
当pre[j]=pre[j-1]时表示不包含A[j]。  
  
最后写了一个函数 void PrintSubQue(int m, int n); //查找第i段连续子序列的左右边界，并输出这些子序列，  
该函数需要用到备忘录数组b[M+1][N+1]，故只能对算法1和算法2产生的结果有效。   
*/    
#include<iostream>    
#include<cstring>    
    
using namespace std;    
    
const int M = 300;    
const int N = 700;    
int A[N+1];   
int B1[M+1][N+1];    
int B2[M+1][N+1];  
int pre[N+1];//pre[j]存储j个数的最大i-1子段和  
int cur[N+1];//cur[j]存储当前处理行包含A[j]的最大i子段和  
int L[M+1], R[M+1];  
  
int MaxMSubSum_1(int i, int j);//自顶向下的备忘录算法     
int MaxMSubSum_2(int m, int n);//动态规划：二维数组   
int MaxMSubSum_3(int m, int n);//优化的动态规划算法      
int MaxMSubSum_4(int m, int n);//优化的动态规划算法     
void SearchSubQue(int m, int n, int B[M+1][N+1]);//利用二维数组B[][]查找第i段连续子序列的左右边界     
void PrintSubQue(int m); //输出m个子段    
    
int main()    
{    
    int m, n;  
    cin >> m >> n;  
    for (int i=1; i<=n; i++)  
        cin >> A[i];  
      
    int maxSum;  
    maxSum = MaxMSubSum_1(m, n);   //当前面的数是负数时不能全对   
    for (int j=n-1; j>=m; j--)    
    {    
        if (maxSum < B1[m][j])    
            maxSum = B1[m][j];    
    }    
    cout << maxSum << endl;   
    SearchSubQue(m, n, B1); //查找第i段连续子序列的左右边界   
    PrintSubQue(m);  //输出m个子段   
        
    memset(L, 0, sizeof(L));  
    memset(R, 0, sizeof(R));  
    maxSum = MaxMSubSum_2(m, n);    
    cout << maxSum << endl;   
    SearchSubQue(m, n, B2); //查找第i段连续子序列的左右边界   
    PrintSubQue(m);  //输出m个子段   
      
    memset(pre, 0, sizeof(pre));  
    memset(cur, 0, sizeof(cur));  
    maxSum = MaxMSubSum_3(m, n);    
    cout << maxSum << endl;    
      
    memset(pre, 0, sizeof(pre));  
    memset(cur, 0, sizeof(cur));  
    maxSum = MaxMSubSum_4(m, n);    
    cout << maxSum << endl;    
      
    return 0;    
}    
    
int MaxMSubSum_1(int i, int j)//备忘录算法      
{      
    if (B1[i][j] != 0)    
       return B1[i][j];    
        
    if (i==0 || j<i)    
        return 0;  
      
    if (i == j)//注意这个特殊条件，否则不能得到正解   
    {  
        B1[i][j] = MaxMSubSum_1(i-1, j-1) + A[j];     
    }  
    else    
    {    
        int maxSum = MaxMSubSum_1(i, j-1);  
        for (int k=i-1; k<j; k++)    
        {    
            if (maxSum < MaxMSubSum_1(i-1, k))    
               maxSum = B1[i-1][k];    
        }   
        B1[i][j] = maxSum + A[j];     
    }    
          
    return B1[i][j];      
}      
    
int MaxMSubSum_2(int m, int n)//动态规划：二维数组      
{      
    int maxSum;  
      
    for (int i=1; i<=m; i++)  //给定i个子段  
    {    
        B2[i][i] = B2[i-1][i-1] + A[i];  //各数独立成段 
        for (int j=i+1; j<=n; j++)   //给定j个数 
        {    
            maxSum = B2[i][j-1]; //默认A[j]和A[j-1]同属于第i个子段   
            for (int k=i-1; k<j; k++)  //看看是不是A[j]独占第i个子段更好   
            {    
                if (maxSum < B2[i-1][k])    
                    maxSum = B2[i-1][k];    
            }  
            B2[i][j] = maxSum + A[j];   
        }    
    }    
    //遍历B2[m][j]，找到最大值   
    maxSum = B2[m][n];  
    for (int j=m; j<n; j++)  
    {  
        if (maxSum < B2[m][j])    
            maxSum = B2[m][j];  
    }  
         
    return maxSum;      
}      
    
int MaxMSubSum_3(int m, int n)//优化的动态规划算法      
{        
    int maxSum;    
    for (int i=1; i<=m; i++)    
    {    
        cur[i] = pre[i-1] + A[i];  
        for (int j=i+1; j<=n; j++)     
        {    
            maxSum = cur[j-1]; //默认A[j]和A[j-1]同属于第i个子段   
            for (int k=i-1; k<j; k++)  //看看是不是A[j]独占第i个子段更好   
            {    
                if (maxSum < pre[k])    
                    maxSum = pre[k];    
            }  
            cur[j] = maxSum + A[j];  
        }  
        for (int j=i; j<=n; j++)     
        {    
            pre[j] = cur[j];//更新pre[j]  
        }  
    }      
    //遍历pre[j]，找到最大值   
    maxSum = pre[n];  
    for (int j=m; j<n; j++)  
    {  
        if (maxSum < pre[j])    
            maxSum = pre[j];  
    }  
         
    return maxSum;      
}  
  
int MaxMSubSum_4(int m, int n)//优化的动态规划算法      
{   //cur[j]表示分成i个子段的情况下，第i个子段必须包含A[j]的最大和  
    //pre[j]表示将数组A[1...j]分成i-1个子段的最大和，子段中不一定包含A[j]   
    for (int i=1; i<=m; i++)    
    {    
        cur[i] = pre[i-1] + A[i];   
        for (int j=i+1; j<=n; j++)     
        {  //在A[j]独占第i个子段和A[j]与A[j-1]同在第i个子段中取较大值   
            cur[j] = max(pre[j-1], cur[j-1]) + A[j];  
        }  
        //更新pre[j]后，pre[j]表示将数组A[1...j]分成i个子段的最大和   
        pre[i] = cur[i]; //将i个元素分成i个子段，每个元素独占1个子段   
        for (int j=i+1; j<=n; j++)     
        {  //在第i个子段包含或不包含A[j]中取较大值   
            pre[j] = max(cur[j], pre[j-1]);//注意此时的pre[j-1]是已更新的，即已经分成了i个子段  
        }  
    }     
             
    return pre[n];      
}  
  
void SearchSubQue(int m, int n, int B[M+1][N+1])//利用二维数组B[][]查找第i段连续子序列的左右边界     
{    
    int maxSum;    
    int left, right;    
        
    for (int i=m,j=n; i>0; i--,j=left)    
    {    
        maxSum = B[i][j];     
        right = j;    
        for (int k=j; k>=i; k--) //查找第i段连续子序列和的最大值和对应右边界    
        {    
            if (B[i][k] > maxSum)    
            {    
                maxSum = B[i][k];    
                right = k;    
            }    
        }     
        left = right; //查找第i段连续子序列的左边界    
        while (left>=i && B[i][left]>0 && B[i][left]>B[i-1][left])    
        {    
            left--;    
        }     
            
        L[i] = left+1;    
        R[i] = right;     
    }    
}  
  
void PrintSubQue(int m) //输出m个子段    
{  
    for (int i=1; i<=m; i++) //输出m段子序列     
    {    
        cout << i << " : " << "(";   
        int s = A[R[i]];   
        for (int j=L[i]; j<R[i]; j++)    
        {    
            cout << A[j] << ", ";   
            s += A[j];   
        }    
        cout << A[R[i]] << ") = " << s << endl;     
    }    
}   
