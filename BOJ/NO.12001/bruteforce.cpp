/*
  문제 : https://www.acmicpc.net/problem/12001
  풀이 : 입력된 점들의 모든 x,y값을 중복없이 탐색하며 (x,y)좌표의 우측상단을 기준으로 4분면으로 나눠
      점의 개수를 센다.
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
int dx[4] = { 1,-1,-1,1 };
int dy[4] = { 1,1,-1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int n, m,res = INF,resi = INF;
vii v;
seti xv, yv;
int main()
{
	SWS;
	cin >> n >> m;
	FOR(i, 1, n)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		xv.insert(a);
		yv.insert(b);
	}

	for(auto i=xv.begin();i!=xv.end();i++)
	{
		for (auto j = yv.begin(); j != yv.end(); j++)
		{
			
			int a = *i + 1, b = *j + 1;
			int arr[4] = { 0, };
			FOR(k, 0, v.size() - 1)
			{
				int x = v[k].first, y = v[k].second;
				if (x>a&&y>b) arr[0]++;
				else if (x<a&&y>b) arr[1]++;
				else if (x>a&&y<b) arr[2]++;
				else if (x<a&&y<b) arr[3]++;
			}
			sort(arr, arr + 4);
			
			if (res >= arr[3] - arr[0] && resi > arr[3])
			{
				res = arr[3] - arr[0];
				resi = arr[3];
			}
		}
	}
		
	cout << resi;
	return 0;
}
