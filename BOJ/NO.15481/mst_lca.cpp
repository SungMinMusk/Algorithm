/*
  문제 : https://www.acmicpc.net/problem/15481
  풀이 : 특정 간선을 가지는 MST의 가중치는 기본 MST에서 그 특정 간선에 속하는 정점의 경로에서 가장 큰 가중치를 가진 간선을 제거하고
   특정 간선을 추가해서 구하면 된다.
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
#include<unordered_map>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
#define unmap unordered_map
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
const int MAXK=18;
vector<pair<int,ll>> v[200001];
pair<int,ll> par[MAXK+1][200001];
vector<pair<pii, ll>> qst;
vector<pair<ll, pii>> edge;
int d[200001];
ll n, m,cost;
int _find(int a) {
	if (a == par[0][a].first) return a;
	else return par[0][a].first = _find(par[0][a].first);
}
void dfs(int pos, int depth) {
	d[pos] = depth;
	for (auto &i : v[pos]) {
		if (!d[i.first]) {
			par[0][i.first] = { pos,i.second };
			dfs(i.first, depth + 1);
		}
	}
}
int main() {
	SWS;
	cin >> n >> m;
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		qst.push_back({ { a,b }, c });
		edge.push_back({ c,{a,b} });
	}
	//MST 생성
	FOR(i, 1, n) par[0][i].first = i;
	sort(edge.begin(), edge.end());
	for (auto &i : edge) {
		int a = _find(i.second.first);
		int b = _find(i.second.second);
		if (a != b) {
			v[i.second.first].push_back({ i.second.second,i.first });
			v[i.second.second].push_back({ i.second.first,i.first });
			par[0][b].first = a;
			cost += i.first;
		}
	}
	// 뎁스 탐색
	par[0][1] = { 1,0 };
	dfs(1, 1);
	//
	FOR(i, 1, MAXK) {
		FOR(j, 1, n) {
			par[i][j].first = par[i - 1][par[i - 1][j].first].first;
			par[i][j].second =
				max(par[i - 1][par[i - 1][j].first].second,par[i - 1][j].second);
		}
	}
	//
	for (auto &z : qst) {
		ll tmp_cost = z.second;
		ll max_cost = 0;
		int a = z.first.first;
		int b = z.first.second;

		if (d[a] > d[b]) swap(a, b);
		for (int i = MAXK; i >= 0; i--) {
			if (a != b && d[par[i][b].first] >= d[a]) {
				max_cost = max(max_cost, par[i][b].second);
				b = par[i][b].first;
			}
		}
		for (int i = MAXK; i >= 0; i--) {
			if (a != b && par[i][b].first != par[i][a].first) {
				max_cost = max(max_cost, max(par[i][a].second, par[i][b].second));
				a = par[i][a].first;
				b = par[i][b].first;
			}
		}

		if(a!=b) max_cost = max(max_cost,max(par[0][a].second, par[0][b].second));
		cout << cost - max_cost + tmp_cost << endl;
	}
	return 0;
}
