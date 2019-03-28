/*
  문제 : https://www.acmicpc.net/problem/2098
  풀이 : 기본적으로 완전탐색이며 비트마스킹을 이용한 메모이제이션을 이용한 풀이를 함.
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
const int INF = 20000000;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { -1, 1 };
/* ----- -- ----- */
int n,dist[17][17],d[17][1 << 17];
int ans(int here, int visit) {
	if (visit == (1 << (n+1)) - 1) {
		if (!dist[here][1]) {
			return INF;
		}
        else {
		    return dist[here][1];
        }
	}
	if (d[here][visit]) {
		return d[here][visit];
	}
	
	int tmp = INF;
	FOR(next, 2, n) {
		if (visit & (1 << next) || !dist[here][next]) continue;
		tmp = min(tmp, dist[here][next]+ans(next, visit | (1 << next)));
	}
	return d[here][visit] = tmp;
}
int main() {
	SWS;
	cin >> n;
	FOR(i, 1, n) FOR(j, 1, n) cin >> dist[i][j];
	cout<<ans(1, 3);
	return 0;
}
