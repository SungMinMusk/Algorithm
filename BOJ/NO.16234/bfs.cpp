/*
  문제 : https://www.acmicpc.net/problem/16234
  풀이 : 조건에 맞는 것들에 BFS탐색을 반복한다. 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef queue<pair<int, int> > qii;
typedef pair<int, int > pii;
typedef vector<int> vi;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int arr[52][52],res,l,r,n;
bool visit[52][52];
bool ans(pii start)
{
	int sum = 0;
	qii q;
	vector<pii> v;
	q.push(start);
	visit[start.first][start.second] = 1;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		v.push_back({ now.first,now.second });
		sum += arr[now.first][now.second];
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			if (abs(arr[nx][ny] - arr[now.first][now.second]) >= l &&
				abs(arr[nx][ny] - arr[now.first][now.second]) <= r && 
				!visit[nx][ny])
			{
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}

		}
	}
	int avg = sum / (int)v.size();
	FOR(i, 0, (int)v.size() - 1)
		arr[v[i].first][v[i].second] = avg;

	if ((int)v.size() == 1) return false;
	else return true;
}
int main()
{
	SWS;
	fill(*arr, *arr + 52 * 52, -1000);
	cin >> n >> l >> r;
	FOR(i, 1, n) FOR(j, 1, n) cin >> arr[i][j];

	int time = 0;
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		bool f = 1;
		FOR(i, 1, n)
		{
			FOR(j, 1, n)
			{
				if (!visit[i][j])
				{
					bool s = ans({ i,j });
					if (s) f = 0;
				}
			}
		}
		if (f)
		{
			cout << time << endl;
			break;
		}
		time++;
	}

	return 0;
}
