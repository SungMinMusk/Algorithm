/*
  문제 : https://www.acmicpc.net/problem/11652
  풀이 : 우선 카드를 정렬하고 숫자를 센다. 같은 숫자만 들어오는 경우를 주의
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<math.h>
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
/* -----구현부----- */
ll n, res;
vector<ll> v;
int main()
{
	SWS;
	cin >> n;
	while(n--)
	{
		ll a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	ll prev = v[0] , cnt = 1, maxv = 0;
	FOR(i,1,v.size()-1)
	{
		if (v[i] == prev)
			cnt++;
		else
		{
			if (cnt > maxv)
			{
				maxv = cnt;
				res = prev;
			}
			prev = v[i];
			cnt = 1;
		}
	}
  // 같은 숫자만 들어오는 경우를 위함
	if (cnt > maxv)
		res = v[v.size() - 1];
	cout << res;
	return 0;
}
