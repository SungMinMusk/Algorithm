/*
  문제 : https://www.acmicpc.net/problem/9873
  풀이 : 모든 X,Y의 경우에 대해 조건을 만족하는 Z값을 이분 탐색으로 찾는다.
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
typedef multiset<int> mseti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
vi v;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int res = 0;
	FOR(i, 0, v.size() - 3)
	{
		FOR(j, i+1, v.size() - 2)
		{
			int d = v[j] - v[i];
			auto it = lower_bound(v.begin()+j+1, v.end(), v[j]+d );
			auto it2 = upper_bound(v.begin()+j+1, v.end(),v[j]+2*d );
			res += it2 - it;
		}
	}
	cout << res;
	return 0;
}
