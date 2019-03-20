/*
  문제 : https://www.acmicpc.net/problem/15831
  풀이 : 조약돌을 앞에서 부터 탐색하며 데크뒤에 넣어주고, 조건에 따라 데크 앞을 빼준다 -> 슬라이딩 윈도
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
int n, b, w;
int l = 1, r = 1, res;
char arr[300100];
int cnt[200];
int main() {
	SWS;
	cin >> n >> b >> w;
	FOR(i, 1, n) {
		cin >> arr[i];
	}
    
	deque<char> q;
	FOR(i, 1, n) {
		q.push_back(arr[i]);
		cnt[arr[i]]++;
		while (cnt['B'] > b) {
			cnt[q.front()]--;
			q.pop_front();
		}
		if (cnt['B'] <= b && cnt['W'] >= w)
			res = max(res, cnt['W'] + cnt['B']);
	}

	cout << res;
	return 0;
}
