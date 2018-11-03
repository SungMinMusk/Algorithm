/*
  문제 : https://www.acmicpc.net/problem/5800
  풀이 : 성적순으로 정렬하면 되는 단순한 문제이다.
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
int main()
{
	SWS;
	int n;
	cin >> n;
	FOR(z, 1, n)
	{
		cout << "Class " << z << endl;;
		int a;
		vi v;
		cin >> a;
		while (a--)
		{
			int b;
			cin >> b;
			v.push_back(b);
		}
		int res = 0;
		sort(v.begin(), v.end());
		FOR(i, 1, v.size() - 1)
			res = max(res, v[i] - v[i - 1]);
		cout << "Max " << v[v.size() - 1] << ", Min " << v[0] << ", Largest gap " << res << endl;
	}
	return 0;
}
