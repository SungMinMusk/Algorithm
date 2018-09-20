/*
  문제 : https://www.acmicpc.net/problem/10656
  풀이 : 제시된 조건대로 구현을 하면 되는 문제이다.
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
char arr[52][52];
bool row[52][52];
bool col[52][52];
int n, m;
int res = 0;
void ans(int x, int y)
{
	if (arr[x][y + 1] == '.'&&arr[x][y + 2] == '.' &&arr[x][y-1]=='#'&&
		!col[x][y + 1] && !col[x][y + 2])
	{
		qii q;
		q.push({ x,y });
		while (!q.empty())
		{
			pii now = q.front();
			q.pop();
			col[now.first][now.second] = true;
			if (arr[now.first][now.second + 1] != '#')
				q.push({ now.first,now.second + 1 });
		}
		arr[x][y] = '!';
		res++;
	}
	else if (arr[x+1][y] == '.'&&arr[x+2][y] == '.' && arr[x-1][y]=='#'&&
		!row[x+1][y] && !row[x+2][y])
	{
		qii q;
		q.push({ x,y });
		while (!q.empty())
		{
			pii now = q.front();
			q.pop();
			row[now.first][now.second] = true;
			if (arr[now.first+1][now.second ] != '#')
				q.push({ now.first+1,now.second });
		}
		arr[x][y] = '!';
		res++;
	}
}
int main()
{
	//입력 
	fill(*arr, *arr+52*52, '#');
	cin >> n >> m;
	FOR(i, 1, n)
		FOR(j, 1, m)
			cin >> arr[i][j];
	
	//처리
	FOR(i, 1, n)
		FOR(j, 1, m)
			if (arr[i][j] == '.')
				ans(i, j);

	// 출력
	cout << res << endl;
	FOR(i, 1, n)
		FOR(j, 1, m)
			if (arr[i][j] == '!')
				cout << i << " " << j <<endl;

	return 0;
}
