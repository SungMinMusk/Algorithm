/*
  문제 : https://www.acmicpc.net/problem/15980
  풀이 : 부분합을 이용한다.
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
vector<pair<char, string> > v;
int sum[2001];
int n, m;
int res=INF,res_idx=INF;
int main()
{
	SWS;
	cin >> n >> m;
	FOR(i, 1, n)
	{
		char a; string s;
		cin >> a >> s;
		v.push_back({ a,s });
		
		if (a == 'L')
		{
			FOR(j, 0, m - 1)
				if (s[j] == '1') sum[j]--;
		}
		else
		{
			FOR(j, 0, m - 1)
				if (s[j] == '1') sum[j]++;
		}
	}

	FOR(i, 0, v.size()-1)
	{
		int tmp_res = 0, tmp = 0;
		if (v[i].first == 'L')
		{
			FOR(j, 0, m - 1)
			{
				if (v[i].second[j] == '1') tmp += sum[j] + 1;
				else tmp += sum[j];
				tmp_res = max(abs(tmp), tmp_res);
			}
		}
		else
		{
			FOR(j, 0, m - 1)
			{
				if (v[i].second[j] == '1') tmp += sum[j] - 1;
				else tmp += sum[j];
				tmp_res = max(abs(tmp), tmp_res);
			}
		}

		if (res > tmp_res)
		{
			res = tmp_res;
			res_idx = i + 1;
		}
	}
	cout << res_idx<<endl<<res<<endl;
}
