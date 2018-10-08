/*
  문제 : https://www.acmicpc.net/problem/14246
  풀이 : 투포인터를 사용한다. 끝
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
int arr[100001];
ll n, k, res;
int main()
{
	SWS;
	//값 입력
	cin >> n;
	FOR(i, 1, n)
		cin >> arr[i];
	cin >> k;

	//투 포인터
	int s = 1, e = 1;
	int sum = arr[1];
	while (e <= n)
	{
		if (sum > k)
		{
			res += n - e + 1;
			sum -= arr[s++];
			if(s==e) 
				sum += arr[++e];
		}
		else
			sum += arr[++e];
	}
	cout << res;
	return 0;
}
