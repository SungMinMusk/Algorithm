/*
  문제 : https://www.acmicpc.net/problem/16162
  풀이 : 큐에 입력 숫자를 전부 넣고, 빼면서 등차수열을 이루는지 확인한다.
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
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */

int n, a, d;
int res = 0;
qi q;
int main(void)
{
	SWS;
	cin >> n >> a >> d;
	FOR(i, 1, n)
	{
		int qq;
		cin >> qq;
		q.push(qq);
	}
	while (!q.empty())
	{
		if (q.front()==a)
		{
			res++;
			a += d;
			q.pop();
		}
		else q.pop();
	}
	cout << res;

	return 0;
}
