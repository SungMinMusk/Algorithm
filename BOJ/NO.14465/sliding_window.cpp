/*
  문제 : https://www.acmicpc.net/problem/14465
  풀이 : 데크의 사이즈를 K로 유지하면서 고장난 신호등의 갯수를 갱신한다. 슬라이딩 윈도기법
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
int n,m,k;
bool arr[100001];
int main() {
	SWS;
	cin >> n >> m >> k;
	while(k--) {
		int a;
		cin >> a;
		arr[a] = 1;
	}

	int cnt = 0,res=INF;
	deque<bool> q;
	FOR(i, 1, n) {
		q.push_back(arr[i]);
		if (arr[i]) cnt++;
		if (q.size() > m) {
			if (q.front() == 1) cnt--;
			q.pop_front();
		}
		if (q.size() == m) {
			res = min(res, cnt);
		}
	}
	cout << res << endl;
	return 0;
}
