/*
  문제 : https://www.acmicpc.net/problem/1193
  풀이 : 분수의 숫자가 커지고 작아지는 규칙을 찾는다.
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
int main()
{
	int n;
	cin >> n;
	int dir = 0;
	int x = 1, y = 1;

	FOR(i, 1, n-1)
	{
		if (dir == 0 && x == 1)
		{
			y++;
			dir = 1;
		}
		else if (dir == 1 && y == 1)
		{
			x++;
			dir = 0;
		}
		else if (dir == 0)
		{
			x--;
			y++;
		}
		else
		{
			x++;
			y--;
		}
	}
	printf("%d/%d", x, y);
	return 0;
}
