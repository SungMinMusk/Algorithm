/*
  문제 : https://www.acmicpc.net/problem/16283
  풀이 : 양과 염소가 먹는 양을 반복문을 이용해 찾을때 까지 돌린다.
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
int a, b, n, w;
vii v;
int main()
{
	SWS;
	cin >> a >> b >> n >> w;
	FOR(i, 1, n - 1)
		if (a*i + b*(n - i) == w)
			v.push_back({ i,n-i });
	
	if (v.size() != 1)
		cout << -1;
	else
		cout << v[0].first << " " << v[0].second;
	return 0;
}
