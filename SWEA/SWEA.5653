/*
	문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo
	풀이 : 단위시간당 움직이는 bfs는 현재큐의 사이즈만큼 와일문을 하나 더 돌리면 된다.
		각 세포별로 time을 life의 두배로 정해주며 pop한번에 time을 1씩 줄인다. 또한 time이 0이되면 총 결과에서 1을 빼준다.
		*주의* 문제는 활성화된 다음 턴에 세포가 분열하지만, 활성화된 턴에 분열하도록 코딩을 하였으므로 글로벌 타임이 k가 되면 분열 하면 안된다!
		
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
int n, m, k, res, global_time;
typedef struct sell
{
	int life, time ,x, y;
};
pii arr[500][500];
queue<sell> q;
void result()
{
	FOR(i,0,499)
		FOR(j,0,499) 
			if (arr[i][j].first != -1) res++;
}
void ans()
{
	while (!q.empty())
	{
		int size = q.size();
		global_time++;

		if (global_time > k)
		{
			while (!q.empty())
				q.pop();
			return;
		}

		while(size--)
		{
			sell now = q.front();
			q.pop();
			if (arr[now.x][now.y].first != now.life) continue;
	
			now.time--;
			if (now.time == 0)
			{
				res--;
				continue;
			}

			q.push(now);
			if (now.life == now.time && global_time!=k) // 주의 부분
			{
				FOR(i, 0, 3)
				{
					int nx = now.x + dx[i];
					int ny = now.y + dy[i];
					pii next = arr[nx][ny];
					if (next.first == -1 || (next.first<now.life && next.second==global_time))
					{
						q.push({ now.life,2 * now.life+1 ,nx,ny });
						arr[nx][ny] = {now.life,global_time};
					}
				}
			}
		}
	}
}
int main()
{
	SWS;
	int t,a;
	cin >> t;
	FOR(z, 1, t)
	{
		//init
		FOR(i, 0, 499) FOR(j, 0, 499) arr[i][j] = { -1,0 };
		res = 0;
		global_time = 0;

		//입력
		cin >> n >> m >> k;
		FOR(i, 200, 200+n-1)
		{
			FOR(j, 200, 200+m-1)
			{
				cin >> a;
				if (a)
				{
					arr[i][j] = { a,0 };
					q.push({a,2*a,i,j});
				}
			}
		}
		ans();
		result();

		//결과 출력
		cout << "#" << z << " " << res << endl;
	}
	return 0;
}

