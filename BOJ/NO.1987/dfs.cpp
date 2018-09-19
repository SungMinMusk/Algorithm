/*
	문제 : https://www.acmicpc.net/problem/1987
	풀이 : dfs로 완전 탐색을 한다.
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

char arr[22][22];
bool visit[200];
bool map_visit[22][22];
int n, m;
int res = -1;

void ans(int x, int y, int cnt)
{
	bool f = 0; //방문 할 좌표가 있는 지
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		//좌표 방문 여부, 알파벳 방문 여부 확인
		if (map_visit[nx][ny] == false && visit[arr[nx][ny]] == false && arr[nx][ny] != -1)
		{
			visit[arr[nx][ny]] = true;
			map_visit[nx][ny] = true;

			ans(nx, ny,cnt+1);

			visit[arr[nx][ny]] = false;
			map_visit[nx][ny] = false;
			f = 1; //방문 할 좌표가 있다
		}
	}
	if (f == 0) //방문 할 좌표가 없다면 종료 조건
	{
		res = max(res, cnt);
		return;
	}
}
int main()
{
	SWS;
	memset(arr, -1, sizeof(arr));
	//입력값
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			arr[i][j] = s[j-1];
	}
	//1,1 방문 처리
	visit[arr[1][1]] = 1;
	map_visit[1][1] = 1;
	
	//탐색 시작
	ans(1,1,1);

	//결과 출력
	cout << res;
	return 0;
}
