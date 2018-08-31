/*
	Name: 冒泡排序及其优化 
	Copyright: 
	Author: 
	Date: 30-08-18 16:26
	Description: 冒泡排序及其优化
*/
#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int M = 50;
int A[M];

void BubbleSort_1(int lib[], int n);
void BubbleSort_2(int lib[], int n);
void BubbleSort_3(int lib[], int n); 

int main() 
{
	int n  = M;
	for (int i=0; i<n; i++)
		A[i] = rand() % 49 + 1;
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	BubbleSort_3(A, n);
	
	for (int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
} 

void BubbleSort_1(int lib[], int n) //冒泡法基础程序：将较大数向上移动
{
    int high;  //待排序部分数组的上边界，即lib[0..high]为待排序部分，lib[high+1..n-1]为已排序部分
    int temp; //用来交换数组元素值的临时变量
    int i;

    for (high=n-1; high>0; high--) //外层循环控制待排序部分数组的上边界，每完成一趟冒泡，上边界下移一个位置
    {
        for (i=0; i<high; i++)//内层循环扫描待排序部分数组，比较相邻元素，并通过交换元素值的方式将最大值顶到最上方
        {
             if (lib[i] > lib[i+1])
             {
                  temp = lib[i];
                  lib[i] = lib[i+1];
                  lib[i+1] = temp;
             }
        }
    }
}

void BubbleSort_2(int lib[], int n) //改进版1：设置交换标志，以便提前结束扫描
{
     int high;  //待排序部分数组的上边界，即lib[0..high]为待排序部分，lib[high+1..n-1]为已排序部分
     int temp; //用来交换数组元素值的临时变量
     int SwapFlag; //交换标志
     int i;

     for (high=n-1; high>0; high--) //外层循环控制待排序部分数组的上边界，每完成一趟冒泡，上边界下移一个位置
     {
         SwapFlag= 0; //设置交换标志
         for(i=0; i<high; i++)
         {
             if(lib[i] > lib[i+1])
             {
                 temp = lib[i];
                 lib[i] = lib[i+1];
                 lib[i+1] = temp;
                 SwapFlag = 1; //该处发生了交换操作
             }
         }
         if(SwapFlag == 0) //若未进行交换操作，说明排序已经完成，提前结束扫描工作
             break;
     }
}

void BubbleSort_3(int lib[], int n)//改进版3：双向冒泡
{
     int low, high;  //待排序部分数组的边界，即lib[low..high]为待排序部分，lib[0..low-1]和lib[high+1..n-1]为已排序部分
     int lastSwapPos;//最后一次发生交换操作的位置
     int temp; //用来交换数组元素值的临时变量
     int i;

     low = 0;
     high = n - 1;
     while (low < high)
     {
          lastSwapPos = low;//假设最后一次交换位置为左边界（即无交换） 
          for (i=low; i<high; i++)
          {
              if (lib[i] > lib[i+1])
              {
                   temp = lib[i];
                   lib[i] =lib[i+1];
                   lib[i+1] =temp;
                   lastSwapPos = i;//该处发生了交换操作，更新需要排序的成员范围 
              }
          }

          high = lastSwapPos;//设置新的右边界
          for (i=high; i>low; i--)
          {
              if (lib[i] < lib[i-1])
              {
                   temp = lib[i];
                   lib[i] = lib[i-1];
                   lib[i-1] = temp;
                   lastSwapPos = i;//该处发生了交换操作，更新需要排序的成员范围 
              }
          }
          low = lastSwapPos;//设置新的左边界 
     }
}


