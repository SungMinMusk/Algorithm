/*
  문제 : https://www.acmicpc.net/problem/2075
  풀이 : 메모리 제한이 있으므로 우선순위 큐의 사이즈를 N으로 유지한다.
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
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int> > pqii;
/* ----- 함수 ----- */
int main()
{
	SWS;
	int n;
	cin >> n;
	pqi q;
	FOR(i, 1, n*n)
	{
		int a;
		cin >> a;
		q.push(-a);

		if (q.size() > n)
			q.pop();
	}
	cout << -q.top();
	return 0;
}
