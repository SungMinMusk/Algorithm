/*
  문제 : https://www.acmicpc.net/problem/13023
  풀이 : DFS의 깊이가 4인것을 찾는다.
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
int n, m;
bool res = 0,visit[2001];
vi v[2001];
void dfs(int pos, int depth)
{
	visit[pos] = 1;
	
	if (depth == 4)
	{
		res = 1;
		return;
	}
	
	FOR(i, 0, v[pos].size() - 1)
		if (!visit[v[pos][i]])
			dfs(v[pos][i], depth + 1);

	visit[pos] = 0;
}
int main()
{
	SWS;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	FOR(i, 0, n-1)
	{
		memset(visit, 0, sizeof(visit));
		dfs(i,0);

		if (res == 1)
		{
			cout << 1;
			return 0;
		}
	}
	
	cout << 0;
	return 0;
}
