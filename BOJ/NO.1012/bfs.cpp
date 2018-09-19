//https://www.acmicpc.net/problem/1012
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n, m, k;
int res = 0;
int map[52][52];
bool visit[52][52];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
typedef struct point
{
	int x, y;
}p;
void bfs(p start)
{
	queue<p> q;
	q.push(start);
	visit[start.x][start.y] = true;
	map[start.x][start.y] = 0;
	while (!q.empty())
	{
		p start = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			p next = { start.x + dx[i],start.y + dy[i] };
			if (visit[next.x][next.y] == false && map[next.x][next.y] == 1)
			{
				q.push(next);
				map[next.x][next.y] = 0;
				visit[next.x][next.y] = true;
			}
		}
	}
	res++;
}
void ans()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
				bfs({ i,j });
		}
	}
	cout << res << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		//초기화
		for (int i = 0; i <52; i++)
		{
			for (int j = 0; j <52; j++)
			{
				map[i][j] = 0;
				visit[i][j] = false;
			}
		}
		res = 0;
		//입력
		cin >> m >> n >> k;
		while (k--)
		{
			int x, y;
			cin >> x>> y;
			map[y+1][x+1] = 1;
		}
		//해결
		ans();
	}

	return 0;
}
