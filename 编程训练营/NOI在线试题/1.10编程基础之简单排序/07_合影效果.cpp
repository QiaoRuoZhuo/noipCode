/*
	Name: 07_合影效果
	Copyright: 
	Author: 
	Date: 18-08-17 16:04
	Description: 07_合影效果
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
小云和朋友们去爬香山，为美丽的景色所陶醉，想合影留念。如果他们站成一排，男生全部在左（从拍照者的角度），并按照从矮到高的顺序从左到右排，
女生全部在右，并按照从高到矮的顺序从左到右排，请问他们合影的效果是什么样的（所有人的身高都不同）？
输入
第一行是人数n（2 <= n <= 40，且至少有1个男生和1个女生）。
后面紧跟n行，每行输入一个人的性别（男male或女female）和身高（浮点数，单位米），两个数据之间以空格分隔。
输出
n个浮点数，模拟站好队后，拍照者眼中从左到右每个人的身高。每个浮点数需保留到小数点后2位，相邻两个数之间用单个空格隔开。
样例输入
6
male 1.72
male 1.78
female 1.61
male 1.65
female 1.70
female 1.56
样例输出
1.65 1.72 1.78 1.70 1.61 1.56
*/
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

const int M = 40;
const int N = 300; //身高不会到300厘米 
double A[M];
int T[N+1];//桶排序专用数组（元素值为0-N的整数） 

int main()
{
	string sex;
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> sex >> A[i];
		if (sex == "male") //注意四舍五入 
			T[int((A[i]*1000+5)/10)] = 1;
		else
			T[int((A[i]*1000+5)/10)] = 2;
	}
	for (int i=0; i<=N; i++) //从低到高输出male 
	{
		if (T[i] == 1) 
			printf("%0.2f ", i/100.0); 
	}
	for (int i=N; i>=0; i--) //从高到低输出female 
	{
		if (T[i] == 2)
			printf("%0.2f ", i/100.0);
	}
	return 0;
}
