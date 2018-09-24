/*
  문제 : https://www.acmicpc.net/problem/14467
  풀이 : 스택배열을 만든다. 각소의 위치를 스택에 저장하고 다음 값이 들어올때 값을 비교하여 결과++ 해준다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<math.h>
#include<string.h>
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
int n,res;
sti st[11];
int main()
{
	SWS;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (!st[a].empty() && st[a].top() != b)
			res++;
		st[a].push(b);
	}
	cout << res;
	return 0;
}
