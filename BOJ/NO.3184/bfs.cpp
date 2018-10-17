/*
  문제 : https://www.acmicpc.net/problem/3184
  풀이 : 모든 영역을 BFS를 이용해 탐색하면서 늑대와 양의 숫자를 비교한다.
    영역의 구분의 경우 방문처리를하여 BFS를 빠져나오고 방문 처리가 안된 점에 다시 BFS를 돌면 된다.
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
#include<float.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
bool visit[252][252];
char arr[252][252];
int lamb, wolf, n, m;
void dfs(int x, int y)
{
	int l = 0, w = 0;
	qii q;
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		if (arr[now.first][now.second] == 'o') l++;
		else if (arr[now.first][now.second] == 'v') w++;

		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] != '#')
			{
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	if (l > w) lamb += l;
	else wolf += w;
}
int main()
{
	SWS;
	fill(*arr, *arr + 252 * 252, '#');
	cin >> n >> m;
	FOR(i, 1, n)
		FOR(j, 1, m) 
			cin >> arr[i][j];

	FOR(i, 1, n)
	{
		FOR(j, 1, m) 
		{ 
			if (arr[i][j] != '#' && !visit[i][j])
				dfs(i, j);
		}
	}
	cout << lamb << " " << wolf;
	return 0;
}
