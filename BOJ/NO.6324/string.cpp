/*
  문제 : https://www.acmicpc.net/problem/6324
  풀이 : 문제에 지시하는 대로 코드를 작성한다.
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
int n;
int main()
{

	SWS;
	cin >> n;
	FOR(z,1,n)
	{
		string s, pro, host, port, path;
		cin >> s;
		//프로토콜
		if (s[0] == 'f') pro = "ftp";
		else if (s[0] == 'h') pro = "http";
		else if (s[0] == 'g') pro = "gopher";
		//
		int pos1 = s.find("://");
		s.erase(pos1, 3);
		int pos2 = s.find(":");
		int pos3 = s.find("/");
		//host
		int i = pos1;
		while (i<=s.length()-1&&s[i]!='/'&&s[i]!=':')
			host += s[i++];
		//port
		if (pos2 != string::npos)
		{
			int i = pos2+1;
			while (s[i] >= '0'&&s[i] <= '9')
				port += s[i++];
		}
		//path
		if (pos3 != string::npos)
		{
			FOR(i, pos3 + 1, s.length() - 1)
				path += s[i];
		}

		if (path == "") path = "<default>";
		if (port == "") port = "<default>";
		//출력
		cout << "URL #" << z << endl;
		cout << "Protocol = " << pro <<endl;
		cout << "Host     = " << host <<endl;
		cout << "Port     = " << port <<endl;
		cout << "Path     = " << path <<endl<<endl;
	}
	return 0;
}
