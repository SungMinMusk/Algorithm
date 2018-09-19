//https://www.acmicpc.net/problem/2667
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int n;
int map[27][27];
bool visit[27][27];
int dx[4]={ 0,0,1,-1 };
int dy[4]={ 1,-1,0,0 };

typedef struct p
{
	int x, y;
}p;

int bfs(int i, int j)
{
	int res = 1;
	queue<p> q;
	q.push({ i,j });
	visit[i][j] = true;
	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			p next = { now.x + dx[i],now.y + dy[i] };
			if (map[next.x][next.y] ==1 && visit[next.x][next.y] == false)
			{
				q.push(next);
				visit[next.x][next.y] = true;
				res++;
			}
		}
	}
	return res;
}
void ans()
{
	vector<int> v;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] == 1 && visit[i][j] == false)
				v.push_back(bfs(i, j));

	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = s[j-1]-48;
		}
	}
	ans();
	return 0;
}
