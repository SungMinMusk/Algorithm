/*
  문제 : https://www.acmicpc.net/problem/1849
  풀이 : 세그먼트 트리를 이용하여 현재 추가 할 숫자 앞에 몇개의 숫자가 있는지 판단.
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
int n,arr[100001],res[100001],tree[400001];
int _size = 1;
int _get(int node,int idx) {
	if (node >= _size) return node-_size;
	if (idx > tree[node * 2]) {
		return _get(node * 2 + 1, idx - tree[node * 2]);
	}
	else {
		return _get(node * 2, idx);
	}
}
void _update(int idx, int value) {
	idx += _size;
	tree[idx] = value;

	while (idx != 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
int main() {
	SWS;
	//input
	cin >> n;
	FOR(i, 1, n) cin >> arr[i];

	//init
	while (_size < n) _size *= 2;
	FOR(i, 1, n) _update(i - 1, 1);

	//logic
	FOR(i, 1, n) {
		int idx = _get(1, arr[i]+1);
		_update(idx, 0);
		res[idx] = i;
	}
	FOR(i, 0, n - 1) cout << res[i] << endl;
	return 0;
}
