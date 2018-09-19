/*
	문제 : https://www.acmicpc.net/problem/7453
	풀이 : 두 원소씩 묶은 후 이분탐색으로 합이 0인 범위를 찾는다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#define INF 0x7fffffff
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int a[4001];
int b[4001];
int c[4001];
int d[4001];
vi v1, v2;

int main()
{
	SWS;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	// A+B를 저장하는 벡터
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v1.push_back(a[i] + b[j]);
	// C+D를 저장하는 벡터
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v2.push_back(c[i] + d[j]);

	// 두 벡터를 정렬함
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	// C+D를 저장한 벡터에서 A+B 각 원소에 부호가 반대인 값을 가지는 범위를 찾음
	long long res = 0;
	for (int i = 0; i <v1.size(); i++)
	{
		vector<int>::iterator it;
		vector<int>::iterator it2;
		it = lower_bound(v2.begin(), v2.end(), -v1[i]);
		it2 = upper_bound(v2.begin(), v2.end(), -v1[i]);
		if (*it + v1[i] == 0)
			res += it2 - it;
	}
	cout << res;

	return 0;
}
