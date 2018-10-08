/*
  문제 : https://www.acmicpc.net/problem/1941
  풀이 : 가능한 모든 점을 탐색해서, 조건에 맞는 것을 찾는다.
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
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
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
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
char arr[5][5];
bool MAP[5][5],visit[5][5];
int res = 0;
vii v;
vi per;
bool bfs(pii a)
{
	qii q; 
	int cnt = 0, scnt = 0;
	q.push(a);
	visit[a.first][a.second] = true;
	
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		
		if (arr[now.first][now.second] == 'S') scnt++;
		cnt++;
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && MAP[nx][ny] == 1 &&(nx>=0&&nx<=4&&ny<=4&&ny>=0))
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}

	if (cnt == 7 && scnt>=4) return 1;
	else return 0;
}
int main()
{
	SWS;
	//입력
	FOR(i, 0, 4)
	{
		FOR(j, 0, 4)
		{
			cin >> arr[i][j];
			v.push_back({ i,j });
		}
	}
	FOR(i, 1, 18) per.push_back(0);
	FOR(i, 1, 7) per.push_back(1);
	// 모든 점중에 7개를 골라서 연결여부, S개수>=4 확인
	do
	{
		memset(MAP, 0, sizeof(MAP));
		memset(visit, 0, sizeof(visit));
		pii start;
		FOR(i, 0, 24)
		{
			if (per[i] == 1)
			{
				MAP[v[i].first][v[i].second] = 1;
				start = v[i];
			}
		}
		if (bfs(start)) res++;
	} while (next_permutation(per.begin(), per.end()));

	cout << res;
	return 0;
}
	
