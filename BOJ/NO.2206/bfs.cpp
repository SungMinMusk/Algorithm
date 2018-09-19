/*
	문제 : https://www.acmicpc.net/problem/2206
	풀이 : 가중치가 없는 최단거리는 BFS로 탐색한다.
		단, 큐에 부수고 지나간 길인지 아닌지 입력해야하며 
		visit배열도 마찬가지로 체크한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#define INF 0x7fffffff
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[1002][1002];
int visit[1002][1002][2]; //0 벽을 부순 visit, 1 벽을 안 부순 visit
int n, m;
vii v;
int res = INF;
void bfs()
{
	queue<pair<pii, pii >> q;
	visit[1][1][0] = true;
	//x , y , crash , level ;
	q.push({ { 1, 1 }, {0,1} });

	int cnt = 0;
	while (!q.empty())
	{
		pii now = q.front().first;
		int crached = q.front().second.first;
		int level = q.front().second.second;
		q.pop();

		//도착한 경우
		if (now.first == n && now.second == m)
		{
			res = min(res, level);
			return;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			//부순 경력이 있는 상태인 경우
			if (crached == 1)
			{
				if (!visit[nx][ny][1] && arr[nx][ny] == 0)
				{
					visit[nx][ny][1] = true;
					q.push({ { nx,ny }, {1,level + 1 } });
				}
			}
			//부순 경력이 없는 상태인 경우
			else
			{
				if (!visit[nx][ny][0] && arr[nx][ny] != -1)
				{
					
					//벽 부숨
					if (arr[nx][ny] == 1)
					{
						q.push({ { nx,ny }, {1 ,level + 1} });
						visit[nx][ny][1] = true;
					}
					//안 부숨
					else
					{
						q.push({ { nx,ny }, {0 ,level + 1} });
						visit[nx][ny][0] = true;
					}
				}
			}
		}
	}
}
int main()
{
	SWS;
	cin >> n >> m;
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = s[j - 1]-'0';
			if (arr[i][j] == 1) v.push_back({ i,j });
		}
	}
	
	bfs();

	if (res == INF)
		cout << "-1";
	else
		cout << res;
	return 0;
}
