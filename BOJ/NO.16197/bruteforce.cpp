/*
  문제 : https://www.acmicpc.net/problem/16197
  풀이 : 동전이 이동 할 수 있는 위치들을 완전 탐색한다.
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
int n, m;
char arr[22][22];
bool visit[22][22][22][22][11];
vii v;
int res = INF;
int game(int d,int cnt)
{
	int drop = 0;

	pii c1 = { v[0].first + dx[d],v[0].second + dy[d] };
	pii c2 = { v[1].first + dx[d],v[1].second + dy[d] };

	if (visit[c1.first][c1.second][c2.first][c2.second][cnt]) return -1;
	visit[c1.first][c1.second][c2.first][c2.second][cnt] = 1;

	//코인 1
	if (arr[c1.first][c1.second] == '.')
		v[0] = c1;
	else if (arr[c1.first][c1.second] == 'z')
	{
		drop++;
		v[0] = c1;
	}

	//코인 2
	if (arr[c2.first][c2.second] == '.')
		v[1] = c2;
	else if (arr[c2.first][c2.second] == 'z')
	{
		drop++;
		v[1] = c2;
	}

	if (v[0]==v[1])
		return -1;
	return drop;
	
}

void ans(int cnt)
{
	if (cnt > 10) return;
	pii c1 = v[0], c2 = v[1];

	FOR(i, 0, 3)
	{
		int r = game(i,cnt);
		if (r == 1)
			res = min(res, cnt);
		if (r == 0)
			ans(cnt + 1);

		v[0] = c1;
		v[1] = c2;
	}
}
int main()
{
	SWS;
	fill(*arr, *arr + 22 * 22, 'z');
	cin >> n >> m;
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'o')
			{
				v.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	ans(1);
	if (res == INF) cout << -1;
	else cout << res;
	return 0;
}
