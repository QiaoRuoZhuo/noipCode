/*
	Name: Êä³öASCIIÂë¶ÔÕÕ±í
	Copyright: 
	Author: 
	Date: 17-08-18 16:47
	Description: 
*/
#include<iostream>
#include<string>

using namespace std;

int main() 
{
	cout << int(' ') <<  "  " << int('\t')<<  "  " << int('\a')<<  "  " << int('\b')<<  "  " << int('\r')<<  "  " << int('\n') ;
	cout  << endl; 
 	for (int i=0; i<=127; i++)
 	{
	 	cout << i << ": " << char(i) << endl;
	}
	
	cout << endl;
	
	return 0;
}
