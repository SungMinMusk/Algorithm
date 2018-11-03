/*
  문제 : https://www.acmicpc.net/problem/3048
  풀이 : 개미가 바라보는 방향을 비교하여 자리를 바꿔준다! pair로 방향을 짝지어서 해결하면 편하다.
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
char a;
int n, m,k;
string s1, s2;
vector<pair<char, bool> >v;

int main()
{
	SWS;
	cin >> n >> m >> s1 >> s2 >> k;
	for (int i = n - 1; i >= 0; i--)
		v.push_back({ s1[i], 0 });
	for (int i = 0; i < m; i++)
		v.push_back({ s2[i], 1 });

	while (k--)
	{
		FOR(i, 0, (int)v.size() - 2)
		{
			if (v[i].second == 0 && v[i + 1].second == 1)
			{
				swap(v[i], v[i + 1]);
				i++;
			}
		}
	}
	FOR(i, 0, v.size() - 1)
		cout << v[i].first;

	return 0;
}
