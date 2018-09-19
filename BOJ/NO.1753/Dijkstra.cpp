//https://www.acmicpc.net/problem/1753
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#define INF 1000000000
using namespace std;
int num, e, start;
int u, v, w;
vector<pair<int, int> > a[20001]; //first : 노드 , second : 가중치
int d[20001];

void Dijkstra()
{
	d[start] = 0;
	//first에 가중치를 음수로 넣어 줌 ,second : 노드 
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, start));

	while (!q.empty())
	{
		int now = q.top().second;
		int now_d = -q.top().first;
		q.pop();
		if (d[now] < now_d) continue;
		for (int i = 0; i < a[now].size(); i++)
		{
			int next = a[now][i].first;
			int next_d = now_d + a[now][i].second;
			if (d[next] > next_d)
			{
				d[next] = next_d;
				q.push(make_pair(-next_d, next));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//초기화
	for (int i = 0; i < 20001; i++)
		d[i] = INF;
	//입력
	cin >> num >> e;
	cin >> start;

	//간선 입력
	for (int i = 1; i <= e; i++)
	{
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
	}

	Dijkstra();
	for (int i = 1; i <= num; i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
	return 0;
}
