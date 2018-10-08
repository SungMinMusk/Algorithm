/*
  문제 : https://www.acmicpc.net/problem/16113
  풀이 : 각 숫자의 특징을 파악하여 구현한다.
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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int n;
string s;
string res;
int main()
{
	SWS;
	cin >> n >> s;
	int len = n / 5;

	for(int i=0;i<len;i++)
	{
		//공백처리
		if (s[i] == '.'&&s[i + 2 * len] == '.') continue;
		if (s[i] == '#' && s[i + 4 * len] == '#' &&(s[i + 1] == '.'||i+1==len))
			res += '1';
		//세칸차지
		else
		{
			if (s[i] == '#' && s[i + 1] == '#' && s[i + 2] == '#')
			{
				
				if (s[i + 1 + len] == '.'&&s[i + 1 + 2 * len] == '.'&&s[i + 1 + 3 * len] == '.')
				{
					if (s[i + 1 + 4 * len] == '#')
						res += '0';
					else
						res += '7';
				}
				else if (s[i + len] == '.'&&s[i + 3 * len] == '#')
					res += '2';
				else if (s[i + len] == '.'&&s[i + 3 * len] == '.' &s[i + 1 + 2 * len] == '#')
					res += '3';

				else if (s[i + len] == '#'&&s[i + 3 * len] == '.')
				{
					if (s[i + 2 + len] == '.') res += '5';
					else res += '9';
				}
				else if (s[i + len] == '#'&&s[i + 3 * len] == '#')
				{
					if (s[i + 2 + len] == '.') res += '6';
					else res += '8';
				}
				
			}
			else if (s[i] == '#' && s[i + 4 * len] == '.')
				res += '4';
			i += 2;
		}
	}
	cout << res;
	return 0;
}
