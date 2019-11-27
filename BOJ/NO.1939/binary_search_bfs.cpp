/*
  문제 : https://www.acmicpc.net/problem/1939
  풀이 : 화물의 중량을 이분탐색하며 BFS로 가능여부를 찾음.
*/

#include<bits/stdc++.h>
#define SWS ios_base::sync_with_stdio(0); cin.tie(0)
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
vii v[100001];
bool visit[100001];
int n, m, s, e;

bool bfs(int w) {
	memset(visit, 0, sizeof(visit));
	qi q;
	visit[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == e) {
			return true;
		}
		for (auto &i : v[now]) {
			if (!visit[i.first] && i.second >= w) {
				q.push(i.first);
				visit[i.first] = 1;
			}
		}
	}
	return false;
}
int main() {
	SWS;
	cin >> n >> m;
	FOR(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> s >> e;

	int l = 0, h = 1000000000;
	while (l <= h) {
		int mid = (l + h) / 2;
		if (bfs(mid)) l = mid + 1;
		else h = mid - 1;
	}
	cout << h;
	return 0;
}
