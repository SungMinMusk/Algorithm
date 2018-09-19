/*
  문제 : http://codeforces.com/contest/1029/problem/B
  풀이 : 최장 증가 수열의 응용 문제이다. 이분탐색을 이용하며, 비교연산자를 재정의한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int,int> > stii;
typedef queue<pair<int,int> > qii;
typedef priority_queue<pair<int,int> > pqii;
typedef pair<int,int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int > >vpii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[210000];
int d[210000];
bool compare(int a, int b)
{
	return 2*a >= b;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	vi v;
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		int size = v.size();
		if (arr[i] <= 2 * v[size - 1])
			v.push_back(arr[i]);
		else
		{
			vi::iterator it;
			it = lower_bound(v.begin(), v.end(),arr[i],compare);
			*it = arr[i];
		}
	}
	
	cout << v.size();
	
	return 0;
}
