/*
  문제 : https://www.acmicpc.net/problem/9613
  풀이 : 2중반복문으로 2쌍을 뽑고 유클리드호제법으로 최대공약수를 구한다.
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
int dx[8] = { 0,0,-1,1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main()
{
	SWS;
	int n;
	cin >> n;
	while (n--)
	{
		vi v;
		seti st;
		int a;
		cin >> a;
		
		while (a--)
		{
			int b;
			cin >> b;
			v.push_back(b);
		}
		ll sum = 0;
		FOR(i, 0, (int)v.size() - 2)
			FOR(j, i + 1, (int)v.size() - 1)
				sum+=gcd(v[i], v[j]);

		cout << sum << endl;
	}
	
	return 0;
}
