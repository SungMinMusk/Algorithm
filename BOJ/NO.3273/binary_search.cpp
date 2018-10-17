/*
  문제 : https://www.acmicpc.net/problem/3273
  풀이 : 정렬을 한후 모든 원소에 대해 합이 M이 되는 원소를 이분탐색으로 찾는다.
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
int n, m,res;
vi v;
int main()
{
	SWS;
	cin >> n;
	FOR(i,1,n)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> m;

	sort(v.begin(), v.end());

	FOR(i, 0, (int)v.size() - 2)
	{
		auto it = lower_bound(v.begin()+i+1, v.end(), m - v[i]);
		if (*it+v[i] == m)
			res++;
	}
	
	cout << res;
	return 0;
}
