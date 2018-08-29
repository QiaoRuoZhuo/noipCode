/*
  Name: 第k小元素
  Copyright: 
  Author: 
  Date: 13-04-17 15:28
  Description: 求一列数中的第k小元素，利用分治的策略进行递归求解。
  模仿快速排序法的思路，只不过每次只递归处理第k小元素所在的序列。
  要注意每次都应该减少搜索的范围，避免因为随机数不随机而导致的死循环 
*/
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

const int N = 60000000;
int A[N] = {0};

int Partition(int A[], int low, int high);
int SelectK(int A[], int low, int high, int k);
void Swap(int &a, int &b);

int main() 
{
 	for (int i=0; i<N; i++)
 	{
	 	A[i] = rand() % 1000;
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
    int k = 5555555;
    cout << SelectK(A, 0, N-1, k) << endl;
    time(&endTime);
	cout << difftime(endTime, startTime) << endl;
    /*
    for (int i=0; i<N; i++)
 	{
	 	cout << A[i] << "  ";
    }
    cout << endl;
 	*/
 	
    return 0;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int SelectK(int A[], int low, int high, int k)
{
 	if (low == high)
 	   return A[low];
 	   
    int mid = Partition(A, low, high);
    int leftLen = mid - low + 1;
    
    if (k == leftLen)
       return A[mid];
    else if (k < leftLen) //要考虑随机数不随机的特殊情形，避免进入死循环 
        return SelectK(A, low, mid-1, k);
    else
    	return SelectK(A, mid+1, high, k-leftLen);
}

int Partition(int A[], int low, int high)
{
 	srand((unsigned)time(NULL)); //生成随机数
 	int i, j = rand() % (high - low) + low; 
 	Swap(A[low], A[j]); //把枢纽元素置换到最左端 
 	int x = A[low];
 	i = low; 
    j = high + 1;
    
    while (true)
    {
        while (A[++i] <= x && i < high) ;
        while (A[--j] > x) ;
        if (i >= j)
            break;
        
        Swap(A[i], A[j]);
    } 
    Swap(A[low], A[j]); //把枢纽元素置换到它该处的位置
	
	return j; 
}


