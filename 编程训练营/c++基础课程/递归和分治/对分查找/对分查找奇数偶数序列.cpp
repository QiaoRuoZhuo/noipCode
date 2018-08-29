/*
	Name: 对分查找奇数偶数序列 
	Copyright: 
	Author: 
	Date: 29-08-18 22:28
	Description: 数组 a 为一组正整数，奇数在前，偶数在后。奇数与偶数已分别按升序排序。
	依据对分查找思想：设计一个在数组 a 中查找数据 Key 的程序。填写语句1-5。 
如下：
*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	int a[10] = {1,3,5,7,9,2,4,6,8,10};
	int key;
	int i=0, j=9, m;
	cin >> key; 
	
	while (i <= j)
	{
		m = (i + j) / 2;
		if (a[m] == key)
			break; //语句1 
		if (a[m]%2==1 && key%2==0)
			i = m + 1; //语句2 
		else if (a[m]%2==0 && key%2==1)
			j = m - 1; //语句3
		else
		{
			if (a[m] < key)
				i = m + 1; //语句4 
			else
				j = m - 1;	 //语句5
		}
	}
	if (i <= j)
		cout << "位置：" << m << endl;
	else
		cout << "未找到" << endl;
		
	return 0;
}
