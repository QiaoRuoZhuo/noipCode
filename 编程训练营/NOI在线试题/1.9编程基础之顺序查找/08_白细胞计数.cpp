/*
	Name:08_白细胞计数 
	Copyright: 
	Author: 
	Date: 16-08-17 11:02
	Description:08_白细胞计数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
医院采样了某临床病例治疗期间的白细胞数量样本n份，用于分析某种新抗生素对该病例的治疗效果。
为了降低分析误差，要先从这n份样本中去除一个数值最大的样本和一个数值最小的样本，然后将剩余n-2个有效样本的平均值作为分析指标。
同时，为了观察该抗生素的疗效是否稳定，还要给出该平均值的误差，即所有有效样本（即不包括已扣除的两个样本）与该平均值之差的绝对值的最大值。 
现在请你编写程序，根据提供的n个样本值，计算出该病例的平均白细胞数量和对应的误差。
输入
输入的第一行是一个正整数n（2 < n <= 300），表明共有n个样本。
以下共有n行，每行为一个浮点数，为对应的白细胞数量，其单位为10^9/L。数与数之间以一个空格分开。
输出
输出为两个浮点数，中间以一个空格分开。分别为平均白细胞数量和对应的误差，单位也是10^9/L。计算结果需保留到小数点后2位。
样例输入
5
12.0
13.0
11.0
9.0
10.0
样例输出
11.00 1.00 

算法分析：
需要求2次最值，要考虑所有元素均相等的特殊情形，有点繁琐，需要细心。 
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int M = 300;

int main() 
{
	double A[M] = {0};
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	
	int pmin = 0, pmax = 0;
	for (int i=1; i<n; i++)
	{
		if (A[i] > A[pmax])
			pmax = i;
		else if (A[i] < A[pmin])
			pmin = i;
	}
	
	if (pmin == pmax) //所有元素均相等
	{
		printf("%0.2lf 0.00\n", A[0]);
		return 0;	
	} 
	
	double s = 0;
	for (int i=0; i<n; i++)
	{
		if (i != pmax && i != pmin) 
			s += A[i];
	}
	s /= n - 2; //求有效平均值 
	
	A[pmin] = A[pmax] = s;//修改原来的最值，寻找新的最值用来求最大误差 
	pmin = 0, pmax = 0;
	for (int i=1; i<n; i++)
	{
		if (A[i] > A[pmax])
			pmax = i;
		else if (A[i] < A[pmin])
			pmin = i;
	}
	printf("%0.2lf %0.2lf\n", s, max(A[pmax]-s, s-A[pmin]));
	
	return 0;	
} 
