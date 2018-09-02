/*
	Name: 郊游活动
	Copyright: 
	Author: 
	Date: 20-09-17 15:23
	Description: 有n名同学参加学校组织的郊游活动，已知学校给这n名同学的郊游总经费为A元，
与此同时第i位同学自己携带了Mi元。为了方便郊游，活动地点提供B(≥n)辆自行车供人租用，租用第j辆自行车的价格为Cj元，
每位同学可以使用自己携带的钱或者学校的郊游经费，为了方便账务管理，每位同学只能为自己租用自行车，且不会借钱给他人，
他们想知道最多有多少位同学能够租用到自行车。（第四、五空2.5分，其余3分）
 本题采用二分法。对于区间[l, r]，我们取中间点mid并判断租用到自行车的人数能否达到mid。
 判断的过程是利用贪心算法实现的。
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAXN = 10;
int M[MAXN], C[MAXN];
int A, B, n;

int Cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

bool Check(int num) //看下标为num的人是否能租用到车 
{
	int count = 0, i = n - num - 1, j = 0; //i代表左边界，[i,n)共num+1个人 
	while (i < n)
	{
		if (C[j] > M[i])//累计欠费数值 
		{
			count += C[j] - M[i];
		}
		i++; j++;
	}
	return count <= A; //总经费能否支付欠费 
}

int main() 
{
	cin >> n >> B >> A;
	
	for (int i=0; i<n; i++)
		cin >> M[i];
	for (int i=0; i<B; i++)
		cin >> C[i];
 	qsort(M, n, sizeof(M[0]), Cmp);
 	qsort(C, B, sizeof(C[0]), Cmp);
 	
 //	for (int i=0; i<n; i++)
//		cout <<  M[i] << " ";
//	for (int i=0; i<B; i++)
//		cout <<  C[i] << " ";
 	
 	int ans = 0, mid, left = 0, right = n-1;
 	while (left <= right)
 	{
		mid = (left + right) / 2;
		if (Check(mid))
		{
			ans = mid; //注意mid是下标，而ans是人数 
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	
 	cout << ans+1 << endl; 
 	
    return 0;
}
