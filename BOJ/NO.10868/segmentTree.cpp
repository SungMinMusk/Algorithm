/*
  문제 : https://www.acmicpc.net/problem/10868
  풀이 : 세그먼트트리를 이용해 구간의 최솟값을 구한다.
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
int arr[410000];
int n, m, k = 0;
int MIN(int L, int R, int node, int nl, int nr)
{
	if (R<nl || L>nr) return INF;
	if (L <= nl && nr <= R) return arr[node];
	int mid = (nl + nr) / 2;
	return min(MIN(L, R, node * 2, nl, mid), MIN(L, R, node * 2 + 1, mid + 1, nr));
}
void update(int i, int val) 
{
	arr[i] = val;
	while (i > 1)
	{
		i /= 2;
		arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
	}
}
void setting()
{
	fill(arr, arr + 410000, INF);
	while ((1<<k) < n)
		k++;
	k = (1 << k);
}
int main()
{
	SWS;
	cin >> n >> m;
	setting();
	FOR(i, k, k + n - 1)
	{
		int a;
		cin >> a;
		update(i, a);
	}

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		cout << MIN(a-1, b-1, 1, 0, k-1) << endl;
	}
	return 0;
}
