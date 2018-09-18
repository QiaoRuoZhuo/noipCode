/*
	Name: 向量旋转算法 
	Copyright: 
	Author: 
	Date: 18\09\18 13:50
	Description: 将数组A中的元素分成左右两部分，然后整体交换两部分的元素的位置，称为旋转向量。
	例如A[6]={1,2,3,4,5,6}，假设左部分长度leftlen=4，则进行旋转后，A[6]={5,6,1,2,3,4} 
	编写一个函数，实现向量旋转。 
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

void ReverseRotate(int A[], int n, int r); 
void Reverse(int A[], int left, int right);
void Fun(int A[], int n, int r);

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%50 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	ReverseRotate(A, MAX, 8);
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	Fun(A, MAX, 2);
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void Fun(int A[], int n, int r)
{
	for (int i=0; i<r; i++)
	{
		int t = A[0];
		for (int j=1; j<n; j++)
			A[j-1] = A[j];
		A[n-1] = t;
	}
}

//方法二：使用一个逆置数组的原子操作
/*
函数名称：Reverse
函数功能：逆置数组的原子操作 
输入参数：int A[]：需要被逆置的数组 
          int left： 数组的左界 
          int right：数组的右界 
输出参数：int A[]：逆置后的数组 
返回值：无 
*/
void Reverse(int A[], int left, int right)
{    
    int t; 
    while (left < right) 
    {
        t = A[left]; 
        A[left] = A[right]; 
        A[right] = t;
        left++;
        right--;
    } 
}

/*
函数名称：ReverseRotate
函数功能：简明的的逆置数组旋转算法：构造一个逆置数组的原子操作子函数，然后设置不同的数组左右界，
          分三次调用子函数就行了。因为每个元素都需要移动两次，所以效率不是很高。 
输入参数：int A[]：需要被旋转的向量 
          int n：向量的长度 
          int r：向量左半段长度 
输出参数：int A[]：旋转后的向量 
返回值：无 
*/
void ReverseRotate(int A[], int n, int r)
{    
    Reverse(A, 0, r-1); //逆置左半段数组
    Reverse(A, r, n-1); //逆置右半段数组 
    Reverse(A, 0, n-1); //逆置整段数组 
}

