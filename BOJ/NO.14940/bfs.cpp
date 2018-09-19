//https://www.acmicpc.net/problem/14940
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int map[1005][1005];
bool visit[1005][1005];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
typedef struct p
{
	int x, y, level;
};
void bfs(p start)
{
	//넓이 우선 탐색
	queue<p> q;
	q.push(start);
	visit[start.x][start.y] = true;
	while (!q.empty())
	{
		p tmp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			p next = { tmp.x + dx[i],tmp.y + dy[i],tmp.level + 1 };
			if (map[next.x][next.y] == 1 && visit[next.x][next.y] == false)
			{
				q.push(next);
				visit[next.x][next.y] = true;
				map[next.x][next.y] = next.level;
			}
		}
	}
	//가지 못한 곳 -1로
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int f = 1;
			for (int k = 0; k < 4; k++)
			{
				if (i == start.x + dx[k] && j == start.y + dy[k])
					f = 0;
			}
			if (map[i][j] == 1 && f == 1)
				map[i][j] = -1;
		}
	}
	//지도출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	//지도 초기화
	for (int i = 0; i <1005; i++)
		for (int j = 0; j < 1005; j++)
			map[i][j] = -1;

	p start;
	cin >> n >> m;
	//데이터 입력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				start = { i,j,0 };
		}
	}
	map[start.x][start.y] = 0;
	bfs(start);
	return 0;
}
