/*
  문제 : https://www.acmicpc.net/problem/14395
  풀이 : 가능한 모든 경우의수를 탐색한다. 단. 사전순으로 나아갈수 있도록 *+-/ 순서로 dfs탐색한다.
*/#include<iostream>
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
queue<pair<ll, string> >q;
map<ll, bool> visit;
ll a, b;
void ans()
{
	while (!q.empty())
	{
		string s = q.front().second;
		ll num = q.front().first;
		q.pop();

		if (num == b)
		{
			cout << s;
			exit(0);
		}
		if (num*num <= b && !visit[num*num])
		{
			q.push({ num*num,s + "*" });
			visit[num*num] = 1;
		}
		if (num + num <= b && !visit[num + num])
		{
			q.push({ num + num,s + "+" });
			visit[num + num] = 1;
		}
		if (!visit[num - num])
		{
			q.push({ num - num,s + "-" });
			visit[num - num] = 1;
		}
		if (num!=0 && num / num <= b && !visit[num / num])
		{
			q.push({ num / num,s + "/" });
			visit[num / num] = 1;
		}
	}
	cout << -1;
	exit(0);
}
int main()
{
	SWS;
	cin >> a >> b;
	if (a == b)
	{
		cout << "0";
		return 0;
	}
	visit[a] = 1;
	q.push({ a,"" });
	ans();
	return 0;
}

