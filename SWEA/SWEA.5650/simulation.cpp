/*
	문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
	풀이 : 그대로 짠다.!
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
typedef struct robot
{
	int x, y;
	int d;
}robot; robot ro;
int arr[102][102];
vii worm_hole[11];
int n, res;
/******************/
void init()
{
	fill(*arr, *arr + 102 * 102, 5);
	memset(worm_hole, 0, sizeof(worm_hole));
	res = -1;
}
int next_dir(int a)
{
	if (a == 1)
	{
		if (ro.d == 1) return 3;
		else if (ro.d == 2) return 4;
		else if (ro.d == 3) return 2;
		else if (ro.d == 4) return 1;
	}
	else if (a == 2)
	{
		if (ro.d == 1) return 2;
		else if (ro.d == 2) return 4;
		else if (ro.d == 3) return 1;
		else if (ro.d == 4) return 3;
	}
	else if (a == 3)
	{
		if (ro.d == 1) return 4;
		else if (ro.d == 2) return 3;
		else if (ro.d == 3) return 1;
		else if (ro.d == 4) return 2;
	}
	else if (a == 4)
	{
		if (ro.d == 1) return 3;
		else if (ro.d == 2) return 1;
		else if (ro.d == 3) return 4;
		else if (ro.d == 4) return 2;
	}
	else if (a == 5)
	{
		if (ro.d == 1) return 3;
		else if (ro.d == 2) return 4;
		else if (ro.d == 3) return 1;
		else if (ro.d == 4) return 2;
	}
}
pii next_worm(pii a)
{
	int num = arr[a.first][a.second];
	if (worm_hole[num][0] == a)
		return worm_hole[num][1];
	else
		return worm_hole[num][0];
}
pii next_point()
{
	if (ro.d == 1)
		return { ro.x - 1,ro.y };
	else if (ro.d == 2)
		return { ro.x,ro.y + 1 };
	else if (ro.d == 3)
		return { ro.x + 1,ro.y };
	else if (ro.d == 4)
		return { ro.x,ro.y - 1 };
}
int game(pii start, int dir)
{
	int result = 0;
	ro.x = start.first;
	ro.y = start.second;
	ro.d = dir;
	while (1)
	{
		pii next = next_point();
		if (next == start || arr[next.first][next.second] == -1) return result;
		else if (arr[next.first][next.second] >= 1 && arr[next.first][next.second] <= 5)
		{
			ro.d = next_dir(arr[next.first][next.second]);
			ro.x = next.first;
			ro.y = next.second;
			result++;
		}
		else if (arr[next.first][next.second] >= 6 && arr[next.first][next.second] <= 10)
		{
			pii n = next_worm(next);
			ro.x = n.first;
			ro.y = n.second;
		}
		else if (arr[next.first][next.second] == 0)
		{
			ro.x = next.first;
			ro.y = next.second;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	FOR(z, 1, t)
	{
		init();
		cin >> n;
		FOR(i, 1, n)
		{
			FOR(j, 1, n)
			{
				cin >> arr[i][j];
				if (arr[i][j] >= 6 && arr[i][j] <= 10)
					worm_hole[arr[i][j]].push_back({ i,j });
			}
		}

		FOR(i, 1, n)
		{
			FOR(j, 1, n)
			{
				if (arr[i][j] == 0)
				{
					FOR(k, 1, 4)
					{
						int tmp = game({ i,j }, k);
						res = max(res, tmp);
					}
				}
			}
		}
		printf("#%d %d\n", z, res);
	}

	return 0;
}
