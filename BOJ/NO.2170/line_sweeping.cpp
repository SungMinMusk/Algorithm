/*
  문제 : https://www.acmicpc.net/problem/2170
  풀이 : 라인스위핑을 이용한다. 좌측 좌표를 기준으로 정렬 후 그려진 선분을 갱신한다.
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
int n,res;
vii v;
int main() {
	SWS;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int l = v[0].first;
	int r = v[0].second;
	for (auto &i : v) {
		if (i.first <= r) {
			if(i.second >= r)
				r = i.second;
		}
		else {
			res += r - l;
			l = i.first;
			r = i.second;
		}
	}
	res += r - l;
	cout << res;
	return 0;
}
