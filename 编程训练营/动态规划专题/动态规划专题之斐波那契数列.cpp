
/* 
  Name: 1755_菲波那契数列 
  Copyright:  
  Author:  
  Date: 22-03-17 08:56 
  Description: 1755:菲波那契数列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。
给出一个正整数a，要求菲波那契数列中第a个数是多少。
输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 <= a <= 20)
输出
输出有n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小
样例输入
4
5
2
19
1
样例输出
5
1
4181
1

算法思路：
算法1（递归算法）： 利用数列本身的规律：F(n) = F(n-1) + F(n-2)；使用递归，可以写出简洁的代码。
算法2（备忘录）：递归的缺点是每次都要调用自身，对时间和空间的消耗大，而且存在大量的重复计算，效率低下；
如果能把递归过程中子问题的解保存起来，就可以避免大量的重复计算，可以大大提高效率。 
算法3（动态规划）：备忘录算法（也叫记忆化搜索）和递归算法一样，都是采用自顶向下的思考方法，
为解决一个大问题，先递归地解决较小的问题，再把小问题的解返回来。虽然备忘录算法避免了重复计算，
但是仍然需要递归的调用自身，效率仍然低。
无论是递归算法还是备忘录算法，都利用了数列的递推公式，
我们可以采用自底向上的思考方法来理解该递推公式，即先求出较小小问题的解，再逐步向上求出较大问题的解，
直到求出最终解。这种自底向上，把每一个子问题的解都保存起来的方法就是动态规划。 
算法3（动态规划降维优化）：算法3中，我们使用1个一维数组把每一个子问题的解都保存起来了，
但是仔细观察我们可以发现每个元素的值只由其前面的2个元素决定，再往前的元素已经没有用处了，
完全没有继续保存的必要，所以我们只需要3个变量cur,pre1和pre2分别存储F(n)，F(n-1)和F(n-2)就行了，
随着n的增大，不断迭代更新cur,pre1和pre2的值，用几个变量来代替一维数组，就实现了降维优化。 
*/  
#include<iostream>  
#include<cmath>  
  
using namespace std;  
  
const int MAXN = 50;  
int F1[MAXN];//Fibonacci数列 
int F2[MAXN] = {0, 1};//Fibonacci数列  
  
int Fibonacci(int n); //递归算法 
int Fibonacci_1(int n); //备忘录：自顶而下  
int Fibonacci_2(int n);//动态规划：自底而上  
int Fibonacci_3(int n);//动态规划：降维优化
  
int main()   
{  
    int n, a;  
	
	Fibonacci_2(MAXN); //动态规划，先记录所有子问题的解 
	cin >> n;
	for (int i=0; i<n; i++)  
    {  
		cin >> a;
        cout << Fibonacci(a) << endl;
        cout << Fibonacci_1(a) << endl;
        cout << F2[a] << endl;
    	cout << Fibonacci_3(a) << endl;
    }  
      
    return 0;  
}  
  
int Fibonacci(int n) //递归算法 
{  
    if (n == 0 || n == 1)  //递归出口 
    {  
        return n;  
    }  
    
    return Fibonacci(n-1) + Fibonacci(n-2); 
}  

int Fibonacci_1(int n) //备忘录：自顶而下  
{  
    if (F1[n] > 0)  //如果这个问题曾经计算过，直接返回   
    {  
        return F1[n];  
    }
	if (n == 0 || n == 1)  //递归出口 
    {  
        F1[n] = n;  
    }   
    else
    {
		F1[n] = Fibonacci_1(n-1) + Fibonacci_1(n-2);  
	}
    
    return F1[n];
}  
  
int Fibonacci_2(int n)//动态规划：自底而上  
{  
    for (int i=2; i<=n; i++)  
    {  
        F2[i] = F2[i-1] + F2[i-2];  
    }  
      
    return F2[n];  
}  

int Fibonacci_3(int n)//动态规划：降维优化 
{  
	int cur, pre1, pre2;
	
	pre1 = 0, cur = pre2 = 1; //初始化 
    for (int i=2; i<=n; i++) //自底向上，迭代更新变量值 
    {  
		cur = pre1 + pre2;  
        pre1 = pre2;
        pre2 = cur;
    }  
      
    return cur;  
}  
