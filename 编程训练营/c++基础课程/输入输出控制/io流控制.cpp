#include<iostream>
#include<iomanip>

using namespace std;

int main() 
{
   	double b1 = 60.0;
	cout << b1 / 5 << endl;
	cout << setiosflags(ios::showpoint) << b1 / 5 << endl;
	
	float a1 = 123.4567890123456789;
	double a2 = 123.4567890123456789;
	
	cout << a1 << endl;
	cout << setprecision(10) << a1 << endl;
	cout << setiosflags(ios::fixed) << setprecision(10) << a1 << endl;
	cout << setprecision(6); //恢复成原默认设置，小数点后保留6位 
	cout << a1 << endl;
	
	cout << a2 << endl;
	cout << setprecision(10) << a2 << endl;
	cout << setiosflags(ios::fixed) << setprecision(10) << a2 << endl;
	cout << setprecision(6); //恢复成原默认设置 
	
	const float pi1 = 3.141592653;
	const double pi2 = 3.141592653;
	cout << pi1 << "  " << pi2 << endl;
	   
	system("pause");
	return 0;
}
