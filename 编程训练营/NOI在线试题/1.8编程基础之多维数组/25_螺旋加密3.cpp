/*
	Name: 25_螺旋加密
	Copyright: 
	Author: 
	Date: 31-08-17 14:37
	Description: 25_螺旋加密
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Chip和Dale发明了一种文本信息加密技术。他们事先秘密约定好矩阵的行数和列数。接着，将字符按如下方式编码：
1. 所有文本只包含大写字母和空格。
2. 每个字符均赋予一个数值：空格=0，A=1，B=2，……，Y=25，Z=26。
按照下图所示的方式，将每个字符对应数值的5位二进制数依次填入矩阵。最后用0将矩阵补充完整。
例如，对于信息“ACM”，行列数均为4时，矩阵将被填充为：
将矩阵中的数字按行连起来形成数字串，完成加密。例子中的信息最终会被加密为：0000110100101100。
输入
一行。首先是两个整数R(1≤R≤20)和C(1≤C≤20)，表示行数和列数。之后是一个只包含大写字母和空格的字符串。
字符串的长度≤(R*C)/5。R和C之间以及C和字符串之间均用单个空格隔开。
输出
一行，为加密后的二进制串。注意你可能需要用0将矩阵补充完整。
样例输入
4 4 ACM
样例输出
0000110100101100
*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int M = 20;
const int N = 20;
int A[N][M];
string Lib[26]={"00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001", "01010",
                "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011", "10100", 
				"10101", "10110", "10111", "11000", "11001", "11010"};
string s1, s2;

int main() 
{
	int n, m;
	cin >> n >> m;
	getline(cin, s1);
	for (int i=1; i<s1.length(); i++)//转换成二进制字符串，注意要去掉第一个空格
	{
		if (s1[i]==' ')
			s2 += "00000";
		else
			s2 += Lib[s1[i]-'A'];
	}
	 
	int t=0,len=s2.length(),left=-1,right=m-1,top=0,bottom=n-1;//分别代表左右上下边界 
	while (t < len)
	{
		if (top<=bottom)
		{
			for (int j=++left; t<len && j<=right; j++)//向右 
				A[top][j] = s2[t++] - '0';
		}
		if (left<=right)
		{
			for (int i=++top; t<len && i<=bottom; i++)//向下 
				A[i][right] = s2[t++] - '0';
		}
		if (top<=bottom)
		{
			for (int j=--right; t<len && j>=left; j--)//向左
				A[bottom][j] = s2[t++] - '0';
		}
		if (left<=right)
		{
			for (int i=--bottom; t<len && i>=top; i--)//向上 
				A[i][left] = s2[t++] - '0';
		}
	}
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout << A[i][j];
		}
	}
	cout << endl;
	
	return 0;	
} 
