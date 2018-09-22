/*
	문제 : https://www.acmicpc.net/problem/9935
	풀이 : 본래 문자열을 스택에다 넣으면서 찾으려는 문자열의 끝부분과 같아지면 이전에 넣은 것들도 비교하여
		찾으려는 문자열이 완성되면 전부 스택에서 뽑아준다.
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


int main()
{
	SWS;
	//입력
	string s, t;
	vector<char> st;
	cin >> s >> t;

	//처리
	int idx = t.length() - 1;
	FOR(i, 0, s.length() - 1)
	{	
		
		if (st.size()>=idx && s[i]==t[idx])
		{
			bool f = 1;
			int size = st.size();
			FOR(j, 1, idx)
			{
				if (st[size - j] != t[idx - j])
				{
					st.push_back(s[i]);
					f = 0;
					break;
				}
			}
			if(f)
			FOR(j, 1, idx)
				st.pop_back();
		}
		else
			st.push_back(s[i]);
	}

	//출력
	if (st.size() == 0)
		cout << "FRULA" << endl;
	else
		FOR(i, 0, st.size() - 1)
			cout << st[i];
	return 0;
}
