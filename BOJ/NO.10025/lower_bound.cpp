/*
  문제 : https://www.acmicpc.net/problem/10025
  풀이 : 양동이의 위치를 정렬하고, 모든점에서 +2k까지의 부분합을 구한다.
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
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int n, k;
ll sum[100001];
vii v; //포지션
bool compare(pii a, pii b)
{
	return a.first < b.first;
}
int main()
{
	cin >> n >> k;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(b,a));
	}
	sort(v.begin(), v.end());

	FOR(i, 0, v.size() - 1)
		sum[i+1] = v[i].second + sum[i];

	ll res = 0;
	FOR(i, 0, v.size() - 1)
	{
		auto it = upper_bound(v.begin(), v.end(), make_pair(v[i].first + 2*k,0),compare);
		int idx = it - v.begin();

		ll tmp = sum[idx] - sum[i];

		res = max(res, tmp);
	}
	cout << res;
	return 0;
}
