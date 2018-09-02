/* 
    Name: 快速排序算法析疑  
    Copyright:  
    Author: 巧若拙 
    Date: 13-01-18 15:38 
    Description:快速排序算法  
快速排序的基本思想是通过一趟排序将待排序列分割成独立的两个子序列，然后分别对这两个子序列分别快速排序，以达到整个序列有序。  
假设待排序序列为a[low:high+1]，从中任选一个元素值作为枢纽，再分别从左右两端向中间扫描，通过交换操作将不大于和不小于枢纽的元素分别置于左右两侧，  
使得一趟排序后左子序列的元素均不大于右子序列的元素。  
为防止数组下标越界或重复扫描或出现无限递归，需要下标进行越界检查或设置“限位标志”，  
根据检查方法的不同，出现了各种不同的表达方式，本文拟对此进行分析，抓住问题的本质。 
为了提高算法效率，以下四种算法均采取了随机取枢纽和消除尾递归优化，其中算法一和算法四效率较高，分别适用等值元素少和多的情形。   
*/  
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib>  
  
using namespace std;  
  
const int N = 400000;  
int A[N] = {0};  
int B1[N] = {0};  
int B2[N] = {0};  
int B3[N] = {0};  
int B4[N] = {0};  
int B5[N] = {0};  
  
void QuickSort_1(int A[], int low, int high);  
void QuickSort_2(int A[], int low, int high);  
void QuickSort_3(int A[], int low, int high);  
void QuickSort_4(int A[], int low, int high);  
  
int Cmp(const void *a, const void *b)    
{    
    return *(int *)a - *(int *)b;    
}   
  
int main()   
{  
    for (int i=0; i<N; i++)  
    {  
        B1[i] = B2[i] = B3[i] = B4[i] = B5[i] = A[i] = rand() % 100;  
    }  
 /*    
    for (int i=0; i<N; i++) 
    { 
        cout << A[i] << "  "; 
    } 
    cout << endl; 
   */  
     
    time_t startTime;  
    time_t endTime;  
      
    time(&startTime);   
    QuickSort_1(B1, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    time(&startTime);   
    QuickSort_2(B2, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    time(&startTime);   
    QuickSort_3(B3, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    time(&startTime);   
    QuickSort_4(B4, 0, N-1);  
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
   /* 
    for (int i=0; i<N; i++) 
    { 
        cout << A[i] << "  "; 
    } 
    cout << endl; 
    */  
      
    time(&startTime);  
    qsort(A, N, sizeof(A[0]), Cmp);    
    time(&endTime);  
    cout << difftime(endTime, startTime) << endl;  
      
    int sum = 0;  
    for (int i=0; i<N; i++)  
    {  
        sum += (A[i] != B1[i]) || (A[i] != B2[i]) || (A[i] != B3[i]) || (A[i] != B4[i]);  
    }  
    cout << sum << endl;  
      
    return 0;  
}  
/* 
方法一：此法只获取了枢纽的值，但未对枢纽进行定位，故排序结束后枢纽位置不确定。  
为避免当枢纽为最大或最小元素值时，会单向扫描整个数组而不做任何处理，出现无限递归。  
应将枢纽设为“限位标志”，扫描时遇到枢纽就停下，并在做完交换操作后，i,j均向前一步。  
这样无需对下标进行越界检查，而且确保一趟排序后j<i，子序列长度至少比原序列少1。  
虽然此法在扫描时遇到枢纽也停下，使得交换操作增加，但由于无需检查下标越界，扫描效率很高，特别适合等值元素不多的情形。 
极限情况分析：  
t为最小值：1.i不动，j向左扫描到pos处停下；交换a[i],a[j]，i,j各向前一步。  
2.i不动，j向左扫描到low处停下，因为i>j，外层循环结束。  
3.此时j==low，i==low+1，递归执行qsort_1(a,i,high)。  
t为最大值：1.i向右扫描到pos处停下,j不动；交换a[i],a[j]，i,j各向前一步。  
2.i向右扫描到high处停下,j不动，因为i>j，外层循环结束。  
3.此时j==high-1，i==high，递归执行qsort_1(a,low,j)。 
*/  
void QuickSort_1(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        i = low; j = high; t = A[p];  
        while (i <= j) //注意下标相等时也要扫描，确保最终j<i   
        {  
            while (A[i] < t)  
                i++;  
            while (A[j] > t)  
                j--;  
            if (i <= j)//交换完毕，i,j均向前一步，是本算法的高效之处  
                swap(A[i++], A[j--]);  
        }  
        if (j > low)  
            QuickSort_1(A, low, j);  
        low = i; //消除尾递归qsort_1(a,i,high);   
    }  
}  
  
/* 
方法二：方法一未对枢纽进行定位，当枢纽为最值时，会出现无限递归，若事先将枢纽定位到a[low]，则可避免无限递归。  
因为扫描时不交换与枢纽等值的元素，故需对下标进行越界检查，确保一趟排序后i==j， 
然后将枢纽交换到a[j]处，这样可以确保子序列长度至少比原序列少1。  
由于扫描时需要检查下标越界，使得扫描速度变慢，虽然交换操作减少，但总体效率还是下降了。  
极限情况分析：  
t为最小值：1.j向左扫描到low处停下，i不动，因为i==j，外层循环结束。  
2.交换a[j],a[low]，此时j==low，i==low，递归执行qsort_2(a,i+1,high)。  
t为最大值：1.j不动，i向右扫描到high处停下，因为i==j，外层循环结束。  
2.交换a[j],a[low]，此时j==high，i==high，递归执行qsort_2(a,low,j-1)。 
*/   
void QuickSort_2(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        swap(A[low], A[p]);  
        i = low; j = high; t = A[low];  
        while (i < j) //循环结束时i==j    
        {  
            while (i < j && A[j] > t)//因为枢纽元素在最左侧，应先向左扫描，确保最终a[j]<t   
                j--;  
            while (i < j && A[i] <= t)  
                i++;  
            if (i < j)  
                swap(A[i], A[j]);  
        }  
        swap(A[low], A[j]);  
        if (j-1 > low) //枢纽元素a[j]已经排好，无需再处理   
            QuickSort_2(A, low, j-1);  
        low = i + 1; //消除尾递归qsort_2(a,i+1,high);   
    }  
}  
  
/* 
方法三：方法二中向左右扫描时都需要检查下标越界，当i==j时，外层循环结束，为了确保最终a[j]<t，必须先向左扫描。  
因为我们已经将枢纽放到了a[low]处，故向左扫描时，可以将枢纽设为“限位标志”，j到达low处时必须停下， 
这样就无需检查下标越界，而且扫描方向次序可变。  
此外，方法二中交换操作前后都要判断if i<j，有些重复，我们可以将交换操作提到前面，少做一次判断。  
为了将交换操作提到前面，我们要先取a[high]为枢纽，然后循环之初就交换左右两端元素，那么在后面的过程中枢纽值仍然是a[low]。  
此法还有一个好处，就是确保最终a[i+1,high+1]的值均大于枢纽（a[i]>=t），这样在进行消除尾递归优化后，递归深度大大减少。  
但是由于向右扫描时要检查下标，向左扫描时要在枢纽值处停下，总体来说效率不高，速度与方法二接近。  
极限情况分析：  
t为最小值：1.交换a[i],a[j]；i向前一步，j向左扫描到low处停下，因为i>j，外层循环结束。  
2.交换a[j],a[low]，此时j==low，i==low+1，递归执行qsort_3(a,i,high)。  
t为最大值：1.交换a[i],a[j]；i向右扫描到high处停下，j不动，因为i==j，外层循环结束。  
2.交换a[j],a[low]，此时j==high，i==high，递归执行qsort_3(a,low,j-1)。 
*/  
void QuickSort_3(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        swap(A[high], A[p]);  
        i = low; j = high; t = A[high];  
        while (i < j)  
        {  
            swap(A[i], A[j]);  
            while (i < j && A[i] <= t)  
                i++;  
            while (A[j] > t)  
                j--;  
        }  
        swap(A[low], A[j]);  
        if (i < high)  
            QuickSort_3(A, i, high);  
        high = j - 1; //消除尾递归qsort_3(a,low,j-1);   
    }  
}  
  
/* 
方法四：方法二和方法三都对枢纽进行了定位，以枢纽元素为界，将原序列分为左右两个子序列，递归执行的子序列中都不包含枢纽元素。  
假设存在一种这样的特殊情况：序列中存在大量与枢纽等值的元素，且这些元素连续分布在枢纽两侧，则这些元素已经排好序，不应划入左右子序列中再次递归排序。  
此法在方法二的基础上进行了改进，扩大了i,j的扫描范围，使其能够跨过枢纽右侧与其等值的元素，减少下层递归的子序列长度， 
所以要分别以high和low为扫描边界，即内层循环时i可以大于j，但外层循环检测到i>j时，循环结束。 
此法特别适合等值元素多的数组，与方法一互为补充。  
极限情况分析：  
t为最小值：1.i向前一步，j向左扫描到low处停下，因为i>j，外层循环结束。  
2.交换a[j],a[low]，此时j==low，i==low+1，递归执行qsort_4(a,i,high)。  
t为最大值：1.i向右扫描到high+1处停下，j不动，因为i>j，外层循环结束。  
2.交换a[j],a[low]，此时j==high，i==high+1，递归执行qsort_4(a,low,j-1)。 
*/   
void QuickSort_4(int A[], int low, int high)  
{  
    int t;  
    int i, j, p;  
    while (low < high)  
    {  
        p = rand() % (high + 1 - low) + low;   
        swap(A[low], A[p]);  
        i = low; j = high; t = A[low];  
        while (i <= j)  
        {  
            while (i <= high && A[i] <= t)  
                i++;  
            while (j > low && A[j] >= t)  
                j--;  
            if (i < j)  
                swap(A[i++], A[j--]);  
        }  
        swap(A[low], A[j]);  
        if (j-1 > low) //因为a[j:i]的值均等于枢纽，无需再排序   
            QuickSort_4(A, low, j-1);  
        low = i; //消除尾递归qsort_4(a,i,high);   
    }  
}  

