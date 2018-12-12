/*
  문제 : https://www.acmicpc.net/problem/15594
  풀이 : 1 3 4 5 6 2 와 1 2 3 7 4 5 6의 두가지 TC에 구현
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
/* -----구현부----- */
int main()
{
	SWS;
	int n, prev = -1;
	vi v;
	v.push_back(-1);
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;

		if (prev == a) continue;

		prev = a;
		v.push_back(a);
	}
	v.push_back(INF);

	FOR(i, 1, v.size() - 2)
	{
		if (v[i+1]<v[i])
		{
			int tmp = v[i+1];
			bool f = 1;
			FOR(j, 1, i-1)
				if (v[j] > tmp ) f = 0;

			int idx = i, cnt = 0;
			if(f)
			{
				while (v[idx + 1] < v[idx] && idx <= (int)v.size() - 2)
				{
					swap(v[idx + 1], v[idx]);
					cnt++;
					idx++;
				}	
			}
			else 
			{
				idx++;
				while (v[idx - 1] > v[idx] && idx >= 1)
				{
					swap(v[idx - 1], v[idx]);
					cnt++;
					idx--;
				}
			}	
			cout << cnt;
      			break;
		}
	}
	return 0;
}
