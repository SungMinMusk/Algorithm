/*
	문제 : https://www.acmicpc.net/problem/10657
	풀이 : 스택에 속력을 넣어간다. 넣으면서 원래 스택에 본래보다 빠른 속도는 뽑아준다.
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
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int n;
stack<int> st;
vii v;
int main()
{
	SWS;
	cin >> n;
	FOR(i, 1, n)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	FOR(i, 0, v.size() - 1)
	{
		while (!st.empty() && st.top() > v[i].second)
			st.pop();
		st.push(v[i].second);
	}
	cout << st.size();
	return 0;
}
