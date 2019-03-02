/*
  문제 : https://www.acmicpc.net/problem/1074
  풀이 : 모든 구간을 탐색하려 하면 TLE가 난다. 탐색 할 곳만 하자.
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
#include<float.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { -1, 1 };
/* ----- -- ----- */
int N, n, r, c, cnt ,res;
void ans(pii s, int len)
{
	if (s.first <= r && r < (s.first + len) && 
		s.second <= c && c < (s.second + len))
	{
		if (len == 1)
		{
			cnt++;
			if (s == make_pair(r, c)) res = cnt;
			return;
		}
		len /= 2;
		ans(s, len);
		ans({ s.first,s.second + len }, len);
		ans({ s.first + len,s.second }, len);
		ans({ s.first + len,s.second + len }, len);
	}
	else
	{
		cnt += len * len;
		return;
	}
}
int main()
{
	SWS;
	cin >> N >> r >> c;
	n = 1;
	FOR(i, 1, N) n <<= 1;
	ans({ 0,0 }, n);
	cout << res-1;
	return 0;
}
