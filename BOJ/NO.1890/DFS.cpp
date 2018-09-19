// DFS로 시간초과 뜨는 코드 ..
// https://www.acmicpc.net/problem/1890
#include<iostream>
#include<vector>
using namespace std;
bool visit[101][101];
long long res = 0;
int N;
typedef struct node
{
	int x, y;
	int jump;
};
vector <node> v[101];

void dfs(node n)
{
	if (n.x == N && n.y == N && n.jump == 0)
	{
		res++;
		return;
	}
	else if (!n.jump) return;
	visit[n.x][n.y] = true;
	if (n.x + n.jump <= N)
	{
		dfs(v[n.x + n.jump][n.y]);
	}
	if (n.y + n.jump <= N)
	{
		dfs(v[n.x][n.y + n.jump]);
	}
}
int main()
{
	int tmp;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		v[i].push_back({ 0,0,0 });
		for (int j = 1; j <= N; j++)
		{
			cin >> tmp;
			node tmp_node = { i,j,tmp };
			v[i].push_back(tmp_node);
		}
	}
	dfs(v[1][1]);
	cout << res;
	return 0;
}
