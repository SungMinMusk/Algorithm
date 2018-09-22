/*
	문제 : https://www.acmicpc.net/problem/10675
	풀이 : 각 항공편에서 출발점과 도착점을 찾아 존재하는 경우 결과값에 최솟값을 넣도록 처리
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
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int s, e, n;
vector<char> v;
int res = INF;
int main()
{
	SWS;
	cin >> s >> e >> n;
	while (n--)
	{
		int cost, num;
		cin >> cost >> num;
		int st = -1, et = -1;
		FOR(i, 1, num)
		{
			int a;
			cin >> a;
			if (a == s)
				st = i;
			else if (a == e)
				et = i;
		}
		if (et != -1 && st != -1 && et > st)
			res = min(res, cost);
	}
	if (res == INF)cout << -1;
	else cout << res;
	return 0;
}
