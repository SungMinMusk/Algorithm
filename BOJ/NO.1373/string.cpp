/*
  문제 : https://www.acmicpc.net/problem/1373
  풀이 : 2진수를 8진수로 바꾸기 위해 3자리 단위로 파싱을 한다.
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
/* -----구현부----- */
string ans(string s)
{
	int res = 0;
	if (s[0] == '1') res += 4;
	if (s[1] == '1') res += 2;
	if (s[2] == '1') res += 1;
	return to_string(res);
}
int main()
{
	SWS;
	string s,res;
	cin >> s;
	if (s.length() % 3 == 1) s = "00" + s;
	else if (s.length() % 3 == 2) s = "0" + s;
	for(int i=0;i<=s.length()-3;i+=3)
		res += ans(s.substr(i, 3));
	cout << res;
	return 0;
}
