/*
	Name: 荷兰国旗算法 
	Copyright: 
	Author: 
	Date: 06-10-16 16:16
	Description: 
	一排木桶里分别装有红白蓝三色小球（分别用0,1,2表示），如何让所有的'0'出现在前面，所有的'1'在中间，所有的'2'在最后。
要求：要求空间复杂度为O(1),只许遍历一遍字符串数组。 
之所以叫荷兰国旗，是因为我们可以将红白蓝三色小球想象成条状物，有序排列后正好组成荷兰国旗。
*/
#include <iostream>
#include <cstdlib>

using namespace std;

void Swap(int &a, int &b);
void TheDutchFlag(int lib[], int n, int min, int max);

int main()
{
	const int COLORNUM = 3;
	int color[COLORNUM] = {0, 1, 2};
	
	const int MAXSIZE = 30;
	int lib[MAXSIZE] = {0};
	
	for (int i=0; i<MAXSIZE; i++) //随机生成3色小球 
	{
		lib[i] = color[rand() % COLORNUM];
	}
	
	for (int i=0; i<MAXSIZE; i++)
	{
		cout << lib[i] << " ";
	}
	cout << endl;
		
	TheDutchFlag(lib, MAXSIZE, color[0], color[2]);
	
	for (int i=0; i<MAXSIZE; i++)
	{
		cout << lib[i] << " ";
	}
	cout << endl;
    
    return 0;
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void TheDutchFlag(int lib[], int n, int min, int max)
{
	int left = 0;
	int right = n - 1;
	
	while (lib[left] == min) //确定左边界的位置 
	{
		left++;
	}
		
	while (lib[right] == max) //确定右边界的位置 
	{
		right--;
	}
		
	int i = left;
	while (i <= right)
	{
		if (lib[i] == min) //是最小值，则与左区域的元素交换，同时左边界右移，游标也右移 
		{
			Swap(lib[i++], lib[left++]);
		}
		else if (lib[i] == max) //是最大值，则与右区域的元素交换，同时右边界左移，游标不动 
		{
			Swap(lib[i], lib[right--]);
		}
		else //既不是最大值也不是最小值，则该元素属于中间区域，不做任何交换，游标右移 
		{
			i++;
		}
	}
}

