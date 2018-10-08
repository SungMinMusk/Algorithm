/*
   문제 : https://www.acmicpc.net/problem/5588
   풀이 : 찾고자 하는 별자리에서 한점을 골라 사진속의 모든 별과 매칭하여 dx,dy를 찾는다.
          그리고 그것을 기준으로 모든 점이 매칭되는 것이 존재하는지 찾는다.
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
vii a;
map<pii, bool>b;
int n, m;
int main()
{
	SWS;
	//입력 & 전처리
	cin >> n;
	FOR(i, 1, n)
	{
		int x, y;
		cin >> x >> y;
		a.push_back({ x,y });
	}
	cin >> m;
	FOR(i, 1, m)
	{
		int x, y;
		cin >> x >> y;
		b[{x, y}] = 1;
	}
	sort(a.begin(), a.end());

	for(auto it=b.begin();it!=b.end();it++)
	{
		int dx = it->first.first- a[0].first;
		int dy = it->first.second - a[0].second;
		bool f = 0;
		FOR(j, 0, n-1)
		{
			int nx = a[j].first + dx;
			int ny = a[j].second + dy;
			if (b[{nx, ny}] != 1)
			{
				f = 1;
				break;
			}
		}
		if (!f)
		{
			cout << dx << " " << dy;
			return 0;
		}
	}
	return 0;
}
