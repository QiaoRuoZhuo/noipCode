/*
	Name:  30_含k个3的数
	Copyright: 
	Author: 
	Date: 02-07-17 13:36
	Description: 30_含k个3的数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入两个正整数 m 和 k，其中1 < m < 100000，1 < k < 5 ，判断 m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。 

例如，输入： 
43833 3 
满足条件，输出YES。

如果输入：
39331 3 
尽管有3个3，但不能被19整除，也不满足条件，应输出NO。

输入
m 和 k 的值，中间用单个空格间隔。
输出
满足条件时输出 YES，不满足时输出 NO。
样例输入
43833 3
样例输出
YES
*/
#include<iostream>

using namespace std;

int main()
{
    int m, k;
    
    cin >> m >> k;
    
    if (m%19 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
	 	int s = 0;
        while (m > 0) //注意计算b和结束循环的技巧 
        {
		    s += (m%10 == 3);
		    m /= 10;
	    }
	    
	    if (s == k)
	    {
	        cout << "YES" << endl;
	    }
	    else
	    {
	        cout << "NO" << endl;
	    }
    }
			  
    return 0;
}
