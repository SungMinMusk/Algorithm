/*
  문제 : https://www.acmicpc.net/problem/9872
  풀이 : 입력 문자열을 정렬하여 한문자로 합친후 map컨테이너를 이용하여 갯수를 파악한다.
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

int main()
{
	SWS;
	map<string, int>m;
	int n,maxv=0;
	cin >> n;
	while (n--)
	{
		string s[3],t;
		cin >> s[0] >> s[1] >> s[2];
		sort(s, s + 3);
		t = s[0] + s[1] + s[2];
		m[t]++;
	}
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second > maxv) maxv = it->second;
	cout << maxv;
	return 0;
}
