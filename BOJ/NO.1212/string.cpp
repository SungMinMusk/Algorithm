/*
  문제 : https://www.acmicpc.net/problem/1212
  풀이 : 2진수로 변환하고 맨 앞의 0을 계속 없앤다.
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
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
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
string arr[8] = {"000","001","010","011","100","101","110","111"};
string res;
int main()
{
	SWS;
	string s;
	cin >> s;
	FOR(i, 0, s.length() - 1)
		res += arr[s[i] - '0'];
	while (res[0] == '0' && res.length()>1)
		res.erase(0,1);
	cout << res;
}
