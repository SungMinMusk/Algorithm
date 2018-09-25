/*
	문제 : https://www.acmicpc.net/problem/11971
	풀이 : 1km마다 제한속도,달린속도를 배열에 저장하여 비교한다.
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
int n, m, a, b, res;
vi v, y;
int main()
{
	SWS;
	//값 입력
	cin >> n >> m;
	while (n--)
	{
		cin >> a >> b;
		FOR(i, 1, a)
			v.push_back(b);
	}
	while (m--)
	{
		cin >> a >> b;
		FOR(i, 1, a)
			y.push_back(b);
	}

	//처리
	FOR(i, 0, 99)
		if (y[i] > v[i])
			res = max(res, y[i] - v[i]);
	cout << res;

	return 0;
}
