/*
  문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy
  풀이 : 큐를 적극적으로 활용한다. 접수대기하는 wa, 정비대기하는 wb큐를 활용한다.
      도착하는 시간을 정렬후 wa큐에 넣고 wa큐에서 빼면서 접수를 진행하고 접수가 끝나면 wb큐에 넣고 
      정비가 끝나는 정비소에 wb큐에서 빼면서 정비를 해준다.
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
int n, m, k, x, y;
int a[10], b[10];
int user[1001];
pii A[10], B[10];
pii visit[1001];
void init()
{
	FOR(i, 0, 1000)
	{
		visit[i] = { 0,0 };
		user[i] = 0;
	}
	FOR(i, 0, 9)
	{
		a[i] = 0;
		b[i] = 0;
		A[i] = { 0,0 };
		B[i] = { 0,0 };
	}
}
int main()
{
	SWS;
	int t;
	cin >> t;
	
	FOR(z, 1, t)
	{
		init();
		qi wa, wb;
		vii v;
		cin >> n >> m >> k >> x >> y;
		FOR(i, 1, n) cin >> a[i];
		FOR(i, 1, m) cin >> b[i];
		FOR(i, 1, k) 
		{ 
			cin >> user[i];
			v.push_back({ user[i],i }); 
		}
		sort(v.begin(), v.end());
		FOR(i, 0, (int)v.size() - 1) wa.push( v[i].second );

		int time = -1;
		while (1)
		{
			time++;
			FOR(i, 1, n)
			{
				if (A[i].first != 0 && A[i].second + a[i] == time)
				{
					wb.push(A[i].first);
					A[i] = { 0,0 };
				}
				if (!wa.empty() && A[i].first == 0 && user[wa.front()] <= time)
				{
					visit[wa.front()].first = i;
					A[i].first = wa.front();
					A[i].second = time;
					wa.pop();
				}
			}

			FOR(i, 1, m)
			{
				if (B[i].first != 0 && B[i].second + b[i] == time)
					B[i] = { 0,0 };
				if (!wb.empty() && B[i].first == 0)
				{
					visit[wb.front()].second = i;
					B[i].first = wb.front();
					B[i].second = time;
					wb.pop();
				}
			}

			//종료조건
			bool f = 1;
			FOR(i, 1, k)
			{
				if (!visit[i].first || !visit[i].second)
				{
					f = 0;
					break;
				}
			}

			if (f)
			{
				int sum = 0;
				FOR(i, 1, k)
					if (visit[i].first == x && visit[i].second == y)
						sum += i;
				if(sum)
					cout << "#" << z << " " << sum << endl;
				if(!sum)
					cout << "#" << z << " -1"<< endl;
				break;
			}
		}
	}
	return 0;
}
