#include<iostream>
#include<string>

using namespace std;

int main() 
{
 	int s = 0;
 	
 	for (int i=1; i<=100; i++)
 	{
	 	if (i % 5 == 0 || i % 6 == 0)
	 	{
	        s++;
        }
	}
	
	cout << s << endl;
	
	system("pause");
	return 0;
}
