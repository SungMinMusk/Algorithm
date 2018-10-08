/*
  문제 : https://www.acmicpc.net/problem/1194
  풀이 : 가진 열쇠의 정보를 비트마스킹하여 visit배열을 만든 후, bfs한다.
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
char arr[52][52];
bool visit[66][52][52];
typedef struct point
{
	int x, y;
	int time=0;
	int key=0;
}point;
int n, m;
pii s;
set<pii>e;

int bfs()
{
	queue<point> q;
	point p;
	p.x = s.first;
	p.y = s.second;
	q.push(p);
	visit[0][p.x][p.y] = true;

	while (!q.empty())
	{
		point now = q.front();
		q.pop();
		//종료 조건
		if (e.find({ now.x,now.y }) != e.end()) return now.time;
		//상하좌우 탐색
		FOR(i, 0, 3)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (!visit[now.key][nx][ny] && arr[nx][ny] != '#')
			{
				point next = now;
				if (arr[nx][ny] >= 'a' && arr[ny][ny] <= 'f')
				{
					next.time++;
					next.key |= (1 << (arr[nx][ny] - 32 - 'A'));
					next.x = nx;
					next.y = ny;
					q.push(next);
					visit[next.key][nx][ny] = true;
				}
				else if (arr[nx][ny] == '.' || now.key&(1 << (arr[nx][ny] - 'A')))
				{
					next.time++;
					next.x = nx;
					next.y = ny;
					q.push(next);
					visit[next.key][nx][ny] = true;
				}
			}
		}
	}
	return -1;
}
int main()
{
	//값 입력
	fill(*arr, *arr + 52 * 52, '#');
	cin >> n >> m;
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '0')
			{
				s = { i,j };
				arr[i][j] = '.';
			}
			else if (arr[i][j] == '1')
			{
				e.insert({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	//처리
	cout << bfs();
	return 0;
}
