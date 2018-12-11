/*
  문제 : boj.kr/7568
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
vii v;
int arr[51];
int main()
{
	SWS;
	int n;
	cin >> n;
	FOR(i, 1, n)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	int idx = 1;
	for (auto &i : v)
	{
		for (auto &j : v)
		{
			if (i.first < j.first && i.second < j.second)
				arr[idx]++;
		}
		idx++;
	}
	FOR(i, 1, n)
		cout << arr[i] + 1 << " ";
	return 0;
}
