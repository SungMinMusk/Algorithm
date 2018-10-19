/*
  문제 : https://www.acmicpc.net/problem/1016
  풀이 : 큰수의 제곱근까지의 소수를 찾는다. 각 소수의 제곱의 배수를 작은 수부터 큰 수까지 체크한다(범위가 크므로 해싱함)
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
string s;
ll a, b;
ll maxsq;
ll res;
bool visit[1000001];
bool prime[1000001];
void PrimeArray()
{
	ll m = maxsq;
	if (m <= 1) return;
	for (int i = 2; i <= m; i++) prime[i] = true;
	for (int i = 2; (i*i) <= m; i++)
	{
		if (prime[i] == true)
			for (int j = i * i; j <= m; j += i)
				prime[j] = false;
	}
}
int main()
{
	cin >> a >> b;
	maxsq = sqrt(b);
	PrimeArray();
	FOR(i, 2, maxsq)
	{
		if (prime[i] = false) continue;
		ll k = (ll)i * i;
		ll start = a /k;
		for (ll j = start; k*j <= b; j++)
		{
			if (k*j >= a && !visit[k*j - a])
			{
				visit[k*j - a] = 1;
				res++;
			}
		}
	}
	cout << (ll)b - a + 1 - res;
	return 0;
}
