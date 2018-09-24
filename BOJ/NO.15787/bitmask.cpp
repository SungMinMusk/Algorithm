/*
  문제 : https://www.acmicpc.net/problem/15787
  풀이 : 좌석의 칸수가 20개이므로 int형 변수에 bitmask를 이용한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
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
int n, m,res;
int train[100001];
map<int, bool> ma;
int main()
{
	SWS;
	cin >> n >> m;

	FOR(i, 1, m)
	{
		int a, b, c;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			train[b] |= (1 << c - 1);
		}
		else if (a == 2)
		{
			cin >> c;
			train[b] &= ~(1 << c - 1);
		}

		else if (a == 3)
			train[b] <<= 1;
	
		else
			train[b] >>= 1;

		FOR(j, 20, 31) train[b] &= ~(1 << j);
	}

	//중복이 없는 기차갯수만 ++
	FOR(i, 1, n)
	{
		if (!ma[train[i]])
		{
			ma[train[i]] = 1;
			res++;
		}
	}
	cout << res;
	return 0;
}
