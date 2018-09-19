//https://www.acmicpc.net/problem/7576
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int map[1002][1002];
bool visit[1002][1002];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m;

typedef struct point
{
	int x;
	int y;
	int level;
}p;
//익은 것 확인
bool ok()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}
int ans()
{
	int res = 0;
	queue<p> q;
	//지도에서 1인것 push
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
			{
				q.push({ i,j,0 });
				visit[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		//레벨 갱신
		if (res < now.level) res = now.level;
		for (int i = 0; i < 4; i++)
		{
			p next = { now.x + dx[i],now.y + dy[i],now.level+1 };
			if (visit[next.x][next.y] == false && map[next.x][next.y]==0)
			{
				q.push(next);
				visit[next.x][next.y] = true;
				map[next.x][next.y] = 1;
			}
		}
	}
	return res;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//초기화
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			map[i][j] = -1;
	//입력
	cin >> m>>n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	//처음에 모두 익었으면
	if (ok()) { cout << 0; return 0; }
	//solve
	int res = ans();
	//result 출력
	if (ok()) cout << res;
	else cout << -1;
	return 0;
}
