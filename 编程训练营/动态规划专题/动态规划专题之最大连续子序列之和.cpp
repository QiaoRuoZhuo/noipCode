/* 
  Name:  动态规划专题之最大连续子序列之和 
  Author:  巧若拙 
  Description:  最大连续子序列之和 
给定K个整数的序列{ N1,N2, ..., NK }，其任意连续子序列可表示为{Ni, Ni+1, ..., Nj }， 
其中 1 <= i <= j <= K。最大连续子序列是所有连续子序列中元素和最大的一个， 
例如给定序列{ -2, 11, -4, 13, -5, -2 }，其最大连续子序列为{ 11, -4, 13 }，最大和为20。  
输入：
测试输入包含若干测试用例，每个测试用例占2行，第1行给出正整数K( < 10000 )，第2行给出K个整数，中间用空格分隔。
当K为0时，输入结束，该用例不被处理。
输出：
对每个测试用例，在1行里输出最大和。若所有K个元素都是负数，则定义其最大和为0。
输入示例：
6
-2 11 -4 13 -5-2
10
-10 1 2 3 4 -5-23 3 7 -21
6
5 -8 3 2 5 0
1
10
3
-1 -5 -2
3
-1 0 -2
0
输出示例：
20
10
10
10
0
0

算法分析：
算法1：
最直接的想法是蛮力穷举。计算每一段可能的连续子序列A[i..j]之和，然后保留最大值。由于有三层循环，故时间复杂度为O(N^3)。

算法2：
仔细观察算法1，我们发现其实最内层循环是不必要的，因为我们可以直接在最外层循环中设置sum = 0;然后累计每一个A[j]值就可以得到A[i..j]之和了。
由于只有两层循环，故时间复杂度为O(N^2)。

算法3：
虽然算法2把时间复杂度减小到O(N^2)，但还算不上高效的算法，我们可以采用一种“分治”策略，把序列分成左右两个部分，
则最大子序列和可能在三处出现：左半部，右半部，或者跨越数据的中部而占据左右两半部分。
前面两种情况可以递归求解，第三种情况需要计算出左半部最大和（必须包含左半部最右元素）以及右半部最大和（必须包含右半部最左元素），
然后将这两个和加在一起。最后返回三者的最大值。
由于采用了分治算法，所以时间复杂度可以减小到O(NlogN)。

算法4：
记忆化搜索（备忘录算法），设置一个全局变量B[i]用来存储包含A[i]的最大连续子序列之和，然后自顶向下，递归计算最优解。
在本题中，因为每个子问题其实只被计算了一次，所以使用记忆化搜索算法并无优势，我把它拿出来，主要是为了和算法5作比较。 

算法5：
接下来要出场的是“动态规划”算法，这也是我向大家隆重推荐的算法，它的实际复杂度为O(N)，是解决此类问题的最佳算法。
动态规划算法与分治法类似，其基本思想也是将待求解问题分解成若干个子问题，先求解子问题，然后从这些子问题的解得到原问题的解。
与分治法不同的是，适合于用动态规划求解的问题，经分解得到子问题往往不是互相独立的。若用分治法来解这类问题，则分解得到的子问题数目太多，
有些子问题被重复计算了很多次。如果我们能够保存已解决的子问题的答案，而在需要时再找出已求得的答案，这样就可以避免大量的重复计算，节省时间。
我们可以用一个表来记录所有已解的子问题的答案。不管该子问题以后是否被用到，只要它被计算过，就将其结果填入表中。这就是动态规划法的基本思路。
在本题中，我们可以把前i(1<=i<=n)个元素的最大子序列和记录下来，不断增大i，最后就得到n个元素的最大子序列和。
我们用一个备忘录数组S[i]来记录包括元素A[i]的最大连续子序列之和， 
从左向右依次增大序列的规模，我们注意到，当处理元素A[i]时，若左侧的连续子序列和S[i-1]>0， 
则S[i]=S[i-1]+A[i]有可能是最优解； 若S[i-1]<0 ，则S[i]=A[i]有可能是最优解。 
计算出所有的S[i]后，再遍历一次数组S[i]，找出最大值。

算法6：
考虑到算法5中S[i]的值只与S[i-1]有关，无需把所有的S[i]都记录下来，可以使用一个变量代替备忘录数组， 
用变量sum代替S[i-1]，记得每处理完一个元素A[i]，都要及时更新sum的值。 

算法7： 
算法6的另一种写法，思路是一样的，但sum初始值不是A[0]，而是0；然后每次不是先判断sum，而是先把A[i]加到sum中，如果sum变成负数，则重新设置sum=0。
 
算法8： 
在算法5的基础上输出连续子序列，在记录备忘录数组的同时，记录最优解和左右边界。

算法9： 
在算法6的基础上输出连续子序列，在记录变量值的同时，记录最优解和左右边界。
*/  
#include<iostream>  
#include<string>  
  
using namespace std;  

const int INF = -100000;  
const int MAX = 10000;  
int B[MAX]; //B[i]用来存储包含A[i]的最大连续子序列之和
  
int MaxSubsequenceSum_1(const int A[], int n);//低效算法1     
int MaxSubsequenceSum_2(const int A[], int n);//低效算法2
int MaxSubsequenceSum_3(const int A[], int n);//分治算法 
int MaxSubSum(const int A[], int left, int right);//分治算法子程序  
int MaxSubsequenceSum_4(const int A[], int i);//记忆化搜索（备忘录算法） 
int MaxSubsequenceSum_5(const int A[], int n);//使用一维数组的动态规划算法  
int MaxSubsequenceSum_6(const int A[], int n);//使用一个变量代替一维数组  
int MaxSubsequenceSum_7(const int A[], int n);//使用一个变量代替一维数组的另一种写法 
int MaxSubsequenceSum_8(const int A[], int n);//记录数组的同时，记录最优解和左右边界   
int MaxSubsequenceSum_9(const int A[], int n);//使用一个变量代替一维数组，输出子序列 

  
int main()  
{  
	int A[MAX] = {0};  
	int n; 
	cin >> n;
	while (n != 0)
	{
		for (int i=0; i<n; i++)
			cin >> A[i];
		cout << MaxSubsequenceSum_1(A, n) << endl;  
	    cout << MaxSubsequenceSum_2(A, n) << endl;  
	    cout << MaxSubsequenceSum_3(A, n) << endl; 
	    
		for (int i=0; i<n; i++)
			B[i] = INF;
	    MaxSubsequenceSum_4(A, n-1);//全局变量B2[MAX] 
		int maxSum = max(0, B[0]);  //注意全是负数的情形 
	    for (int i=1; i<n; i++)//存储各连续子序列的最大和      
	    {  
	        if (B[i] > maxSum)  
	           maxSum = B[i];  
	    }  
	    cout << maxSum << endl;
	    
	    cout << MaxSubsequenceSum_5(A, n) << endl;  
	    cout << MaxSubsequenceSum_6(A, n) << endl;  
	    cout << MaxSubsequenceSum_7(A, n) << endl;  
	    cout << MaxSubsequenceSum_8(A, n) << endl;  
	    cout << MaxSubsequenceSum_9(A, n) << endl;  
	    
	    cin >> n;
	}
      
    return 0;  
}  

int MaxSubsequenceSum_1(const int A[], int n)//低效算法1   
{  
    int sum, maxSum = 0;    
      
    for (int i=0; i<n; i++)  
    {  
        for (int j=i; j<n; j++)  
        {  
            sum = 0;  
            for (int k=i; k<=j; k++)//计算连续子序列A[i..j]之和  
            {  
                sum += A[k];  
            }  
            if (sum > maxSum)  
                maxSum = sum;  
        }  
    }   
      
    return maxSum;  
}  

int MaxSubsequenceSum_2(const int A[], int n)//低效算法2  
{  
    int sum, maxSum = 0; 
      
    for (int i=0; i<n; i++)  
    {  
        sum = 0;  
        for (int j=i; j<n; j++)  
        {  
            sum += A[j];  
            if (sum > maxSum)  
                maxSum = sum;  
        }  
    }   
      
    return maxSum;  
}  

int MaxSubsequenceSum_3(const int A[], int n)//分治算法  
{  
    return MaxSubSum(A, 0, n-1);  
}  
  
int MaxSubSum(const int A[], int left, int right)//分治算法子程序  
{  
    int maxLeftSum, maxRightSum;  
    int maxLeftBorderSum, maxRightBorderSum;  
    int leftBorderSum, rightBorderSum; 
      
    if (left == right)  
        return (A[left] > 0) ? A[left] : 0;  
          
    int mid = (left + right) / 2;  
    maxLeftSum = MaxSubSum(A, left, mid); //递归计算左半部子序列最大和   
    maxRightSum = MaxSubSum(A, mid+1, right);//递归计算右半部子序列最大和   
      
    maxLeftBorderSum = leftBorderSum = 0;  
    for (int i=mid; i>=left; i--)  //从中间开始向左计算包含A[mid]子序列的最大和   
    {  
        leftBorderSum += A[i];  
        if (leftBorderSum > maxLeftBorderSum)  
            maxLeftBorderSum = leftBorderSum;  
    }  
      
    maxRightBorderSum = rightBorderSum = 0;  
    for (int i=mid+1; i<=right; i++)   //从中间开始向右计算A[mid+1]子序列的最大和   
    {  
        rightBorderSum += A[i];  
        if (rightBorderSum > maxRightBorderSum)  
            maxRightBorderSum = rightBorderSum;  
    }  
      
    return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum+maxRightBorderSum);  
}   

int MaxSubsequenceSum_4(const int A[], int i)//记忆化搜索（备忘录算法）   
{    //B[i]用来存储包含A[i]的最大连续子序列之和
    if (B[i] != INF)
    	return B[i];
    if (i == 0)
    {
		B[i] = A[0];
	}
	else
	{
		if (MaxSubsequenceSum_4(A, i-1) > 0)  //若之前的连续子序列之和大于0，则把A[i]累加上去 
			B[i] = MaxSubsequenceSum_4(A, i-1) + A[i];
		else  //否则重新开始 
			B[i] = A[i]; 
	}
	
    return B[i];    
}  

int MaxSubsequenceSum_5(const int A[], int n)//使用一维数组的动态规划算法    
{    
    int S[MAX] = {A[0]};//S[i]用来存储包含A[i]的最大连续子序列之和     
   
    for (int i=1; i<n; i++)//存储各连续子序列的最大和      
    {    
        if (S[i-1] > 0) //若之前的连续子序列之和大于0，则把A[i]累加上去     
            S[i] = S[i-1] + A[i];    
        else   //否则重新开始     
            S[i] = A[i];      
    }     
      
    int maxSum = max(0, S[0]);  //注意全是负数的情形 
    for (int i=1; i<n; i++)//存储各连续子序列的最大和      
    {  
        if (S[i] > maxSum)  
           maxSum = S[i];  
    }  
        
    return maxSum;    
}   

int MaxSubsequenceSum_6(const int A[], int n)//使用一个变量代替一维数组
{  
    int sum = A[0];  
    int maxSum = max(0, sum); //注意全是负数的情形 
    
    for (int i=1; i<n; i++)//存储各连续子序列的最大和      
    {    
        if (sum > 0) //若之前的连续子序列之和大于0，则把A[i]累加上去    
        {   
            sum += A[i];    
            if (sum > maxSum) 
                maxSum = sum; 
        }  
        else   //否则重新开始     
        {   
            sum = A[i]; 
        }  
    }   
      
    return maxSum;  
}   

int MaxSubsequenceSum_7(const int A[], int n)//使用一个变量代替一维数组的另一种写法 
{  
    int sum = 0;  
    int maxSum = max(0, sum); //注意全是负数的情形 
    
    for (int i=0; i<n; i++)//存储各连续子序列的最大和      
    {    
		sum += A[i];
        if (sum > maxSum)   //更新最大值 
        {   
            maxSum = sum; 
        }  
        else if (sum < 0)   //重新开始     
        {   
            sum = 0; 
        }  
    }   
      
    return maxSum;  
}  
  
int MaxSubsequenceSum_8(const int A[], int n)//记录数组的同时，记录最优解和左右边界   
{    
    int S[MAX] = {A[0]};//S[i]用来存储包含A[i]的最大连续子序列之和   
    int maxSum = max(0, S[0]);  
    int left = 0, mLeft = 0, right = 0; //mLeft和right分别存储最大连续子序列的左右边界   
      
    for (int i=1; i<n; i++)//存储各连续子序列的最大和      
    {    
        if (S[i-1] > 0) //若之前的连续子序列之和大于0，则把A[i]累加上去    
        {   
            S[i] = S[i-1] + A[i];    
            if (S[i] > maxSum)   
            {  
                maxSum = S[i];  
                mLeft = left;  
                right = i;  
            }  
        }  
        else   //否则重新开始     
        {   
            S[i] = A[i];    
            left = i;  
        }  
    }     
    
	if (maxSum > 0) 
	{
		cout << "A[" << mLeft << ":" << right << "] : ";  
	    for (int i=mLeft; i<=right; i++)//存储各连续子序列的最大和      
	    {  
	        cout << A[i] << " ";  
	    }  
	    cout << "= ";  
	}
      
    return maxSum;    
}    

int MaxSubsequenceSum_9(const int A[], int n)//使用一个变量代替一维数组，输出子序列   
{    
    int sum = A[0];  
    int maxSum = max(0, sum);  
    int left = 0, mLeft = 0, right = 0; //mLeft和right分别存储最大连续子序列的左右边界   
      
    for (int i=1; i<n; i++)//存储各连续子序列的最大和      
    {    
        if (sum > 0) //若之前的连续子序列之和大于0，则把A[i]累加上去    
        {   
            sum += A[i];    
            if (sum > maxSum)   
            {  
                maxSum = sum;  
                mLeft = left;  
                right = i;  
            }  
        }  
        else   //否则重新开始     
        {   
            sum = A[i];    
            left = i;  
        }  
    }     
    
	if (maxSum > 0)  
	{
		cout << "A[" << mLeft << ":" << right << "] : ";  
	    for (int i=mLeft; i<=right; i++)       
	    {  
	        cout << A[i] << " ";  
	    }  
	    cout << "= ";  
	}
      
    return maxSum;    
} 


