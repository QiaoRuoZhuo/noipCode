#include<iostream>
#include<string>

using namespace std;

int main()
{
	const int MAX = 500;
	const double MIN = 66;
	int b = 1, c = 2, d = 3;
	double e = 4, f = 5, g = 6;
	int h = 7, i = 8, j = 9;
	int a[4] = {1,2,3,4};
	
	const int *pi = &MAX; 
	const double *pd = &MIN; 
	int *p = a;
	int *p1,*p2,*p3;
	double *p4,*p5, *p6;
	int *p7,*p8,*p9,*p10,*p11;  
	
	int &yb = b;
	int *pyb = &yb;
	
	p1 = &b;p2 = &c;p3 = &d;p4 = &e;p5 = &f;p6 = &g;p7 = &h;p8 = &i;p9 = &j; 
	
	cout << MAX << ": " << &MAX << "  " << *pi << endl;
	cout << MIN << ": " << &MIN << "  " << pd << endl;
	cout << b << ": " << &b << "  " << p1 << "  " << *p1 << endl;
	cout << c << ": " << &c << "  " << p2 << endl;
	cout << d << ": " << &d << "  " << p3 << endl;
	cout << e << ": " << &e << "  " << p4 << endl;
	cout << f << ": " << &f << "  " << p5 << endl;
	cout << g << ": " << &g << "  " << p6 << endl;
	cout << h << ": " << &h << "  " << p7 << endl;
	cout << i << ": " << &i << "  " << p8 << endl;
	cout << j << ": " << &j << "  " << p9 << endl;
	
	cout << yb << ": " << &yb << "  " << pyb << endl;
	
	cout << endl;
    p1++; p1++; p1++; p1++; *p = 999;
    cout << MAX << ": " << &MAX << "  " << *pi << endl;
	cout << MIN << ": " << &MIN << "  " << pd << endl;
	cout << b << ": " << &b << "  " << p1 << "  " << *p1 << endl;
	cout << c << ": " << &c << "  " << p2 << endl;
	cout << d << ": " << &d << "  " << p3 << endl;
	cout << e << ": " << &e << "  " << p4 << endl;
	cout << f << ": " << &f << "  " << p5 << endl;
	cout << g << ": " << &g << "  " << p6 << endl;
	cout << h << ": " << &h << "  " << p7 << endl;
	cout << i << ": " << &i << "  " << p8 << endl;
	cout << j << ": " << &j << "  " << p9 << endl;
    
    return 0;
}
