//https://www.acmicpc.net/problem/1697
#include<iostream>
#include<queue>
using namespace std;
int n, m;
bool visit[100005];

struct point
{
	int x;
	int level;
};
void ans()
{
	int res = 21000000;
	queue<struct point > q;
	q.push({ n,0 });
	visit[n] = true;
	while (!q.empty())
	{
		int now = q.front().x;
		int cnt = q.front().level;
		q.pop();
		if (now == m)
		{
			res = cnt;
			break;
		}
		if ( now+1 <= 100000 && now < m && visit[now + 1] == false )
		{
			q.push({ now + 1,cnt + 1 });
			visit[now + 1] = true;
		}
		if ( now - 1 >= 0 && visit[now - 1] == false )
		{
			q.push({ now - 1, cnt + 1 });
			visit[now - 1] = true;
		}
		if (2 * now <= 100000 && visit[2 * now] == false && now < m)
		{
			q.push({ 2 * now,cnt + 1 });
			visit[2*now] = true;
		}
	}
	cout << res;
}
int main()
{
	cin >> n >> m;
	visit[n] = true;
	ans();
	return 0;
}
