/*
  문제 : https://www.acmicpc.net/problem/16204
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
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef stack<int> sti;
typedef stack<pair<int, int> > stii;
typedef queue<int> qi;
typedef queue<pair<int, int> > qii;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int> > pqii;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
vector<bool> f,b;
int main()
{
	SWS;
	int n, m, k;
	cin >> n >> m >> k;
	int fo = m, fx = n - m;
	int bo = k, bx = n - k;
	
	FOR(i, 1, fo) f.push_back(0);
	FOR(i, 1, fx) f.push_back(1);
	FOR(i, 1, bo) b.push_back(0);
	FOR(i, 1, bx) b.push_back(1);

	int cnt = 0;
	FOR(i, 0, n-1) if (f[i] == b[i])cnt++;
	cout << cnt;
	return 0;
}
