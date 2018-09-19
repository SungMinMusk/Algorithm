/*
	문제 : https://www.acmicpc.net/problem/1504
	풀이 : 필수적으로 지나야 하는 두점이 존재하므로 각 경로를 나눠
		최단경로를 다익스트라 알고리즘으로 구한다.
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
const int INF = 2147483647;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
/* -----구현부----- */

const int MAX = 801;
int N, E;
int v1, v2;
vii v[MAX];
int d[MAX];
void stra(int start, int dep)
{
	fill(d, d + MAX, INF);
	priority_queue<pair<int, int> > q;
	q.push({ 0,start });
	d[start] = 0;

	while (!q.empty())
	{
		int now = q.top().second;
		int now_d = -q.top().first;
		q.pop();

		if (d[now] < now_d)
			continue;

		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].first;
			int next_d = now_d + v[now][i].second;
			if (next_d < d[next])
			{
				d[next] = next_d;
				q.push({ -next_d, next });
			}
		}
	}
}
int main(void)
{
	SWS;
	//입력값
	cin >> N >> E;
	while (E--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	// res1 = 1-v1-v2-n .... res2 = 1-v2-v1-n
	long long res1 = 0, res2 = 0;
	//시작 -> v1
	stra(1, v1);
	res1 += d[v1];
	//v1->v2
	stra(v1, v2);
	res1 += d[v2];
	//v2->N
	stra(v2, N);
	res1 += d[N];

	//시작 -> v2
	stra(1, v2);
	res2 += d[v2];
	//v2->v1
	stra(v2, v1);
	res2 += d[v1];
	//v1->N
	stra(v1, N);
	res2 += d[N];

	//결과 출력
	res1 = min(res1, res2);
	if (res1 >= INF)
		cout << -1;
	else
		cout << res1;
	return 0;
}
