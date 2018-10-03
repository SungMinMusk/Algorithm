/*
  문제 : https://www.acmicpc.net/problem/1707
  풀이 : 이분그래프 판별 알고리즘을 사용한다.
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
vi v[20001];
int visit[20001];
bool color[20001];
int n, m, res;
void dfs(int a)
{
	visit[a] = true;
	int next_color = (color[a]) ? 0 : 1;

	FOR(i, 0, v[a].size() - 1)
	{
		int next = v[a][i];
		if (!visit[next])
		{
			color[next] = next_color;
			dfs(next);
		}
		else if (color[next] != next_color)
		{
			res = 0;
			return;
		}
	}

}
int main()
{
	SWS;
	int t;
	cin >> t;
	while (t--)
	{
		//초기화
		memset(visit, 0, sizeof(visit));
		memset(color, 0, sizeof(color));
		FOR(i, 0, 20000) v[i].clear();
		res = 1;
		//입력
		cin >> n >> m;
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		FOR(i, 1, n)
		{
			if (!visit[i] && !v[i].empty())
				dfs(i);
		}
		if(res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
