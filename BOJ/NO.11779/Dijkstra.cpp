// https://www.acmicpc.net/problem/11779
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
int n, m, start, ed;
int d[1001];
int trace[1001];
vector<pair<int, int> > v[1001];
void stra()
{
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, start));
	d[start] = 0;
	while (!q.empty())
	{
		int now = q.top().second;
		int now_d = -q.top().first;
		q.pop();

		if (d[now] < now_d) continue;
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].first;
			int next_d = now_d + v[now][i].second;
			if (next_d < d[next])
			{
				q.push(make_pair(-next_d, next));
				d[next] = next_d;
				trace[next] = now;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 1001; i++)
		d[i] = 100000000;
	cin >> n >> m;


	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(pair<int,int>(b, c));
	}
	cin >> start >> ed;
	//solve
	stra();
	//첫번째 결과 출력
	cout << d[ed] << endl;
	//역추적
	stack<int> st;
	int find = ed;
	st.push(ed);
	while (1)
	{
		st.push(trace[find]);
		find = trace[find];
		if (find == start) break;
	}
	//2~3번째 결과 출력
	cout << st.size() << endl;
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}
