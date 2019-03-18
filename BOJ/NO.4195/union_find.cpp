/*
  문제 : https://www.acmicpc.net/problem/4195
  풀이 : unordered_map로 string을 키와 값으로 사용한다. union-find를 사용 집합을 만든다.
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
unmap<string,string> par;
unmap<string, int>cnt;
int t, f;
string _find(string a) {
	if (a == par[a]) return a;
	return par[a] = _find(par[a]);
}
int main() {
	SWS;
	cin >> t;
	while (t--) {
		par.clear();
		cin >> f;
		FOR(i, 1, f) {
			string a, b;
			cin >> a >> b;
			if (par.find(a) == par.end()) {
				par[a] = a;
				cnt[a] = 1;
			}
			if (par.find(b) == par.end()) {
				par[b] = b;
				cnt[b] = 1;
			}
			a = _find(a);
			b = _find(b);
			if (a != b) {
				cnt[a] += cnt[b];
				par[b] = a;
			}
			cout << cnt[a] << endl;
		}
	}
	return 0;
}
