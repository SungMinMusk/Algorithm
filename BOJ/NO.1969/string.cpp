/*
  문제 : https://www.acmicpc.net/problem/1969
  풀이 : 주어진 DNA의 각 인덱스별로 염기의 갯수를 구한다. 제일 큰 염기를 선택해 DNA를 만든다.
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
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
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
int n, m, cnt;
vs v;
string res;
int main()
{
	SWS;
	cin >> n >> m;
	FOR(z, 1, n)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	FOR(i, 0, m - 1)
	{
		int a = 0, c = 0, t = 0, g = 0;
		for (auto &j : v)
		{
			if (j[i] == 'A') a++;
			else if (j[i] == 'C') c++;
			else if (j[i] == 'T') t++;
			else g++;
		}

		int maxv = max({ a,t,g,c });
		cnt += a + t + g + c - maxv;

		if (maxv == a) res += 'A';
		else if (maxv == c) res += 'C';
		else if (maxv == g) res += 'G';
		else res += 'T';
	}
	cout << res << endl << cnt;
	return 0;
}
