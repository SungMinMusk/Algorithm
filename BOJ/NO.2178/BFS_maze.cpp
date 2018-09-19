//https://www.acmicpc.net/problem/2178
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int maze[102][102]; // 미로
bool visit[102][102]; // visit
int x[4] = { 1,0,-1,0 }; // to move
int y[4] = { 0,-1,0,1 };

typedef struct point // 좌표 구조체
{
	int x, y;
	int level = 0;
}pt;
queue<pt> q;

void ans(int n, int m)
{
	int res = 0; 
	q.push({ 1,1,1});
	visit[1][1] = true;
	while (!q.empty())
	{
		pt tmp = q.front();
		if (tmp.x == n && tmp.y == m)
		{
			cout << tmp.level; 
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pt new_pt = { tmp.x + x[i],tmp.y + y[i],tmp.level+1};
			if (maze[new_pt.x][new_pt.y] == 1 && visit[new_pt.x][new_pt.y] == false)
			{
				q.push(new_pt);
				visit[new_pt.x][new_pt.y] = true;
			}
		}
	}
	
}
int main()
{
	int N, M;
	string s[101];

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> s[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			maze[i][j]=s[i].at(j-1)-48;
	
	ans(N,M);
	return 0;
}
