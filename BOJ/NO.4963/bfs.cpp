//https://www.acmicpc.net/problem/4963
#include<iostream>
#include<queue>
using namespace std;
int n,m;
bool map[52][52];
bool visit[52][52];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,-1,1,1,-1 };
typedef struct point
{
	int x, y;
}p;
void init()
{
	for(int a=0;a<52;a++)
	{
		for (int b = 0; b<52; b++)
		{
			map[a][b] = 0;
			visit[a][b] = 0;
		}
	}
}
int bfs(int a, int b)
{
	queue<p> q;
	q.push({ a,b });
	map[a][b] = false;
	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			p next = { now.x + dx[i],now.y + dy[i] };
			if (visit[next.x][next.x] == false && map[next.x][next.y] == 1)
			{
				q.push(next);
				map[next.x][next.y] = false;
			}
		}
	}
	return 1;
}
void ans()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
				res+=bfs(i,j);
		}
	}
	cout << res;
}
int main()
{
	while (true)
	{
		//입력
		cin >> m>>n;
		if (n == 0 && m == 0) return 0;
		init();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];

		ans();
		cout << '\n';
	}
	return 0;
}
