/*
	문제 : https://www.acmicpc.net/problem/10026
	풀이 : 넓이 우선 탐색으로 문제를 해결, 색맹 환자의 경우 G를 R로 전부 바꿔서 한번 
*/
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n;
char arr[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[102][102];
typedef struct point
{
	int x, y;
}p;
void bfs(p start,char color)
{
	queue<p>q;
	q.push(start);
	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			p next = { now.x + dx[i],now.y + dy[i] };
			if (visit[next.x][next.y] == false && arr[next.x][next.y] == color)
			{
				q.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
}
void ans()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visit[i][j] == false)
			{
				visit[i][j] = true;
				bfs({ i,j },arr[i][j]);
				res++;
			}
		}
	}
	cout << res;
}
int main()
{
	//입력
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
			arr[i][j] = s[j-1];
	}
	//정상인 출력
	ans();

	//visit배열 초기화
	for (int i = 0; i < 102 * 102; i++)
		*(visit[0] + i) = 0;

	//적록색맹환자 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
	}
	cout << " ";
	ans();


	return 0;
}
