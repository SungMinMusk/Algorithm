/*
	문제 : https://www.acmicpc.net/problem/14500
	풀이 : ㅗ모양을 제외한 다른 모양은 dfs로 만들 수 있다.
		따라서 ㅗ 모양을 제외하고는 dfs를 이용하여 영역의 합산을 구한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
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
int arr[502][502];
bool visit[502][502];
int n,m;
int res = -1;

void dfs(int x, int y, int cnt ,int sum)
{
	//cnt가 3일때 까지 진행
	if (cnt == 3)
	{
		res = max(res, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] == false && arr[nx][ny] != -1)
		{
			visit[nx][ny] = 1;
			sum += arr[nx][ny];

			dfs(nx, ny, cnt + 1, sum);

			visit[nx][ny] = 0;
			sum -= arr[nx][ny];
		}
	}
}

void fuc(int x, int y) //ㅗ 모양
{
	int sum = arr[x][y];
	for (int i = 0; i < 4; i++)
		sum += arr[x + dx[i]][y + dy[i]];
	for (int i = 0; i < 4; i++)
		res = max(res, sum - arr[x + dx[i]][y + dy[i]]);
}
int main()
{
	SWS;
	//arr 초기화
	for (int i = 0; i < 502; i++)
		for (int j = 0; j < 502; j++)
			arr[i][j] = -1;
	//데이터 입력
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	//모든 좌표마다 dfs 진행
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			visit[i][j] = 1;
			//ㅗ 형태 제외한 경우
			dfs(i, j, 0, arr[i][j]);
			//ㅗ 형태
			fuc(i, j);
			visit[i][j] = 0;
		}
	}
	cout << res;
	return 0;
}
