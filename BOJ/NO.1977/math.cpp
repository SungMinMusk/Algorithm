/*
  문제 : https://www.acmicpc.net/problem/1977
  풀이 : 미리 모든 완전제곱수를 구하고 범위내에서 체크만 해준다.
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
bool arr[100000001];
int main()
{
	FOR(i, 1, 10000)
		arr[i*i] = 1;

	ll sum = 0;
	int a, b, res = INF;
	cin >> a >> b;
	FOR(i, a, b)
	{
		if (arr[i])
		{
			sum += i;
			res = min(res, i);
		}
		
	}
	if (!sum) 
		cout << -1;
	else
		cout << sum << endl << res << endl;

	return 0;
}
