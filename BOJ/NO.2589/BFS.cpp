//https://www.acmicpc.net/problem/2589
#include<iostream>
#include<string>
#include<queue>
using namespace std;
char map[52][52];
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
typedef struct point
{
	int x, y, time;
}pt;
int bfs(int a, int b)
{
	queue<pt> q;
	bool visit[52][52] = { 0, };
	//시작 좌표 큐에 넣음
	q.push({ a,b,0 });
	visit[a][b] = true; //방문처리
	int max = 0;
	while (!q.empty())
	{
		//큐 맨 앞 꺼냄
		pt prev = q.front();
		q.pop();
		//사방이 전부 방문했으면 false;
		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			//다음 좌표 정의 (time+1 해줌)
			pt next = { prev.x + dx[i],prev.y + dy[i],prev.time + 1 };
			if (visit[next.x][next.y] == false && map[next.x][next.y] == 'L')
			{
				q.push(next);
				visit[next.x][next.y] = true; //큐에 넣고 방문 처리
				flag = true; //flag 
			}
		}
		//막다른 길인경우 최대 시간인지 판단 후 넘김
		if (flag == false)
		{
			if (max < prev.time) max = prev.time;
		}
	}
	return max;
}
void ans()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 'L')
			{
				int tmp = bfs(i, j);
				if (tmp > res) res = tmp;
			}
		}
	}
	cout << res;
}
int main()
{
	//초기화
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			map[i][j] = 'K';
		}
	}
	// 지도입력 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j - 1];
		}
	}
	//함수실행
	ans();
	return 0;
}
