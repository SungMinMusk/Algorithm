/*
  문제 : https://www.acmicpc.net/problem/5052
  풀이 : 트라이를 이용해 자식이 있으면서 특정 문자열의 끝점인 노드가 존재하면 NO를 출력
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
string s;
bool res;
typedef struct Trie {
	Trie *go[10];
	bool has_son;
	bool is_end;
	Trie() {
		FOR(i, 0, 9) go[i] = nullptr;
		is_end = has_son  = false;
	}
	~Trie() {
		FOR(i, 0, 9)
			if(go[i]) delete go[i];
	}
	void insert(int idx) {
		if (idx == s.length()) {
			is_end = true;
		}
		else
		{
			int to = s[idx] - '0';
			if (!go[to]) go[to] = new Trie;
			has_son = true;
			go[to]->insert(idx + 1);
		}
		if (is_end && has_son) res = false;
	}
}Trie;
int main() {
	SWS;
	int n, m;
	cin >> n;

	while (n--) {
		res = true;
		cin >> m;
		Trie *root = new Trie;
		while (m--) {
			cin >> s;
			root->insert(0);
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
		delete root;
	}
	return 0;
}
