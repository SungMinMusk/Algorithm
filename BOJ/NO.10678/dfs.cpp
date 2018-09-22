/*
	문제 : https://www.acmicpc.net/problem/10678
	풀이 : 완전탐색을 통하여 두명의 도착시간이 같아지는 때를 찾는다.
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
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int n, m;
vii vb[20];
vii ve[20];
vi resb, rese;
void dfsb(int now, int time)
{

	if (n == now)
	{
		resb.push_back(time);
		return;
	}

	if (vb[now].size() == 0) return;
	FOR(i, 0, vb[now].size() - 1)
		dfsb(vb[now][i].first, time + vb[now][i].second);
}
void dfse(int now, int time)
{
	if (n == now)
	{
		rese.push_back(time);
		return;
	}

	if (ve[now].size() == 0) return;
	FOR(i, 0, ve[now].size() - 1)
		dfse(ve[now][i].first, time + ve[now][i].second);
}

int main()
{
	SWS;
	cin >> n >> m;
	while (m--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vb[a].push_back({ b,c });
		ve[a].push_back({ b,d });
	}

	dfsb(1, 0);
	dfse(1, 0);

	sort(rese.begin(), rese.end());
	sort(resb.begin(), resb.end());

	int e = 0, b = 0;
	while (e < rese.size() && b < resb.size())
	{
		if (rese[e] == resb[b]) { cout << rese[e]; return 0; }
		else if (rese[e] > resb[b]) b++;
		else e++;
	}
	cout << "IMPOSSIBLE";
	return 0;
}
