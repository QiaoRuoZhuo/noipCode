/*
  Name: 
  Copyright: 
  Author: 
  Date: 01-04-07 18:00
  Description: 
	1.  给定等式  A B C D E     其中每个字母代表一个数字，且不同数字对应不
                      D F G     同字母。编程求出这些数字并且打出这个数字的
             +        D F G     算术计算竖式。

             ───────

                  X Y Z D E

*/

#include <iostream>

using namespace std;

int main()
{
	int A, B, C, D, E, F, G, X, Y, Z;
	int m, n, sum;
	
	for (A=0; A<10; A++)
	for (B=0; B<10; B++)
	if (A!=B)
	for (C=0; C<10; C++)
	if (A!=C&&B!=C)
	for (D=0; D<10; D++)
	if (A!=D&&B!=D&&C!=D)
	for (E=0; E<10; E++)
	if (A!=E&&B!=E&&C!=E&&D!=E)
	for (F=0; F<10; F++)
	if (A!=F&&B!=F&&C!=F&&D!=F&&E!=F)
	for (G=0; G<10; G++)
	if (A!=G&&B!=G&&C!=G&&D!=G&&E!=G&&F!=G)
	for (X=0; X<10; X++)
	if (A!=X&&B!=X&&C!=X&&D!=X&&E!=X&&F!=X&&G!=X)
	for (Y=0; Y<10; Y++)
	if (A!=Y&&B!=Y&&C!=Y&&D!=Y&&E!=Y&&F!=Y&&G!=Y&&X!=Y)
	{
		Z = 45 - A - B - C - D - E - F - G - X - Y;
		m = A*10000 + B*1000 + C*100 + D*10 + E;
		n = D*100 + F*10 + G;
		sum = X*10000 + Y*1000 + Z*100 + D*10 + E;
		
		if (m + n * 2 == sum)
		{
			cout <<" "<<A<<B<<C<<D<<E<<endl;
			cout <<"   "<<D<<F<<G<<endl;
			cout <<"+  "<<D<<F<<G<<endl;
			cout <<"_____________"<<endl;
			cout <<" "<<X<<Y<<Z<<D<<E<<endl;
			cout << endl;
		}
	}
		 
	getchar();
	return 0;
}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int A, B, C, D, E, F, G, X, Y, Z;
//	int m, n, sum;
//	
//	B = 9;
//	Y = 1;
//	for (G=0; G<6; G+=5)
//		for (F=0; F<6; F+=5)
//		if (F!=G)
//			for (A=2; A<9; A++)
//			if (A!=G && A!=F)
//					for (C=2; C<9; C++)
//					if (C!=A && C!=G && C!=F)
//						for (D=2; D<9; D++)
//						if (D!=A && D!=C && D!=G && D!=F)
//							for (E=2; E<9; E++)
//							if (E!=A && E!=C && E!=D && E!=G && E!=F)
//							{
//								X = A + 1;
//								if (B!=X && C!=X && D!=X && E!=X && F!=X && G!=X)
//								{
//									Z = 45 - A - B - C - D - E - F - G - X - Y;
//								
//									m = A*10000 + B*1000 + C*100 + D*10 + E;
//									n = D*100 + F*10 + G;
//									sum = X*10000 + Y*1000 + Z*100 + D*10 + E;
//									
//									if (m + n * 2 == sum)
//									{
//										cout <<" "<<A<<B<<C<<D<<E<<endl;
//						                cout <<"   "<<D<<F<<G<<endl;
//						                cout <<"+  "<<D<<F<<G<<endl;
//						                cout <<"_____________"<<endl;
//						                cout <<" "<<X<<Y<<Z<<D<<E<<endl;
//						                cout << endl;
//									}	
//								}
//							}
//	getchar();
//	return 0;
//}

//#include <iostream>
//#include <time.h>
//using namespace std;
//
//int main( )
//{
//      time_t startTime;
//      time_t endTime;
//      int a,b,c,d,e,f,g,x,y,z;
//      int count=1;
//      
//      time(&startTime);
//      for (a=0; a<9; a++)
//      {
//      for (b=0; b<=9; b++)
//      {
//      if(b!=a)
//      for (c=0; c<=9; c++)
//      {
//      if(c!=a && c!=b)
//      for (d=0; d<=9; d++)
//      {
//      if(d!=a && d!=b && d!=c)
//      {
//      for (e=0; e<=9; e++)
//      {
//      if(e!=a && e!=b && e!=c && e!=d)
//      for (f=0; f<=5; f+=5)
//      {
//      if(f!=a && f!=b && f!=c && f!=d && f!=e)
//      for (g=0; g<=5; g+=5)
//      {
//      if(g!=a && g!=b && g!=c && g!=d && g!=e && g!=f)
//      for (y=0; y<=9; y++)
//      {
//      if(y!=a && y!=b && y!=c && y!=d && y!=e && y!=f && y!=g)
//      {
//            x = a + 1;
//            if(x!=b && x!=c && x!=d && x!=e && x!=f && x!=g && x!=y)
//            {
//                  z = 45 -a-b-c-d-e-f-g-x-y;
//                  if ((a*10000+b*1000+c*100+d*10+e)+(d*100+f*10+g)+(d*100+f*10+g) == (x*10000+y*1000+z*100+d*10+e))
//                  {
//                        cout << count++ << ":" << endl;
//                        cout <<" "<<a<<b<<c<<d<<e<<endl;
//                        cout <<"   "<<d<<f<<g<<endl;
//                        cout <<"+  "<<d<<f<<g<<endl;
//                        cout <<"_____________"<<endl;
//                        cout <<" "<<x<<y<<z<<d<<e<<endl;
//                        cout << endl;
//                  }
//            }
//      }
//      }
//      }
//      }
//      }
//      }
//      }
//      }
//      }
//      }
//      
//      time(&endTime);
//
//      cout << "time = " << difftime(endTime, startTime) << endl;
//      getchar();
//      return 0;
//}


