/*
	문제 : https://www.acmicpc.net/problem/1197
	풀이 : 크루스칼 알고리즘을 이용한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
using namespace std;
int V, E;
int par[10001];
pair<int, int > edge[100001];

//정점의 부모를 찾는 함수, 부모가 같으면 같은 트리에 속함 = 사이클 존재
int find(int x) {
	if (x == par[x])
		return x;
	else
		return par[x] = find(par[x]);
}
int main()
{
	priority_queue<pair<int,int> > q;
	cin >> V >> E;
	//간선 정보 입력
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		//간선 가중치를 기준으로한 최소힙
		q.push(make_pair(-c,i));
		edge[i] = make_pair(a, b);
	}
	
	for (int i = 1; i <= V; i++)
		par[i] = i;
	long long res = 0;

	while (!q.empty())
	{
		pair<int,int> now = q.top();
		q.pop();
		int x = find(edge[now.second].first);
		int y = find(edge[now.second].second);
		
		//사이클 존재시 스킵
		if (x == y)
			continue;
		//사이클 존재 X, 스패닝 트리로 선정
		else
			par[y] = x;

		res += now.first;
	}
	cout << -res;
	return 0;
}

