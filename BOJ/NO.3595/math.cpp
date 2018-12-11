/*
  문제 : https://www.acmicpc.net/problem/3595
  풀이 : 주어진 수의 약수들에 대해 전부 탐색한다.
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
/* -----구현부----- */
int n,minv=INF,a,b,c;
vi v;

int main()
{
	SWS;
	cin >> n;
	FOR(i, 1, n)
		if (n%i == 0) v.push_back(i);

	for (int &i : v)
	{
		for (int &j : v)
		{
			for (int &k : v)
			{
				if (i*j*k != n) continue;
				int tmp = i * j + j * k + k * i;
				if (minv > tmp)
				{
					minv = tmp;
					a = i;
					b = j;
					c = k;
				}
			}
		}
	}
	cout << a << " " << b << " " << c;
	return 0;
}
