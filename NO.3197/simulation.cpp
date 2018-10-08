/*
  문제 : https://www.acmicpc.net/problem/3197
  풀이 : 어렵다. 빙판이 녹는 시간을 기록하고, 1~MAX_DAY까지 이분탐색으로 적절한 DAY를 찾는다.
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
char arr[1502][1502];
int water_visit[1502][1502];
bool visit[1502][1502];
queue<pair<pii, int> >water;
int r, c, maxt = -1;
vii L;
void waterBFS()
{
	while (!water.empty())
	{
		pii now = water.front().first;
		int now_t = water.front().second;
		maxt = max(now_t, maxt);
		water.pop();
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (arr[nx][ny] == 'X' && water_visit[nx][ny] > now_t + 1)
			{
				arr[nx][ny] = '.';
				water.push({ { nx,ny },now_t + 1 });
				water_visit[nx][ny] = now_t + 1;
			}
		}
	}
}
bool bfs(int time)
{
	memset(visit, 0, sizeof(visit));
	qii q;
	q.push(L[0]);
	visit[L[0].first][L[0].second] = true;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		if (now == L[1])
			return 1;
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && water_visit[nx][ny] <= time && arr[nx][ny] == '.' || arr[nx][ny] == 'L')
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	return 0;
}
int main()
{
	SWS;
	fill(*water_visit, *water_visit + 1502 * 1502, INF);
	fill(*arr, *arr + 1502 * 1502, '#');
	cin >> c >> r;
	FOR(i, 1, c)
	{
		string s;
		cin >> s;
		FOR(j, 1, r)
		{
			arr[i][j] = s[j - 1];
			if (arr[i][j] != 'X')
			{
				water.push({ { i,j },0 });
				water_visit[i][j] = 0;
			}
			if (arr[i][j] == 'L') L.push_back({ i,j });
		}
	}
	waterBFS();
	int s = 0, e = maxt;
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (bfs(m)) e = m - 1;
		else s = m + 1;
	}
	cout << s;
	return 0;
}
