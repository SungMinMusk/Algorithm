/*
  문제 : https://www.acmicpc.net/problem/16431
  풀이 : 데시와 베이지를 bfs탐색한다.
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
int ddx[8] = { 1,-1,0,0,1,1,-1,-1 };
int ddy[8] = { 0,0,1,-1,1,-1,1,-1 };
pii b, d, j;
int bfs(pii start,char who)
{
	bool visit[1001][1001];
	memset(visit, 0, sizeof(visit));
	qii q;
	q.push(start);
	visit[start.first][start.second] = 1;

	int time = 0;
	while (!q.empty())
	{
		int size = q.size();
		time++;
		while (size--)
		{
			pii now = q.front();
			q.pop();
			if (now == j) return time;
			if(who == 'D')
			{
				FOR(i, 0, 3)
				{
					int nx = now.first + dx[i];
					int ny = now.second + dy[i];

					if ((nx >= 0 && ny >= 0 && nx <= 1000 && ny <= 1000) &&!visit[nx][ny])
					{
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
			}
			else
			{
				FOR(i, 0, 7)
				{
					int nx = now.first + ddx[i];
					int ny = now.second + ddy[i];

					if ((nx >= 0 && ny >= 0 && nx <= 1000 && ny <= 1000) && !visit[nx][ny])
					{
						q.push({ nx,ny });
						visit[nx][ny] = 1;
					}
				}
			}
		}
	}
}
int main()
{
	SWS;
	cin >> b.first >> b.second;
	cin >> d.first >> d.second;
	cin >> j.first >> j.second;
	int diff_b = bfs(b,'B');
	int diff_d = bfs(d,'D');

	if (diff_b == diff_d) cout << "tie";
	else if (diff_b < diff_d) cout << "bessie";
	else cout << "daisy";

	return 0;
}
