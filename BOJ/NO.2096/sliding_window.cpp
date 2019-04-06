/*
  문제 : https://www.acmicpc.net/problem/2096
  풀이 : 메모리제약이 심하므로, 일반적인 DP가 아닌 슬라이딩 윈도기법을 사용한다.
      점화식은 간단하다.(코드참고)
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
#include<list>
#include<string.h>
#include<unordered_map>
#include<limits.h>
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
int n,q,w,e,r,t,y, arr[3], din[3], dax[3];
int main() {
	freopen("t.txt", "r", stdin);
	SWS;
	cin >> n;
	while (n--) {
		FOR(i, 0, 2) {
			cin >> arr[i];
		}
		q = dax[0], w = dax[1], e = dax[2];
		r = din[0], t = din[1], y = din[2];
		dax[0] = max(q, w) + arr[0];
		dax[1] = max({ q,w,e }) + arr[1];
		dax[2] = max(w,e) + arr[2];
		din[0] = min(r, t) + arr[0];
		din[1] = min({ r,t,y }) + arr[1];
		din[2] = min(t, y) +arr[2];
	}
	cout<< max({dax[0],dax[1],dax[2] }) <<" "<< min({ din[0],din[1],din[2] });
	return 0;
}
