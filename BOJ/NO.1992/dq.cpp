/*
  문제 : https://www.acmicpc.net/problem/1992
  풀이 : 분할 정복으로 풀이 가능하다. 
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
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { -1, 1 };
/* ----- -- ----- */
int n;
bool arr[65][65];
string ans(pii s, int len)
{
	string res;
	bool f = 0;
	int first = arr[s.first][s.second];
	FOR(i, s.first, s.first + len - 1)
		FOR(j, s.second, s.second + len - 1)
			if (arr[i][j] != first) f = 1;

	if (f)
	{
		len /= 2;
		res += '(';
		res += ans(s, len);
		res += ans({ s.first,s.second+len }, len);
		res += ans({ s.first+len,s.second}, len);
		res += ans({ s.first+len,s.second + len }, len);
		res += ')';
	}
	else res += first + '0';
	return res;
}
int main()
{
	SWS;
	cin >> n;
	FOR(i, 1, n)
	{
		string s;
		cin >> s;
		FOR(j, 1, n) arr[i][j] = s[j - 1]-'0';
	}
	cout << ans({ 1,1 }, n);
	return 0;
}
