/*
  문제 : https://www.acmicpc.net/problem/2210
  풀이 : 방문처리를 안한 백트랙킹으로 모든 경우를 탐색한다.
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
int arr[7][7];
int visit[1000000];
int res = 0;
void ans(pii pos, int cnt, string s)
{
	if (cnt == 6)
	{
		int a = stoi(s);
		if (!visit[a])
		{
			res++;
			visit[a] = 1;
		}
		return;
	}
	string tmp = s;
	FOR(i, 0, 3)
	{
		int nx = pos.first + dx[i];
		int ny = pos.second + dy[i];
		if (arr[nx][ny] != -1)
		{
			s += to_string(arr[nx][ny]);
			ans({ nx,ny }, cnt + 1, s);
			s = tmp;
		}
	}
}
int main()
{
	SWS;
	memset(arr, -1, sizeof(arr));
	FOR(i, 1, 5)
		FOR(j, 1, 5)
			cin >> arr[i][j];

	FOR(i, 1, 5)
		FOR(j, 1, 5)
			ans({ i,j }, 0, "");
	cout << res;
	return 0;
}
