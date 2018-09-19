/*
  문제 : https://www.acmicpc.net/problem/3020
  풀이 : 각 높이별로 종유석,석순을 몇개나 충돌하는지 저장한다. 충돌 횟수는 장애물을 높이순으로 정렬하여 이분탐색으로 충돌갯수를 파악한다.
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
typedef multiset<int> mseti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
vi top, bot;
int w, h;
bool compare(int a, int b)
{
	return a > b;
}
int arr[500000];
int main()
{
	SWS;
	cin >> w >> h;
	FOR(i, 1, w/2)
	{
		int a, b;
		cin >> a >> b;
		bot.push_back(a);
		top.push_back(h - b);
	}
	sort(bot.begin(), bot.end(),compare);
	sort(top.begin(), top.end());


	int minv = INF;
	int res = 0;
	FOR(i, 0, h - 1)
	{
		auto it = lower_bound(bot.begin(), bot.end(),i,compare);
		arr[i] += it - bot.begin();

		it = upper_bound(top.begin(), top.end(),i);
		arr[i] += it - top.begin();
		
		minv = min(minv,arr[i]);
	}

	FOR(i, 0, h - 1)
	{
		if (arr[i] == minv)
			res++;
	}
	cout << minv << " "<<res;

	return 0;
}
