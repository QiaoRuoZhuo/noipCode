/*
	Name: 判断谁是第一名
	Copyright: 
	Author: 
	Date: 19-08-18 11:25
	Description: 有甲，乙，丙，丁四人参加竞赛，有一人得第一名，当问谁得第一名时，
甲说：”乙不是第一名 ，丁是第一名 。“乙说：”我不是第一名，
丙是第一名。“丙说：”甲不是第一名，乙是第一名。”丁说：“我不是第一名。”
  他们各个人说的不是全对，就是全错，编程分别用A，B，C，D代表甲，乙，丙，丁四人， 用A1，B1，C1，D1代表甲，乙，丙，丁四人所说的话，
  判断谁是第一名。
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

    int A,B,C,D,i=0;
    int A1,B1,C1,D1;
    
    for(A=1;A<=4;A++)
      for(B=1;B<=4;B++)
        for(C=1;C<=4;C++)
          for(D=1;D<=4;D++)
            {
                A1=(B!=1&&(D==1))||((B==1)&&D!=1);
                B1=(B!=1&&(C==1))||((B==1)&&C!=1);
                C1=(A!=1&&(B==1))||((A==1)&&B!=1);
                D1=(D==1)||(D!=1);
                
                if(A!=B&&A!=C&&A!=D && B!=C&&B!=D && C!=D && A1&&B1&&C1&&D1)
                {
                    printf("A=%d,B=%d,C=%d,D=%d\n",A,B,C,D);
                    if(A==1)
                         printf("The number is A\n");
                    else if(B==1)
                         printf("The number is B\n");
                    else if(C==1)
                         printf("The number is C\n");
                    else
                         printf("The number is D\n");
                }    

            }
     
      return 0;               
}                  
