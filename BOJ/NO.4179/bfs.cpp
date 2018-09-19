/*
	 문제 : https://www.acmicpc.net/problem/4179
	 풀이 : 불을 bfs로 먼저 퍼지게한 후 걸리는 시간을 visitf에 넣어준다.
		인간이 이동할때 특정 지역에 불이 퍼지는 시간보다 먼저 도착하면 이동이 가능하도록 bfs를 해준다.
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

char arr[1002][1002];
bool visit[1002][1002];
int visitf[1002][1002];
int n, m;
vii fire;
pii me;
int res = -1;
typedef struct p
{
	int x, y, time;
}p;

void bfs()
{
	queue<p> q;

	q.push({me.first,me.second,0});
	visit[me.first][me.second] = 1;

	while (!q.empty())
	{
		p now = q.front();
		q.pop();

		if (arr[now.x][now.y] == 'E')
		{ 
			res = now.time; 
			return;
		}

		FOR(i, 0, 3)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if ((arr[nx][ny] !='#' && now.time+1 < visitf[nx][ny])&& !visit[nx][ny])
			{
				q.push({ nx, ny, now.time + 1 });
				visit[nx][ny] = 1;
			}
		}
	}
}
void bfsf()
{
	
	queue<p> q;
	
	FOR(i, 0, fire.size() - 1)
	{
		q.push({ fire[i].first,fire[i].second ,0 });
		visitf[fire[i].first][fire[i].second] = 0;
	}

	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		FOR(i, 0, 3)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (arr[nx][ny] == '.' && visitf[nx][ny] == INF)
			{
				visitf[nx][ny] = now.time + 1;
				q.push({ nx,ny,now.time + 1 });
			}
		}
	}
}
int main(void)
{
	SWS;

	//초기화
	res = -1;
	FOR(i, 0, 1001) FOR(j, 0, 1001) visitf[i][j] = INF;
	FOR(i, 0, 1001) FOR(j, 0, 1001) arr[i][j] = 'E';
	//입력
	cin >> n>>m;
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'J') me = { i,j };
			if (arr[i][j] == 'F') fire.push_back({ i, j });
		}
	}

	if(fire.size()) bfsf();
	bfs();

	if (res != -1)
		cout << res << endl;
	else
		cout << "IMPOSSIBLE" << endl;
	return 0;
}
