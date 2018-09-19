/*
	문제 : https://www.acmicpc.net/problem/2252
	풀이 : 위상정렬 알고리즘을 이용함.
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int indeg[32001];
vector<int> v[32001];
int main()
{
	queue<int> q;
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indeg[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)q.push(i);
	while (!q.empty())
	{
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();
		for (int i = 0; i < v[tmp].size(); i++)
		{
			indeg[v[tmp][i]] --;
			if (indeg[v[tmp][i]] == 0) q.push(v[tmp][i]);
		}
	}
	return 0;
}
