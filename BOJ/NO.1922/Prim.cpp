/*
	문제 : https://www.acmicpc.net/problem/1922
	풀이 : 프림알고리즘을 이용한 최소 비용 신장트리를 구한다.
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int >> v[1005]; 
priority_queue <pair<int, int> >q;
bool visit[1005];
int n, m, start;
int res = 0;

void prim(int start, int cnt)
{
	if (cnt == n - 1)
	{
		cout << res;
		return;
	}
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i].first] == false)
		{
			q.push(make_pair(-v[start][i].second, v[start][i].first));
		}
	}
	int tmp;
	while (1)
	{
		tmp = q.top().second;
		if (visit[tmp] == true)
		{
			q.pop();
			continue;
		}
		else
		{
			res += -q.top().first;
			q.pop();
			visit[tmp] = true;
			break;
		}
	}
	prim(tmp, cnt + 1);
}
int main()
{

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		if (i == 0) start = a;
	}
	visit[start] = true;
	prim(start, 0);
	return 0;
}
