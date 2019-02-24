/*
  문제 : https://www.acmicpc.net/problem/16955
  풀이 : X돌을 놓을 수 있는 모든 경우에 대하여, 상하, 좌우, 대각선을 BFS탐색하여 오목이 완성되는지 확인
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
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
/* ----- 함수 ----- */
char arr[10][10];
bool visit[10][10];
int dx[4][2] = {{1,-1},{0,0},{1,-1},{-1,1}};
int dy[4][2] = {{0,0},{1,-1},{1,-1},{1,-1}};
bool ans(pii pos)
{
	FOR(i, 0, 3)
	{
		memset(visit, 0, sizeof(visit));
		qii q;
		q.push(pos);
		visit[pos.first][pos.second] = 1;

		int cnt = 0;
		while (!q.empty())
		{
			pii now = q.front();
			q.pop();
			if (arr[now.first][now.second] == 'X') cnt++;
			if (cnt >= 5) return 1;

			FOR(j,0,1)
			{
				int nx = now.first + dx[i][j];
				int ny = now.second + dy[i][j];
				if (nx >= 0 && nx <= 9 && ny >= 0 && ny <= 9 && !visit[nx][ny] && arr[nx][ny] == 'X')
				{
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	SWS;
	FOR(i, 0, 9) FOR(j, 0, 9) cin >> arr[i][j];

	FOR(i, 0, 9)
	{
		FOR(j, 0, 9)
		{
			if (arr[i][j] == '.')
			{
				arr[i][j] = 'X';
				if (ans({ i,j }))
				{
					cout << 1;
					return 0;
				}
				arr[i][j] = '.';
			}
		}
    }
	cout << 0;
	return 0;
}
