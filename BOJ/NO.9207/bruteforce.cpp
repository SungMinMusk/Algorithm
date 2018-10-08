/*
  문제 : https://www.acmicpc.net/problem/9207
  풀이 : 완전탐색을 이용한 구현문제이다. NQueen과 비슷
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
int n = 6, m = 10, res;
char arr[20][20];
int count()
{
	int r = 0;
	FOR(i, 2, n)
		FOR(j, 2, m)
		if (arr[i][j] == 'o') r++;
	return r;
}
void dfs(int cnt, vii v)
{
	int tmp_cnt = count();
	bool flag = 1;

	FOR(z,0,v.size()-1)
	{
		pii now = v[z];
		if (arr[now.first][now.second] != 'o') continue;

		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			int nxx = nx + dx[i];
			int nyy = ny + dy[i];
			if (arr[nx][ny] == 'o' && arr[nxx][nyy] == '.' )
			{
				flag = 0;
				vii tmp;
				tmp.push_back({ nxx,nyy });
				FOR(i, 0, v.size() - 1)
					if (i != z) tmp.push_back(v[i]);
				//전
				arr[now.first][now.second] = '.';
				arr[nx][ny] = '.';
				arr[nxx][nyy] = 'o';
				//
				dfs(cnt + 1, tmp);
				//후
				arr[now.first][now.second] = 'o';
				arr[nx][ny] = 'o';
				arr[nxx][nyy] = '.';
			}

		}
	}
	if (flag)
	{
		res = min(res, tmp_cnt);
		return;
	}

}
int main(void)
{
	SWS;
	int t;
	cin >> t;
	while (t--)
	{
		//초기화
		res = INF;
		fill(*arr, *arr + 20 * 20, '#');
		vii v;

		//입력
		FOR(i, 2, n)
		{
			string s;
			cin >> s;
			FOR(j, 2, m)
			{
				arr[i][j] = s[j - 2];
				if (arr[i][j] == 'o') v.push_back({ i,j });
			}
		}

		dfs(0, v);
		cout << res << " " << v.size() - res << endl;
	}
	return 0;
}
