#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main() 
{
   bool a1, *p1;
   char a2, *p2;
   int a3, *p3;
   long int a4, *p4;
   long long a5, *p5;
   float a6, *p6;
   double a7, *p7;
   long double a8, *p8;
   enum COLOR{RED, GREEN=10, BLUE};
   COLOR a9 = BLUE;
   char *s1 = "abc";
   char *s2 = "abcdefghijklmnopqrstuvwxyz";
   char a10[10];
   
   //可以看到无论何种类型的指针均占4个字节，因为指针变量对应的存储空间是用来存储变量的地址的，地址的编码是统一的，与变量类型无关 
   cout << "bool " << sizeof(bool) << " " << sizeof(a1) << " " << sizeof(p1) << endl;
   cout << "char " << sizeof(char) << " " << sizeof(a2) << " " << sizeof(p2) << " " << sizeof(s1) << endl;
   cout << "int " << sizeof(int) << " " << sizeof(a3) << " " << sizeof(p3) << endl;
   cout << "long int " << sizeof(long int) << " " << sizeof(a4) << " " << sizeof(p4) << endl;
   cout << "long long " << sizeof(long long) << " " << sizeof(a5) << " " << sizeof(p5) << endl;
   cout << "float " << sizeof(float) << " " << sizeof(a6) << " " << sizeof(p6) << endl;
   cout << "double " << sizeof(double) << " " << sizeof(a7) << " " << sizeof(p7) << endl;
   cout << "long double " << sizeof(long double) << " " << sizeof(a8) << " " << sizeof(p8) << endl;
   cout << "enum COLOR " << sizeof(COLOR) << " " << sizeof(a9) << " " << a9 << endl;
   cout << "string " << sizeof(s1) << " " << s1 << endl;
   cout << "string " << sizeof(a10) << " " << a10 << endl;
   
   strncpy(a10, s1, sizeof(a10));
   a10[sizeof(a10)-1] = '\0';
   cout << "strncpy " << sizeof(a10) << " " << a10 << endl;
   strncpy(a10, s2, sizeof(a10));
   a10[sizeof(a10)-1] = '\0';
   cout << "strncpy " << sizeof(a10) << " " << a10 << endl;
       
   system("pause");
   return 0;
}
