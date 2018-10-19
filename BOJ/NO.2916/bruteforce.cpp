/*
  문제 : https://www.acmicpc.net/problem/2916
  풀이 : 360 = 0 이고, 400 = 40 이다. 이를 360도로 나머지를 구하는 방식으로 BFS탐색한다.
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
bool visit[370];
qi q;
int main()
{
	cin >> n >> m;
	FOR(i, 1, n)
	{
		int a;
		cin >> a;
		visit[a] = 1;
		q.push(a);
	}
  
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		FOR(i, 0, 360)
		{
			if (visit[i] == 1)
			{
				if (!visit[(now + i) % 360])
				{
					q.push((now + i) % 360);
					visit[(now + i) % 360] = 1;
				}
				if (now-i>=0 && !visit[(now - i) % 360])
				{
					q.push((now - i) % 360);
					visit[(now - i) % 360] = 1;
				}
			}
		}
	}
  
	while(m--)
	{
		int a;
		cin >> a;
		if (visit[a] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
