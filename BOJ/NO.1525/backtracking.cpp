/*
  문제 : https://www.acmicpc.net/problem/1525
  풀이 : 백트래킹 완전탐색으로 답을 찾으며 상태를 문자열로 만들어 visit처리한다(unordered_map 사용)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<float.h>
#define SWS ios_base::sync_with_stdio(0)
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
short arr[5][5];
unordered_map<string, bool> visit;
pair<short, short> zero;
string tostr()
{
	string s = "";
	FOR(i, 1, 3)
		FOR(j, 1, 3)
		s += arr[i][j] + '0';
	return s;
}
void ans()
{
	queue<pair<pair<short, short>, pair<string, int> > > q;
	q.push({ zero,{ tostr(), 0 } });
	visit[tostr()] = 1;
	while (!q.empty())
	{
		pair<short, short> now = q.front().first;
		string now_s = q.front().second.first;
		//cout << now_s << endl;
		int cnt = q.front().second.second;
		q.pop();

		int d = 0;
		FOR(i, 1, 3) FOR(j, 1, 3) arr[i][j] = now_s[d++] - '0';
		if (now_s == "123456780")
		{
			cout << cnt;
			exit(0);
		}
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (arr[nx][ny] == -1) continue;

			swap(arr[nx][ny], arr[now.first][now.second]);
			string s = tostr();
			if (!visit[s])
			{
				visit[s] = 1;
				q.push({ { nx,ny },{ s,cnt + 1 } });
			}
			swap(arr[nx][ny], arr[now.first][now.second]);
		}
	}

}
int main()
{
	SWS;
	memset(arr, -1, sizeof(arr));
	FOR(i, 1, 3)
	{
		FOR(j, 1, 3)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) zero = { i,j };
		}
	}

	ans();
	cout << -1;
	return 0;
}
