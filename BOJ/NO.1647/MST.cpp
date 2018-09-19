/*
	문제 : https://www.acmicpc.net/problem/1647
	풀이 : 크루스칼 알고리즘을 이용하여 MST를 구한다. 단, 가장 긴 간선은 제외한다.
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct edge
{
	int w, from, to;
}edge;
edge e[1000010];
int V, E;
int par[100010];

int find(int num)
{
	if (num == par[num])
		return num;

	return par[num] = find(par[num]);
}

bool compare(const edge& a, const edge& b)
{
	return a.w < b.w;
}

int main()
{
	//...데이터 입력
	scanf("%d %d", &V, &E);

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[i] = { c,a,b };
	}

	//...부모 정보 초기화
	for (int i = 1; i <= V; i++)
		par[i] = i;

	//...간선 배열 정렬
	sort(e, e + E, compare);

	long long res = 0;
	int cnt = 0;
	//...크루스칼 알고리즘 이용 MST를 가장 긴 간선 제외하여 구함
	for (int i = 0; i < E; i++)
	{
		int x = find(e[i].from);
		int y = find(e[i].to);
		//...사이클이 생기면 넘김
		if (x == y)continue;

		par[y] = x;
		res += e[i].w;
		cnt++;
		if (cnt == V - 2) break;
	}
	cout << res;
	return 0;
}
