//https://www.acmicpc.net/problem/7569
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int map[102][102][102];
bool visit[102][102][102];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int dz[2]={ -1, 1 };
int n, m,h;

typedef struct point
{
	int z;
	int x;
	int y;
	int level;
}p;
//익은 것 확인
bool ok()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (map[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}
int ans()
{
	int res = 0;
	queue<p> q;
	//지도에서 1인것 push
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (map[i][j][k] == 1)
				{
					q.push({ i,j,k,0 });
					visit[i][j][k] = true;
				}
			}
		}
	}

	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		//레벨 갱신
		res = (res < now.level) ? now.level : res;
		for (int i = 0; i < 4; i++)
		{
			p next = { now.z,now.x + dx[i],now.y + dy[i],now.level+1 };
			if (visit[next.z][next.x][next.y] == false && map[next.z][next.x][next.y]==0)
			{
				q.push(next);
				visit[next.z][next.x][next.y] = true;
				map[next.z][next.x][next.y] = 1;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			p next = { now.z + dz[i], now.x,now.y,now.level + 1 };
			if (visit[next.z][next.x][next.y] == false && map[next.z][next.x][next.y] == 0)
			{
				q.push(next);
				visit[next.z][next.x][next.y] = true;
				map[next.z][next.x][next.y] = 1;
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
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++)
			for (int k = 0; k < 102; k++)
				map[i][j][k] = -1;
	//입력
	cin >> m>>n>>h;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= n; j++)
			 for(int k = 1; k <= m; k++)
					cin >> map[i][j][k];

	//처음에 모두 익었으면
	if (ok()) { cout << 0; return 0; }
	//solve
	int res = ans();
	//result 출력
	if (ok()) cout << res;
	else cout << -1;
	return 0;
}
