/*
  문제 : https://www.acmicpc.net/problem/15898
  풀이 : 완전탐색을 이용하는 구현문제, 배열의 회전은 순서를 벡터에 저장하는 방법을 사용함.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<queue>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef stack<int> sti;
typedef queue<int> qi;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
/* -----구현부----- */
pii dir[4][16] =
{
{ {1,1},{ 1,2 },{ 1,3 },{ 1,4 },{ 2,1 },{ 2,2 },{ 2,3 },{ 2,4},
{3,1},{ 3,2 },{ 3,3},{ 3,4 },{4,1},{ 4,2 },{ 4,3 },{ 4,4 }},

 { {4,1},{3,1},{2,1},{1,1},{4,2},{3,2},{2,2},{1,2},{4,3},{3,3},{2,3},{1,3},
{4,4},{3,4},{2,4},{1,4} },

 { {4,4},{4,3},{4,2},{4,1},{3,4},{3,3},{3,2},{3,1},{2,4},{2,3},{2,2},{2,1},
{1,4} ,{1,3},{1,2},{1,1} },

 { {1,4},{2,4},{3,4},{4,4},{1,3},{2,3},{3,3},{4,3},{1,2},{2,2},{3,2},{4,2}
,{1,1},{2,1},{3,1},{4,1}}
};

/*----------------*/
pair<int,char> pot[7][7];
pair<int, char> mat[12][7][7];
int visit[11];
int n, res;
void copy(pair<int, char> a[7][7], pair<int, char> b[7][7])
{
	FOR(i, 1, 5)
		FOR(j, 1, 5)
			b[i][j] = a[i][j];
}
int get_qu()
{
	int red=0, blue=0, green=0, yellow=0;
	FOR(i, 1, 5)
	{
		FOR(j, 1, 5)
		{
			if (pot[i][j].second == 'R')
				red += pot[i][j].first;
			else if (pot[i][j].second == 'B')
				blue += pot[i][j].first;
			else if (pot[i][j].second == 'G')
				green += pot[i][j].first;
			else if (pot[i][j].second == 'Y')
				yellow += pot[i][j].first;
		}
	}
	return (7 * red + 5 * blue + 3 * green + 2 * yellow);
}
void input(int a,int num,pii st)
{
	int idx = 0;
	FOR(i, st.first, st.first + 3)
	{
		FOR(j, st.second, st.second + 3)
		{
			int x = dir[a][idx].first;
			int y = dir[a][idx].second;
			idx++;
			//품질
			pot[i][j].first += mat[num][x][y].first;
			if (pot[i][j].first < 0) pot[i][j].first = 0;
			else if (pot[i][j].first > 9) pot[i][j].first = 9;

			//색
			if (mat[num][x][y].second == 'W') continue;
			else pot[i][j].second = mat[num][x][y].second;
		}
	}
}

void ans(int cnt)
{
	if (cnt == 3)
	{
		int tmp = get_qu();
		res = max(tmp, res);
		return;
	}
	pair<int, char> tmp[7][7];
	copy(pot, tmp);
	FOR(i, 1, n)
	{
		if (!visit[i])
		{
			FOR(dir, 0, 3)
			{
				visit[i] = true;
				input(dir, i, { 1,1 });
				ans(cnt + 1);
				copy(tmp,pot);

				input(dir, i, { 1,2 });
				ans(cnt + 1);
				copy(tmp, pot);

				input(dir, i, { 2,1 });
				ans(cnt + 1);
				copy(tmp, pot);

				input(dir, i, { 2,2 });
				ans(cnt + 1);
				copy(tmp, pot);
				visit[i] = false;
			}
		}
	}
}
int main()
{
	SWS;
	FOR(i, 1, 5) FOR(j, 1, 5) pot[i][j] = { 0,'N' };
	cin >> n;
	FOR(i, 1, n)
	{
		FOR(j, 1, 4)
			FOR(k, 1, 4)
				cin >> mat[i][j][k].first;
		FOR(j, 1, 4)
			FOR(k, 1, 4)
				cin >> mat[i][j][k].second;
	}
	ans(0);
	cout << res;
	return 0;
}
