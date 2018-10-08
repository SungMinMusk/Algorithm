/*
  문제 : https://www.acmicpc.net/problem/2512
  풀이 : 이분탐색을 이용하여 원하는 최대의 결과를 빠르게 찾는다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<math.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> sti;
typedef queue<int> qi;
typedef vector<int> vi;
const int INF = 0x7fffffff;
/* -----구현부----- */
int limit = -1, res = 0,mav;
int n;
vi v;
int ans(int a)
{
	int r = 0;
	FOR(i, 0, v.size() - 1)
	{
		if (v[i] >= a) r += a;
		else r += v[i];
	}
	return r;
}
int main()
{
	cin >> n;
	FOR(i, 1, n)
	{
		int a;
		cin >> a;
		limit = max(limit, a);
		v.push_back(a);
	}
	cin >> mav;
	int s = 1, e = limit;
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (ans(m) <= mav)
			s = m + 1;
		else
			e = m - 1;
	}
	cout << s-1;

	return 0;
}
