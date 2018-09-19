//https://www.acmicpc.net/problem/15649
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,m;
bool visit[9];
int res[9];
int num[9];
void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << res[i] << " ";
		cout << '\n';
		return;
	}
  
	for (int i = 0; i < n; i++)
	{
		if (visit[num[i]] == false)
		{
			res[cnt] = num[i];
			visit[num[i]] = true;
			dfs( cnt + 1);	
			visit[num[i]] = false;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) num[i]=i+1;
	dfs(0);
	return 0;
}
