/*
  문제 : https://www.acmicpc.net/problem/15684
  풀이 : 사다리를 놓을 수 있는 위치를 완전 탐색한다.
*/
#include<iostream>
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
bool sadari[32][12][12];
int arr[12][32];
int n, m, h;
int maxv;
void init()
{
	FOR(i, 1, n)
		arr[i][h + 1] = i;
}
bool game()
{
	FOR(i, 1, n)
	{
		int s = i;
		int f;
		FOR(j, 1, h + 1)
		{
			if (sadari[j][s-1][s]) s = s - 1;
			else if (sadari[j][s][s + 1]) s = s + 1;
			if (j == h + 1) f=arr[s][j];
		}
		//cout << f << endl;
		if (i != f) return false;
	}
	return true;
}
void dfs(int cnt,int r)
{
	if (cnt == maxv)
	{
		if (game())
		{
			cout << cnt;
			exit(0);
		}
		else return;
	}
	
	FOR(i, r, h)
	{
		FOR(j, 2, n)
		{
			if (!sadari[i][j - 2][j - 1] && !sadari[i][j-1][j])
			{
				sadari[i][j - 1][j] = 1;
				dfs(cnt + 1,i);
				sadari[i][j - 1][j] = 0;
			}	
		}
		
	}
}
int main()
{
	SWS;
	cin >> n >> m >> h;
	init();
	FOR(i, 1, m)
	{
		int a, b;
		cin >> a >> b;
		sadari[a][b][b + 1] = true;
	}
	FOR(i, 0, 3)
	{
		maxv = i;
		dfs(0,1);
	}
	cout << -1;
	return 0;
}
