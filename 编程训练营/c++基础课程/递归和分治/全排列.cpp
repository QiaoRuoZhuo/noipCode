#include<iostream>
#include<string>
#include<ctime>

using namespace std;

string s;
int sum = 0;
void F(int low, int high)
{
	if (low == high)
		cout << ++sum << ": " << s << endl;
    else
    {
		for (int i=low; i<high; i++)
		{   
			swap(s[i], s[low]); 
			F(i+1, high);
			swap(s[i], s[low]); 
		}
	}
}

int main() 
{
	cin >> s;
	F(0, s.length());
 	
    return 0;
}
