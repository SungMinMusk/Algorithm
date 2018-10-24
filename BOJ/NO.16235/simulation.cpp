/*
  문제 : https://www.acmicpc.net/problem/16235
  풀이 : 처음엔 '봄'과정을 우선순위큐로 구현을 했으나 시간이 많이 나와, vector를 sort하는 방향으로 변경하였다.
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
int dx[8] = { 0,0,-1,1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
vi tree[10][10];
int arr[10][10];
int yang[10][10];
int n, m, k, time;
void spring_and_summer()
{
	FOR(i, 0, n - 1)
	{
		FOR(j, 0, n - 1)
		{
			int sum = 0;
			int cnt = 0;
			sort(tree[i][j].begin(), tree[i][j].end());
			for(auto &k:tree[i][j])
			{
				if (yang[i][j] >= k)
				{
					yang[i][j] -= k;
					k++;
				}
				else
				{
					sum += k / 2;
					cnt++;
				}
			}
			yang[i][j] += sum;
			while (cnt--) tree[i][j].pop_back();
		}
	}
}
void fall_and_winter()
{
	FOR(i, 0, n - 1)
	{
		FOR(j, 0, n - 1)
		{
			int size = tree[i][j].size();
			FOR(k,0,size-1)
			{
				if (tree[i][j][k] % 5 == 0)
				{
					FOR(l, 0, 7)
					{
						int nx = i + dx[l];
						int ny = j + dy[l];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n)
							tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
	FOR(i, 0, n - 1)
		FOR(j, 0, n - 1)
		yang[i][j] += arr[i][j];
}
int main()
{
	fill(*yang, *yang + 10 * 10, 5);
	SWS;
	cin >> n >> m >> k;
	FOR(i, 0, n - 1)
	{
		FOR(j, 0, n - 1)
			cin >> arr[i][j];
	}
	FOR(i, 1, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a - 1][b - 1].push_back(c);
	}

	while (1)
	{
		spring_and_summer();
		fall_and_winter();
		time++;
		if (time == k)
		{
			int res = 0;
			FOR(i, 0, n - 1)
				FOR(j, 0, n - 1)
				res += tree[i][j].size();

			cout << res;
			return 0;
		}
	}
	return 0;
}
