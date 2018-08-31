#include<iostream>
#include<string>

using namespace std;

int main()
{
	int b = 1, c = 2, d = 3;
	double e = 4, f = 5, g = 6;
	int h = 7, i = 8, j = 9;
	int a[4] = {1,2,3,4};
	
	int *p = a;
	int *p1,*p2,*p3;
	double *p4,*p5, *p6;
	int *p7,*p8,*p9,*p10,*p11;  
	
	p1 = &b;p2 = &c;p3 = &d;p4 = &e;p5 = &f;p6 = &g;p7 = &h;p8 = &i;p9 = &j; 
	
	cout << b << ": " << &b << "  " << p1 << endl;
	cout << c << ": " << &c << "  " << p2 << endl;
	cout << d << ": " << &d << "  " << p3 << endl;
	cout << e << ": " << &e << "  " << p4 << endl;
	cout << f << ": " << &f << "  " << p5 << endl;
	cout << g << ": " << &g << "  " << p6 << endl;
	cout << h << ": " << &h << "  " << p7 << endl;
	cout << i << ": " << &i << "  " << p8 << endl;
	cout << j << ": " << &j << "  " << p9 << endl;
	
	for (int i=0; i<4; i++)
	{
		cout << a[i] << ": " << &a[i] << "  ";
	}
	cout << endl;cout << endl;
	
	p1++;
	cout << p1 << " " << *p1 << endl;
	*p1 = 1;
	cout << p1 << " " << *p1 << endl;
	
	//cout << a << endl;
//	cout << p << endl;
//	cout << &a << endl;
//	cout << &p << endl;
//	cout << &a[0] << endl;
//	cout << a[0] << endl;
    
    return 0;
}
