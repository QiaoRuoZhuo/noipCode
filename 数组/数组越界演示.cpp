#include<iostream>
#include<string>

using namespace std;

int main()
{
	const int MAX = 5;
	int a[MAX] = {0};
	int b[MAX] = {0};
	
	for (int i=0; i<MAX; i++)
	{
		a[i] = 100+i;
		b[i] = 200+i;
	}
	
	cout << "a :" << endl;
	for (int i=0; i<MAX; i++)
	{
		cout << a[i] << ": " << &a[i] << " ";
	}
	cout << endl;
	cout << "b :" << endl;
	for (int i=0; i<MAX; i++)
	{
		cout << b[i] << ": " << &b[i] << " ";
	}
	cout << endl;
	
	//数组越界 
	a[-1] = 2345;
    b[5] = 999;
    cout << "a :" << endl;
	for (int i=0; i<MAX; i++)
	{
		cout << a[i] << ": " << &a[i] << " ";
	}
	cout << endl;
	cout << "b :" << endl;
	for (int i=0; i<MAX; i++)
	{
		cout << b[i] << ": " << &b[i] << " ";
	}
	cout << endl;
    
    return 0;
}
