/*
	Name: 一元三次方程求解
	Copyright: 
	Author: 
	Date: 22-01-18 15:08
	Description: 一元三次方程求解

总时间限制: 1000ms 内存限制: 65536kB 
描述 
有形如：ax3+bx2+cx+d=0 这样的一个一元三次方程。
给出该方程中各项的系数(a，b，c，d 均为实数)，并约定该方程存在三个不同实根(根的范围在-100至100之间)，
且根与根之差的绝对值>=1。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后2位。

输入 
一行，包含四个实数a，b，c，d，相邻两个数之间用单个空格隔开。 
输出 
一行，包含三个实数，为该方程的三个实根，按从小到大顺序排列，相邻两个数之间用单个空格隔开，精确到小数点后2位。 
样例输入 
1.0 -5.0 -4.0 20.0 
样例输出 
-2.00 2.00 5.00
*/

#include<iostream>  
#include<cmath>  
#include<cstdio> 
#include<cstdlib>  
  
using namespace std;  

double f(double x); 
void Fun1(); //枚举法，枚举每一个解看是否成立。
void Fun2(); //枚举法，枚举每一个解看是否成立。
void Fun3(); //分治法，枚举区间，看解存在于哪个区间里，逐渐缩小区间范围，确定解。

double a,b,c,d;

int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    Fun1();
    Fun2();
    Fun3();
} 

void Fun1()
{
	for (double x=-100;x<=100;x+=0.01)
    {
        if (abs(a*x*x*x+b*x*x+c*x+d)<=0.000001)//相当于f(x-0.0005)*f(x+0.0005)<=0
            printf("%.2f ",x);
    }
    cout << endl;
}

void Fun2()
{
	for (double x=-100;x<=100;x+=0.01)
    {
        if (f(x-0.0005)*f(x+0.0005)<=0) 
            printf("%.2f ",x);
    }
    cout << endl;
}

void Fun3()
{
	double x,x1,x2,xx;
	for (x=-100;x<=100;x+=1)
    { 
        x1=x;x2=x+1;
        if (f(x1)==0) 
			printf("%.2f ",x1);
        else if (f(x1)*f(x2)<0)
        {
            while (x2-x1>=0.001)
            {
                xx=(x1+x2)/2;
                if ((f(x1)*f(xx))<=0)
                    x2=xx;
                else x1=xx;
            }
            printf("%.2f ",x1);
        }
    }
    cout << endl;
}

double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
