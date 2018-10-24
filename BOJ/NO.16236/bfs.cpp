/* 
  문제 : https://www.acmicpc.net/problem/16236
  풀이 : 아기상어가 먹을 수 있는 물고기를 벡터에 넣고 sort를 하면 조건에 맞는 물고기가 나온다.
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
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int arr[22][22];
bool visit[22][22];
pii shark;
int res = 0;
int sk_size = 2;
int sk_stack = 0;
pii ans()
{
	memset(visit, 0, sizeof(visit));
	qii q;
	q.push(shark);
	visit[shark.first][shark.second] = 1;
	int diff = 0;
	while (!q.empty())
	{
		diff++;
		int size = q.size();
		bool f = 1;
		vii v;
		while (size--)
		{
			pii now = q.front();
			q.pop();
			FOR(i, 0, 3)
			{
				int nx = now.first + dx[i];
				int ny = now.second + dy[i];
				if (!visit[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == sk_size))
				{
					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
				else if (!visit[nx][ny] && sk_size > arr[nx][ny])
				{
					v.push_back({ nx,ny });
					f = 0;
				}
			}
		}
		if (!f)
		{
			sort(v.begin(), v.end());
			res += diff;
			return { v[0].first,v[0].second };
		}
	}
	cout << res;
	exit(0);
}
int main()
{
	SWS;
	fill(*arr, *arr + 22 * 22, 1000);
	int n;
	cin >> n;
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				shark = { i,j };
				arr[i][j] = 0;
			}
		}
	}
	while (1)
	{
		pii next = ans();
	
		sk_stack++;
		if (sk_stack == sk_size)
		{
			sk_size++;
			sk_stack = 0;
		}
		shark = next;
		arr[shark.first][shark.second] = 0;
	}
	return 0;
}
