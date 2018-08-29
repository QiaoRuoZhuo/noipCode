/*
	Name:  08_病人排队
	Copyright: 
	Author: 
	Date: 17-08-17 09:53
	Description: 08_病人排队
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
病人登记看病，编写一个程序，将登记的病人按照以下原则排出看病的先后顺序： 
1. 老年人（年龄 >= 60岁）比非老年人优先看病。 
2. 老年人按年龄从大到小的顺序看病，年龄相同的按登记的先后顺序排序。 
3. 非老年人按登记的先后顺序看病。
输入
第1行，输入一个小于100的正整数，表示病人的个数；
后面按照病人登记的先后顺序，每行输入一个病人的信息，包括：一个长度小于10的字符串表示病人的ID（每个病人的ID各不相同且只含数字和字母），
一个整数表示病人的年龄，中间用单个空格隔开。
输出
按排好的看病顺序输出病人的ID，每行一个。
样例输入
5
021075 40
004003 15
010158 67
021033 75
102012 30
样例输出
021033
010158
021075
004003
102012
*/
#include<iostream>
#include<string>

using namespace std;

const int M = 100;
string ID[M];
int Age[M], Old[M];

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> ID[i] >> Age[i];
	//获取第一个老年人序号 
	int f = 0;
	while (f < n && Age[f] < 60)
		f++;
	Old[0] = f;
	
	int len = 1, low, high, mid;
	for (int i=f+1; i<n; i++)//对老年人插入排序（存储序号） 
	{
		if (Age[i] >= 60)
		{
			low = 0;
			high = len-1;
			while(low <= high) //折半查找插入位置
			{
				mid = (low + high)/2;
				if (Age[Old[mid]] < Age[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j=len++; j>low; j--)
		    {
				Old[j] = Old[j-1];
		    }
		    Old[low] = i; //插入序号i 
		}
	}
	
	if (f == n)//全是年轻人 
	{
		for (int i=0; i<n; i++)//输出年轻人 
			cout << ID[i] << endl;
	}
	else if (len == n)//全是老年人 
	{
		for (int i=0; i<len; i++)//输出老年人 
			cout << ID[Old[i]] << endl;
	}
	else 
	{
		for (int i=0; i<len; i++)//输出老年人 
			cout << ID[Old[i]] << endl;
		for (int i=0; i<n; i++)//输出年轻人 
		{
			if (Age[i] < 60)
				cout << ID[i] << endl;
		}
	}
	
    return 0;
}
