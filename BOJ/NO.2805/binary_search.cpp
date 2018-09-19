/*
	문제 : https://www.acmicpc.net/problem/2805
	-풀이-
	최고 높은 나무의 길이를 이분탐색한다.
	탐색에 완료 하지 못 하더라도 만족하는 최소값일때의 높이를 출력한다. 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[1000005];
long long n,m;
long long maxtree = -1;
long long res_tmp = 10000000000;
long long res_height = 1;
void ans(long long s,long long e)
{
	long long tmp = 0;
	long long mid = (s + e) / 2;
 	//베어지는 나무 길이 구함  
	for (int i = 0; i < n; i++)
	{
		if(arr[i] > mid)
			tmp += (arr[i] - mid);
	}
	//결과를 최소한 만족하는 경우 탐색 
	if (tmp >= m && tmp < res_tmp)
	{
		res_height = mid;
		res_tmp = tmp;
	}
	//종료 시점  
	if (tmp==m || s>=e)
	{
		cout << res_height;
		return;
	}
	//이분 탐색  
	if (tmp > m)
		ans(mid+1,e);
	else
		ans(s,mid-1);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxtree = max(arr[i], maxtree);
	}
	ans(0,maxtree);
	return 0;
}
