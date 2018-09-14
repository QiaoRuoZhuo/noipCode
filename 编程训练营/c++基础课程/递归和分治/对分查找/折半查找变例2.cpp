/*
	Name: 折半查找变例2 
	Copyright: 
	Author: 
	Date: 20-08-18 16:53
	Description: 一直数组有序递增，有100个元素a[1]到a[100]，输入变量find（确保能找到），
	则程序运行后，变量cs的值最大可以是（ C ）
	A 7   B 13  C 14  D 50 
*/
#include<iostream>  
#include<cmath>  
#include<ctime>  
#include<cstdlib>  

using namespace std;

int BinarySearch(int x); //递减跳跃查找值为x的元素，返回查找的次数

int main() 
{
	for (int i=1; i<=100; i++)
		cout << i << ":" << BinarySearch(i) << " ";
		
    return 0;
}

int BinarySearch(int x) //递减跳跃查找值为x的元素，返回查找的次数
{
	int a[101] = {0};
	for(int i=0; i<101; i++)
		a[i] = i;
		
	int len = 14;//为什么是14？因为1+2+3+...+14 = 105 > 100；而 1+2+3+...+13 = 91 < 100
	int left = 0, right = len, cs = 0;
	
	while (right <= 100)
	{
		cs++;
		if (a[right] == x)//找到x 
			break;
		else if (a[right] > x) //右边界左移 
		{
			right--;
			if (left == right)//左右边界重合了，只剩下一个元素x 
				break;
		}
		else //左边界右移，右边界再向右移动len个位置 
		{
			left = right;
			len--;
			right += (right+len > 100) ? 1 : len;
		}
	}
	return cs;
}
