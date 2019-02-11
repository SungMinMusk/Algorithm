/*
  문제 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD
  풀이 : 백트래킹으로 가볍게 해결하면 된다.
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
/* ----- 함수 ----- */
string str;
int n, res;
map<pair<int,string>, bool> visit;
void ans(int cnt)
{
	if(cnt==n)
	{ 
		int tmp = stoi(str);
		res = max(res, tmp);
		return;
	}

	int len = str.length()-1;
	FOR(i, 0, len-1)
	{
		FOR(j, i+1, len)
		{
			if (str[j] < str[i]) continue;
			swap(str[i], str[j]);
			if (!visit[{cnt, str}])
			{
				visit[{cnt, str}] = 1;
				ans(cnt + 1);
			}
			swap(str[i], str[j]);
		}
	}
}
int main()
{
	//freopen("tc.txt", "r", stdin);
	SWS;
	int z;
	cin >> z;
	FOR(i, 1, z)
	{
		//초기화
		res = -1;
		visit.clear();
		//
		cin >> str >> n;
		ans(0);
		cout << "#" << i << " " <<res<< endl;
	}
	return 0;
}
