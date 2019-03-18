/*
  문제 : https://www.acmicpc.net/problem/1252
  풀이 : bool형 스택을 이용해서 풀이한다.
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
#include<unordered_map>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
#define unmap unordered_map
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { -1, 1 };
/* ----- -- ----- */
int a, b = 0;
vector<bool> s1, s2;
string a1, a2;
sti st;
int main() {
	cin >> a1 >> a2;
	for(int i = a1.length() - 1; i >= 0; i--) s1.push_back(a1[i] - '0');
	for(int i = a2.length() - 1; i >= 0; i--) s2.push_back(a2[i] - '0');
	while (s1.size() && s1[s1.size()-1] == 0) s1.pop_back();
	while (s2.size() && s2[s2.size()-1] == 0) s2.pop_back();
	while (s1.size() > s2.size()) s2.push_back(0);
	while (s1.size() < s2.size()) s1.push_back(0);
	if (s1.empty()) cout << 0;
	FOR(i,0,s1.size()-1) {
		a = s1[i] + s2[i] + b;
		if (a >= 2) {
			b = 1;
			a -= 2;
		}
		else b = 0;
		st.push(a);
	}

	if (b == 1) {
		cout << 1;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
