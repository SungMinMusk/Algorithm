// https://www.acmicpc.net/problem/1389
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kavin[101];
bool visit[101];
typedef struct node
{
	int num;
	int level = 0;
}node;
vector<node> v[101];
int bfs(int n,int goal)
{
	queue<node> q;
	for(int i=0;i< v[n].size() ; i++)
	{ 
		node a = v[n][i];
		a.level = 1;
		q.push(a);
		visit[a.num] = true;
	}
	while (!q.empty())
	{
		node tmp = q.front();
		if (tmp.num == goal) return tmp.level;
		q.pop();
		for (int i = 0; i < v[tmp.num].size(); i++)
		{
			node next = v[tmp.num][i];
			if (visit[next.num] == false)
			{
				next.level = tmp.level + 1;
				q.push(next);
				visit[next.num] = true;
			}
		}
	}
}

void ans(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			for (int z = 0; z <= 100; z++) visit[z] = false; //visit 초기화
			kavin[i] += bfs(i,j);
		}
	}
	int min = 2147483647;
	int res;
	for (int i = 1; i <= n; i++)
	{
		if (kavin[i] < min) { min = kavin[i]; res = i; }
	}
	cout << res;
}

int main()
{
	int n, m ,tmp1,tmp2;
	node x, y;

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2;
		x.num = tmp1; y.num = tmp2;
		v[x.num].push_back(y);
		v[y.num].push_back(x);
	}
	ans(n);
	return 0;
}
