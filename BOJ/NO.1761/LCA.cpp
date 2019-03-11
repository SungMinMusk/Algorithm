/*
  문제 : https://www.acmicpc.net/problem/1761
  풀이 : 두 정점 사이의 거리는 각 정점에서 최저 공통 조상까지의 거리임을 이요한다.
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
#include<limits.h>
#define SWS ios_base::sync_with_stdio(0); 
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
const int MAXK = 16;
int n,m,a,b,c;
int d[40001];
vii v[40001];
pii par[MAXK + 1][40001];
void dfs(int pos, int depth)
{
	d[pos] = depth;
	for (auto &i : v[pos])
	{
		if (!d[i.first])
		{
			par[0][i.first] = {pos,i.second};
			dfs(i.first, depth + 1);
		}
	}
}
int main()
{
	SWS;
	cin >> n;
	FOR(i, 1, n-1)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	par[0][a] = { a,0 };
	dfs(a, 1);

	FOR(i,1,MAXK)
	{
		FOR(j, 1, n)
		{
			par[i][j].first = par[i - 1][par[i - 1][j].first].first;
			par[i][j].second =
				par[i - 1][par[i - 1][j].first].second + par[i - 1][j].second;
		}
	}
	//
	cin >> m;
	while (m--)
	{
		int cost = 0;
		cin >> a >> b;
		if (d[a] > d[b]) swap(a, b);
		for (int i = MAXK; i >= 0; i--)
		{
			if (a != b && d[par[i][b].first] >= d[a])
			{
				cost += par[i][b].second;
				b = par[i][b].first;
			}
		}
		for (int i = MAXK; i >= 0; i--)
		{
			if (a != b && par[i][b].first != par[i][a].first)
			{
				cost += par[i][b].second + par[i][a].second;
				a = par[i][a].first;
				b = par[i][b].first;
			}
		}
		if (a != b)
			cost += par[0][a].second + par[0][b].second;
		cout << cost << endl;
	}
	return 0;
}
