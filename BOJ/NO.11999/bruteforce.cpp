/*
	문제 : https://www.acmicpc.net/problem/11999
	풀이 : 가능한 모든 경우를 queue를 이용하여 따져본다.
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
int a, b, c, res = 0;;
bool visit[1001];
qi q;
int main()
{
	SWS;
	//freopen("tc.txt", "r",stdin);
	cin >> a >> b >> c;
	q.push(0);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		res = max(res, now);
		if (now + a <= c && !visit[now + a])
		{
			q.push(now + a);
			visit[now + a] = 1;
		}
		if (now + b <= c && !visit[now + b])
		{
			q.push(now + b);
			visit[now + b] = 1;
		}
	}
	cout << res;
	return 0;
}
