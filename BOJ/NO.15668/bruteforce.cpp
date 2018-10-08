/*
  문제 : https://www.acmicpc.net/problem/15668
  풀이 : a+b=N이 성립하는 a의 최대값을 찾는 것이 관건, 완전탐색한다.
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
bool visit[10];
int main()
{
	SWS;
	//값 입력
	int n;
	cin >> n;
	FOR(i,1,98765)
	{
		memset(visit, 0, sizeof(visit));
		bool f = 1;
		string s1 = to_string(i);
		string s2 = to_string(n - i);
		FOR(a, 0, s1.length() - 1)
		{
			if (visit[s1[a] - '0'] == 1) f = 0;
			else visit[s1[a] - '0'] = 1;
		}

		FOR(a, 0, s2.length() - 1)
		{
			if (visit[s2[a] - '0'] == 1) f = 0;
			else visit[s2[a] - '0'] = 1;
		}

		if (f&&stoi(s1)>0&&stoi(s2)>0)
		{
			cout << s1 << " + " << s2;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
