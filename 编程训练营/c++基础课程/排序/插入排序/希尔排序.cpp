/*
	Name: 
	Copyright: 
	Author: 
	Date: 18\09\18 15:01
	Description: 插入排序在对几乎已经排好序的数据操作时，效率高，几乎可以达到线性排序的效率，但进行插入操作时，每次只能将数据移动一位，难免出现大量重复移动，如果能将元素尽可能快的移动到它“该去”的地方，将大大减少重复移动的次数，提高效率。

希尔排序是把全部元素分组排序，将所有距离为步长gap的元素放在同一个组中，通过“跳跃式移动”的方法，能让元素每次移动一大步，即步长gap>1，大大提高了移动的效率。一趟排序下来，虽然同组的元素没有挨在一起，各组元素相互隔开，但是由于每一组都已经各自排好序了，所以整个序列还是“基本有序”的。

然后再取越来越小的步长进行排序，直到步长gap=1时，就是普通的插入排序，但是到了这步，整个序列是“基本有序”了，直接插入排序也能高效完成。

代码如下：
*/

#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib> 

using namespace std;

const int MAX = 10;
int A[MAX];

void ShellSort(int vec[], int n) ;

int main()
{
	for(int i=0; i<MAX; i++)
		A[i] = rand()%50 + 1;
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	ShellSort(A, MAX); //希尔排序
	
	for(int i=0; i<MAX; i++)
		cout << A[i] << " ";
	cout << endl;
	
	return 0;
}

void ShellSort(int vec[], int n) //希尔排序
{
    int i, j, gap;
    int temp;
    for (gap=n/2; gap>0; gap/=2)
    {
        for(i=gap; i<n; i++)
        {
		    temp= vec[i]; //语句1 
		    for(j=i; (j>=gap) && (temp<vec[j-gap]); j-=gap)//跳跃插入，跳跃距离为gap
			{
                vec[j]= vec[j-gap]; //语句2 
            }
			vec[j]= temp; //语句3 
        }
   }
}
