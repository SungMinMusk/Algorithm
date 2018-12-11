/*
  문제 : https://www.acmicpc.net/problem/7573
  풀이 : 가능한 모든 x,y좌표 조합에서 그물을 던진다.
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
#define FOR(a,b,c) for(int a=b;a<=c;++a)
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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int n, l, m, res = 0;
vi vx,vy;
vii v;
void ans(int a, int b, pii start)
{
	int sum = 0;
	FOR(i, 0, (int)v.size() - 1)
	{
		pii now = v[i];
		if (now.first >= start.first && now.first <= start.first + a 
		    && now.second >= start.second && now.second <= start.second + b)
			sum++;
	}
	res = max(res, sum);
}
int main()
{
	SWS;
	cin >> n >> l >> m;
	FOR(i, 1, m)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
		vx.push_back(x);
		vy.push_back(y);
	}
	FOR(a, 0, (int)vx.size() - 1)
	{
		FOR(b, 0, (int)vy.size() - 1)
		{
			pii start = { vx[a],vy[b] };
			FOR(i, 1, (l / 2) - 1)
			{
				int j = (l / 2) - i;
				ans(i, j, start);
			}
		}
	}
	cout << res;
	return 0;
}
