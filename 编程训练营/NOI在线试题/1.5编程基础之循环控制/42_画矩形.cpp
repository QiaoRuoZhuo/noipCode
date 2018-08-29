/*
	Name: 42_画矩形
	Copyright: 
	Author: 巧若拙 
	Date: 03-07-17 21:14
	Description: 42_画矩形
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
根据参数，画出矩形。

输入
输入一行，包括四个参数：前两个参数为整数，依次代表矩形的高和宽（高不少于3行不多于10行，宽不少于5列不多于10列）；第三个参数是一个字符，表示用来画图的矩形符号；第四个参数为1或0，0代表空心，1代表实心。
输出
输出画出的图形。
样例输入
7 7 @ 0
样例输出
@@@@@@@
@     @
@     @
@     @
@     @
@     @
@@@@@@@
*/
#include<iostream>

using namespace std;

void DrawRectangle(int h, int w, char c, bool f);

int main()
{
    int h, w, flag;
    char c, ch;
    
//    cin >> h >> w >> c >> flag;
//    ch = (flag == 0) ? ' ' : c;
//    
//    for (int j=0; j<w; j++)//输出第一行
//		cout << c;
//	cout << endl;
//	
//	for (int i=2; i<h; i++) //输出中间h-2行
//	{
//	 	cout << c;
//	 	for (int j=2; j<w; j++)//输出w-2个框内符号 
//			cout << ch;
//	    cout << c << endl;
//	} 
//	
//	for (int j=0; j<w; j++)//输出第h行
//		cout << c;
//	cout << endl;
	
	DrawRectangle(5, 7, 57, 0);
			  
    return 0;
}

void DrawRectangle(int h, int w, char c, bool f)
{
	char ch = (f == 0) ? ' ' : c;
    
    for (int j=0; j<w; j++)//输出第一行
		cout << c;
	cout << endl;
	
	for (int i=2; i<h; i++) //输出中间h-2行
	{
	 	cout << c;
	 	for (int j=2; j<w; j++)//输出w-2个框内符号 
			cout << ch;
	    cout << c << endl;
	} 
	
	for (int j=0; j<w; j++)//输出第h行
		cout << c;
	cout << endl;
}
