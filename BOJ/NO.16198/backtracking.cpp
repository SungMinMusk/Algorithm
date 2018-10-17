/*
  문제 : https://www.acmicpc.net/problem/16198
  풀이 : 백트랙킹으로 가능한 모든 경우를 탐색한다.
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
vi v;
int n,res;
void ans(int sum)
{
	if (v.size() == 2)
	{
		res = max(res, sum);
		return;
	}
	vi tmp = v;
	FOR(i, 1, v.size() - 2)
	{
		int w = v[i - 1] * v[i + 1];
		v.erase(i+v.begin());
		ans(sum+w);
		v = tmp;
	}
}
int main()
{
	SWS;
	cin >> n;
	FOR(i, 1, n)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	ans(0);
	cout << res;
	return 0;
}
