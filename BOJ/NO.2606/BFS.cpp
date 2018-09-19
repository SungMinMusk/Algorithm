// https://www.acmicpc.net/problem/2606
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[110];
bool visit[110];
void ans()
{
	queue<int>q;
	int res=0;
	q.push(1);
	visit[1] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < v[tmp].size(); i++)
		{
			if (visit[v[tmp][i]] == false)
			{
				q.push(v[tmp][i]);
				visit[v[tmp][i]] = true;
				res++;
			}
		}
	}
	cout << res;
}
int main()
{
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans();
	return 0;
}
