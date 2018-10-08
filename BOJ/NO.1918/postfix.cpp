/*
  문제 : https://www.acmicpc.net/problem/1918
  풀이 : 스택을 활용한 후위표기식 출력문제이다.
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
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
stack<char>st;
string s;
string res;
int main()
{
	SWS;
	cin >> s;
	//
	FOR(i, 0, s.size() - 1)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			res += s[i];
		else if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == '+' || s[i] == '-')
		{
			while (!st.empty() && st.top()!='(')
			{
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			while (!st.empty() && (st.top() =='*' || st.top()=='/'))
			{
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (st.top() != '(')
			{
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		
	}
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	cout << res;
	return 0;
}
