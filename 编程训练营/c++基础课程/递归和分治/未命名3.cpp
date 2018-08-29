/*
  Name: 第k小元素
  Copyright: 
  Author: 
  Date: 13-04-17 15:28
  Description: 求一列数中的第k小元素，利用分治的策略进行递归求解。
  模仿快速排序法的思路，只不过每次只递归处理第k小元素所在的序列，
  使用消除尾递归优化后效果更好。 
*/
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

const int N = 6000000;
int A[N] = {0};
int B1[N] = {0};
int B2[N] = {0};
int B3[N] = {0};

int SelectK_1(int A[], int low, int high, int k);
int SelectK_12(int A[], int low, int high, int k);
int SelectK_2(int A[], int low, int high, int k);
int SelectK_3(int A[], int low, int high, int k);

int main() 
{
 	for (int i=0; i<N; i++)
 	{
	 	B1[i] = B2[i] = B3[i] = A[i] = rand() % 1000000;
    }
    time_t startTime;
	time_t endTime;
	for (int k = 1; k<6000000; k+=1000000)
	{
	
		time(&startTime); 
	    cout << "1:" << SelectK_1(A, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
		
		time(&startTime); 
	    cout << "12:" << SelectK_12(B1, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
		
		time(&startTime); 
	    cout << "2:" << SelectK_2(B2, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
		
		time(&startTime); 
	    cout << "3:" << SelectK_3(B3, 0, N-1, k-1) << " ";
	    time(&endTime);
		cout << difftime(endTime, startTime) << endl;
    }
    
    return 0;
}

int SelectK_1(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int p = (low+high)/2; 
	swap(A[low], A[p]);
	int i = low, j = high, t = A[low];
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
	if (j == k)
		return A[j];
	else if (j > k)
		return SelectK_1(A, low, j-1, k);
	else 
		return SelectK_1(A, i+1, high, k);
}

int SelectK_12(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int t;
	int i, j, p;
	while (low < high)
	{   
		p = (low+high)/2; 
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
		if (j == k)
			return A[j];
		else if (j > k)
			high = j - 1; //消除尾递归SelectK_1(A, low, j-1, k);
		else 
			low = i + 1; //消除尾递归SelectK_1(A, i+1, high, k);
	}
}

int SelectK_2(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int p = (low+high)/2; 
	swap(A[high], A[p]);
	int i = low, j = high,t = A[high];
	while (i < j) //循环结束时i==j  
	{
		swap(A[i], A[j]);
		while (i < j && A[i] <= t)
			i++;
		while (A[j] > t)
			j--;
	}
	swap(A[low], A[j]);
	if (j == k)
		return A[j];
	else if (j > k)
		return SelectK_2(A, low, j-1, k);
	else 
		return SelectK_2(A, i, high, k);
}

int SelectK_3(int A[], int low, int high, int k)
{
	if (low == high)
 	   return A[low];
 	   
	int p = (low+high)/2; 
	swap(A[low], A[p]);
	int i = low, j = high,t = A[low];
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
	if (j <= k && k < i)
		return A[j];
	else if (j > k)
		high = j - 1; //消除尾递归SelectK_1(A, low, j-1, k);
	else 
		low = i; //消除尾递归SelectK_1(A, i+1, high, k);
	while (i < j) //循环结束时i==j  
	{
		swap(A[i], A[j]);
		while (i < j && A[i] <= t)
			i++;
		while (A[j] > t)
			j--;
	}
	swap(A[low], A[j]);
	if (j <= k && k < i)
		return A[j];
	else if (j > k)
		return SelectK_3(A, low, j-1, k);
	else 
		return SelectK_3(A, i, high, k);
}
