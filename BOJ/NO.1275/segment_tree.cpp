/*
  문제 : https://www.acmicpc.net/problem/1275
  풀이 : 단순한 세그먼트트리 문제이다.
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
#include<float.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
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
/* ----- 함수 ----- */
const int _MAX = 400001;
int n, q, vol=1;
ll arr[_MAX];
ll _sum(int L,int R, int node ,int a,int b)
{
	if (b < L || R < a) return 0;
	if (L <= a && b <= R) return arr[node];
	int mid = (a + b) / 2;
	return _sum(L, R, node * 2, a, mid) + _sum(L, R, node * 2 + 1, mid + 1, b);
}
void update(int idx, int val)
{
	idx += vol;
	arr[idx] = val;
	while (idx > 1)
	{
		idx /= 2;
		arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
	}
}
int main()
{
	SWS;
	cin >> n >> q;
	while (vol < n) vol *= 2;
	FOR(i, 0, n - 1)
	{
		int a;
		cin >> a;
		update(i, a);
	}

	int x, y, a, b;
	while (q--)
	{
		cin >> x >> y >> a >> b;
		if (y < x) swap(x, y);
		cout << _sum(x - 1, y - 1, 1, 0, vol - 1) << endl;
		update(a - 1, b);
	}
	return 0;
}
