/*
  문제 : https://www.acmicpc.net/problem/16926
  풀이 : BFS를 하는 느낌으로 제일 바깥쪽부터 스왑해 나간다. 
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { -1, 1 };
/* ----- 함수 ----- */
int arr[302][302];
bool visit[302][302];
int n, m, r;
int main()
{
	SWS;
	fill(*arr, *arr + 302 * 302, -1);
	cin >> n >> m >> r;
	FOR(i, 1, n) FOR(j, 1, m) cin >> arr[i][j];
	while (r--)
	{
		memset(visit, 0, sizeof(visit));
		int i = 1, j = 1, dir = 0, prev;
		pii now;
		while (!visit[i][j])
		{
			now = { i,j };
			visit[i][j] = 1;
			prev = arr[i][j];

			while (1)
			{
				int nx = now.first + dx[dir];
				int ny = now.second + dy[dir];
				if (visit[nx][ny] && dir == 3)
				{
					arr[i][j] = prev;
					break;
				}
				else if (arr[nx][ny] == -1 || visit[nx][ny])
					dir++;
				else
				{
					swap(arr[nx][ny], prev);
					visit[nx][ny] = 1;
					now = { nx,ny };
				}
			}
			i++;
			j++;
			dir = 0;
		}
	}
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}
