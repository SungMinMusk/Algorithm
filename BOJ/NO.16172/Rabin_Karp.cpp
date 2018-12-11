/*
  문제 : https://www.acmicpc.net/problem/16172
  풀이 : 라빈카프 알고리즘을 이용했다.
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
const int MOD = 1000000000;
inline int mod(long long n) 
{
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1)*MOD + n) % MOD; 
}

int main()
{
	string tmp, s, k;
	cin >> tmp >> k;
	FOR(i, 0, tmp.length() - 1)
	{
		if (tmp[i] >= '0' && tmp[i] <= '9') continue;
		s += tmp[i];
	}
	int ls = s.length(), lk = k.length();
	int hs = 0, hk = 0, pow = 1;

	FOR(i, 0, ls - lk)
	{
		if (i == 0)
		{
			FOR(j, 0, lk - 1)
			{
				hs = mod(hs+1LL*s[lk-1-j] * pow);
				hk = mod(hk+1LL*k[lk-1-j] * pow);
				pow = mod(pow * 2);
			}
			pow = mod(pow / 2);
		}
		else
		{
			hs = mod(2*(hs - 1LL*pow*s[i - 1]) + s[i + lk - 1]);
		}

		if (hs == hk)
		{
			bool f = 1;
			FOR(j, 0, lk - 1)
			{
				if (s[i + j] != k[j])
				{
					f = 0;
					break;
				}
			}
			if (f)
			{
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
