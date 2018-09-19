#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> v[1001];
bool c[1001];
void dfs(int start)
{
	if (c[start]) return;
	c[start] = true;
	cout << start<<" ";
	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		dfs(next);
	}
}
void bfs(int start)
{
	queue <int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty())
	{
		int next = q.front();
		cout << next << " ";
		q.pop();
		for (int i = 0; i < v[next].size() ; i++)
		{
			int p = v[next][i];
			if (!c[p]) 
			{
				q.push(p); 
				c[p] = true;
			}
		}
	}
}
int main()
{
	int n, m, start;
	cin >> n >> m >> start;
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
    for (int i = 0; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(start);
	cout << '\n';
	for (int i = 0; i <=n; i++) c[i] = false;
	bfs(start);
	cout << '\n';
	return 0;
}
