/*
	문제 : https://www.acmicpc.net/problem/1799
	풀이 : 체스판을 대각선을 기준으로 본다. 비숍은 각 대각선당 한개만 놓을 수 있다.
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
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef stack<int> sti;
typedef stack<pair<int, int> > stii;
typedef queue<int> qi;
typedef queue<pair<int, int> > qii;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int> > pqii;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;
typedef set<int> seti;
/* -----구현부----- */
int arr[12][12], n, res;
vii v[30];
bool check(pii pos)
{
	int nx = pos.first - 1;
	int ny = pos.second - 1;
	while (nx > 0 && ny > 0)
	{
		if (arr[nx][ny] == 2) return false;
		nx -= 1;
		ny -= 1;
	}
	return true;
}
void bfs()
{
	int x[2] = { 1,0 }, y[2] = { 0,1 };
	bool visit[12][12];
	memset(visit, 0, sizeof(visit));
	qii q;
	q.push({ 1,1 });
	visit[1][1] = 1;
	int num = 0;
	while (!q.empty())
	{
		int size = q.size();
		num++;
		while (size--)
		{
			pii now = q.front();
			q.pop();
			if (arr[now.first][now.second] == 1) v[num].push_back(now);
			FOR(i, 0, 1)
			{
				int nx = now.first + x[i];
				int ny = now.second + y[i];
				if (!visit[nx][ny] && nx <= n && ny <= n)
				{
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}
}
void ans(int lv, int cnt)
{
	if (lv == 2 * n)
	{
		res = max(cnt, res);
		return;
	}
	bool f = 0;
	for (pii &i : v[lv])
	{
		if (check(i))
		{
			f = 1;
			arr[i.first][i.second] = 2;
			ans(lv + 1, cnt + 1);
			arr[i.first][i.second] = 1;
		}
	}
	if (!f) ans(lv + 1, cnt);
}
int main()
{
	SWS;
	cin >> n;
	FOR(i, 1, n) FOR(j, 1, n) cin >> arr[i][j];
	bfs();
	ans(1, 0);
	cout << res;
	return 0;
}
