/*
	문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
	풀이 : 입력 문자열을 length/4 까지 회전 시키면서 완전탐색한다.
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
int n, k;
int res = -1;
string s;
int next(int a)
{
	if (a == s.length() - 1) return 0;
	else return a + 1;
}
ll convert(string str)
{
	ll sum = 0;
	int x = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		int a;
		if (str[i] >= '0' && str[i] <= '9')
			a = str[i] - '0';
		else if (str[i] >= 'A'&&str[i] <= 'F')
			a = str[i] - 'A' + 10;
		sum += a * (int)pow(16, x);
		x++;
	}
	return sum;
}
int main()
{
	int t;
	cin >> t;
	FOR(z, 1, t)
	{
		res = -1;
		cin >> n >> k >> s;
		seti se;
		int size = s.length() / 4;
		FOR(point, 0, size - 1)
		{
			string tmp;
			int idx = point;
			int cnt = 0;
			while (cnt != s.length())
			{
				tmp += s[idx];

				if (tmp.length() == size)
				{
					se.insert(-convert(tmp));
					tmp = "";
				}
				cnt++;
				idx = next(idx);
			}
		}
		int i = 1;
		for (auto & a : se)
		{
			if (i == k) printf("#%d %d\n", z, -a);
			i++;
		}
	}

	return 0;
}
