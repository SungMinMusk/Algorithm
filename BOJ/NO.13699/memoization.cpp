/*
  문제 : https://www.acmicpc.net/problem/13699
  풀이 : 점화식의 결과를 메모이제이션을 이용하여 도출한다.
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
ll arr[40];
ll ans(int n)
{
	if (n == 0) return 1;
	if (arr[n] != 0) return arr[n];
	else
	{
		ll sum = 0;
		FOR(i, 0, n - 1)
			sum += ans(i)*ans(n - 1 - i);

		return arr[n]=sum;
	}

}
int main()
{
	SWS;

	int n;
	cin >> n;
	cout << ans(n);

	return 0;
}
