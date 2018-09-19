// https://www.acmicpc.net/problem/15686
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;
int map[52][52];
int n, m;
int res = 1000000;
typedef struct point
{
	int x, y;
}pt;
vector<pt> chicken;
vector<pt> home;

int dis(pt a, pt b)
{
	int x, y;
	if (a.x > b.x)
		x = a.x - b.x;
	else
		x = b.x - a.x;
	if (a.y > b.y)
		y = a.y - b.y;
	else
		y = b.y - a.y;
	return x + y;
}

void dfs(int pos, int cnt, int prev, vector<pt> v)
{
	if (cnt != 0)
		v.push_back(chicken[prev]);
	if (cnt == m)
	{
		int sum = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int tmp=1000000;
			for (int j = 0; j < v.size(); j++)
			{
				if (tmp > dis(v[j], home[i]))
					tmp = dis(v[j], home[i]);
			}
			sum += tmp;
		}
		if (res > sum)res = sum;
		return;
	}
	for (int i = pos; i < chicken.size(); i++)
	{
		dfs(i + 1, cnt + 1, i, v);
	}
}

int main()
{
	int tmp;
	chicken.push_back({ 0, 0 });
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if (tmp == 2)chicken.push_back({ i,j });
			if (tmp == 1)home.push_back({ i,j });
			map[i][j] = tmp;
		}
	}
	
	dfs(1, 0, 0, {});
	cout << res << endl;
	return 0;
}
