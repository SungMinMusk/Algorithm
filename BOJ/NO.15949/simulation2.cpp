/*
  문제 : https://www.acmicpc.net/problem/15949
  풀이 : 풀이를 조금 다르게한 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef queue<int> qi;
typedef vector<pair<int, int > >vii;
typedef priority_queue<int> pqi;
typedef queue<pair<int, int> > qii;
typedef pair<int, int > pii;
typedef vector<int> vi;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
/* -----구현부----- */
int n, m;
int now_block = 0;
int arr[102][102];
bool visit[102][102];
int edge[20000][4];
int memo[20000][9];
map<int, char> color_map;
int nextCC(int CC)
{
	if (CC == 4) return 0;
	else return 4;
}
int nextDP(int DP)
{
	if (DP == 4) return 1;
	else return DP + 1;
}
void bfs(pii start, int number)
{
	int maxx = 0, maxy = 0;
	int minx = INF, miny = INF;
	char color = arr[start.first][start.second];
	qii q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		arr[now.first][now.second] = number;

		maxx = max(maxx, now.first);
		minx = min(minx, now.first);
		maxy = max(maxy, now.second);
		miny = min(miny, now.second);
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] == color)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	edge[number][0] = minx;
	edge[number][1] = maxx;
	edge[number][2] = miny;
	edge[number][3] = maxy;
}
int find(int number, int DP, int CC)
{
	vii v;
	if (DP == 1)
	{
		int i = edge[number][0];
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == number) v.push_back({ i,j });
	}
	else if (DP == 2)
	{
		int j = edge[number][3];
		for (int i = 1; i <= n; i++)
			if (arr[i][j] == number) v.push_back({ i,j });
	}
	else if (DP == 3)
	{
		int i = edge[number][1];
		for (int j = m; j >= 1; j--)
			if (arr[i][j] == number) v.push_back({ i,j });
	}
	else if (DP == 4)
	{
		int j = edge[number][2];
		for (int i = n; i >= 1; i--)
			if (arr[i][j] == number) v.push_back({ i,j });
	}
	pii codel, next;
	if (CC == 0)  codel = v[0];
	else if (CC == 4) codel = v[v.size() - 1];

	//리턴
	if (DP == 1) next = { codel.first - 1,codel.second };
	else if (DP == 2) next = { codel.first,codel.second + 1 };
	else if (DP == 3) next = { codel.first + 1,codel.second };
	else if (DP == 4) next = { codel.first ,codel.second - 1 };
	return arr[next.first][next.second];
}
int main()
{
	SWS;
	//초기화
	FOR(i, 0, 101) FOR(j, 0, 101) arr[i][j] = 'X';
	cin >> n >> m;
	FOR(i, 1, n)
	{
		string s;
		cin >> s;
		FOR(j, 1, m)
			arr[i][j] = s[j - 1];
	}

	//영역 칠함
	int number = 0;
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			if (!visit[i][j] && arr[i][j] != 'X')
			{
				color_map[number] = arr[i][j];
				bfs({ i,j }, number);
				number++;
			}
			if (number == 88) number = 89; //88은 X임
		}
	}
	//memo
	FOR(i, 0, number - 1)
	{
		FOR(j, 1, 4)
		{
			memo[i][j + 0] = find(i, j, 0);
			memo[i][j + 4] = find(i, j, 4);
		}
	}

	int DP = 2, CC = 0; //DP 1234 상우하좌 //CP 0 4 좌우
	cout << color_map[now_block];
	while (1)
	{
		//종료 조건
		bool ex = 0;
		FOR(j, 1, 8)
			if (memo[now_block][j] != 'X') ex = 1;
		if (!ex) return 0;

		int turn = 0;
		int next = memo[now_block][CC + DP];
		while (next == 'X')
		{
			if (turn % 2 == 0)
				CC = nextCC(CC);
			else
				DP = nextDP(DP);
			next = memo[now_block][CC + DP];
			turn++;
		}

		now_block = next;
		cout << color_map[now_block];
	}
	return 0;
}
