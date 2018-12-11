/*
  문제 : https://www.acmicpc.net/problem/12869
  풀이 : 조건에 맞게 완전탐색.
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
int a[4], n;
int res = INF;
bool visit[61][61][61];
struct point
{
	int a, b, c;
};
void ans()
{
	queue<struct point> q;
	q.push({ a[1],a[2],a[3]});
	visit[a[1]][a[2]][a[3]] = 1;
	int time = 0;

	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			struct point now = q.front();
			q.pop();
			if (!now.a && !now.b && !now.c)
			{
				cout << time;
				return;
			}
			
			vi tmp;
			tmp.push_back(1);
			tmp.push_back(3);
			tmp.push_back(9);
			do
			{
				int nx = now.a - tmp[0];
				int ny = now.b - tmp[1];
				int nz = now.c - tmp[2];
				if (nx < 0)nx = 0;
				if (ny < 0)ny = 0;
				if (nz < 0)nz = 0;
				if (!visit[nx][ny][nz])
				{
					q.push({ nx,ny,nz });
					visit[nx][ny][nz] = 1;
				}
			} while (next_permutation(tmp.begin(), tmp.end()));
			
		}
		time++;
	}
}
int main()
{
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	ans();
	return 0;
}
