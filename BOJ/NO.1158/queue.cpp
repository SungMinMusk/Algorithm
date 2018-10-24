/*
  문제 : https://www.acmicpc.net/problem/1158
  풀이 : q를 이용해 반복적으로 pop을 해주면서 다시 push해준다. 단 M번째는 그냥 pop만한다.
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
int n, m;
vi res;
qi q;
int main()
{
	SWS;
	cin >> n >> m;
	FOR(i, 1, n)
		q.push(i);

	while (!q.empty())
	{
		FOR(i, 1, m)
		{
			int now = q.front();
			q.pop();
			if (i != m) q.push(now);
			else res.push_back(now);
		}
	}

	cout << "<";
	FOR(i, 0, (int)res.size() - 1)
	{
		if (i == (int)res.size() - 1) cout << res[i]<< ">";
		else cout << res[i] << ", ";
	}
	return 0;
}
