/*
  문제 : https://www.acmicpc.net/problem/4999
  풀이 : 2번째 입력 문자열이 앞에 입력된 문자열에서 찾아지는 여부 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef queue<int> qi;
typedef vector<pair<int, int > >vii;
typedef priority_queue<int> pqi;
typedef queue<pair<int, int> > qii;
typedef pair<int, int > pii;
typedef vector<int> vi;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
/* -----구현부----- */
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.find(s2) == string::npos) cout << "no";
	else cout << "go";
	return 0;
}
