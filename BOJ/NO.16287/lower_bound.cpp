/*
  문제 : https://www.acmicpc.net/problem/16287
  풀이 : 택배를 두개씩 묶어 벡터에 넣은 후 이분탐색으로 원하는 택배 조합을 찾는다.
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
int w, n, arr[5001];
vector<pair<int, pii> > v;
int main()
{
	SWS;
	cin >> w >> n;
	FOR(i, 1, n)
		cin >> arr[i];

	FOR(i, 1, n)
		FOR(j, i + 1, n)
			v.push_back({ arr[i] + arr[j],{ i,j } });

	sort(v.begin(), v.end());
	FOR(i, 0, v.size() - 2)
	{
		pair<int, pii> a = { w - v[i].first,{ 0,0 } };
		auto it = lower_bound(v.begin(), v.end(), a);
		if (it->first == w - v[i].first)
		{
			if (v[i].second.first != it->second.first&&
				v[i].second.first != it->second.second&&
				v[i].second.second != it->second.first&&
				v[i].second.second != it->second.second)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
