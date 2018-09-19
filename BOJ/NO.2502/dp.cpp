/*
	문제 : https://www.acmicpc.net/problem/2502
	풀이 : 피보나치 수열을 역으로 구한다고 생각한다.
		N번째 피보나치 수가 몇개의 1,2번째 피보나치수로 
		이루어졌는지 계산한다.
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
#define INF 0x7fffffff
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
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
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int df[35];
int ds[35];
int main()
{
	SWS;
	int n, k;
	cin >> n >> k;
	df[1] = 1; 
	ds[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		df[i] = df[i - 1] + df[i - 2];
		ds[i] = ds[i - 1] + ds[i - 2];
	}

	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i*df[n] + j * ds[n] == k)
			{
				cout << i << endl;
				cout << j;
				return 0;
			}
		}
	}
	return 0;
}
