/*
	문제 : https://www.acmicpc.net/problem/1238
	풀이 : 플로이드 워셜로 간선의 최소 가중치를 구한다.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x;
int arr[1100][1100];
const int INF = 210000000;
int main()
{
	cin >> n >> m >> x;
	//i==j를 제외하고 INF로 초기화
	for (int i = 0; i < 1100; i++)
		for (int j = 0; j < 1100; j++)
			if (i != j) arr[i][j] = INF;
	//간선 정보입력
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a][b] = c;
	}
	//플로이드 워셜
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
	//
	int MAXV = -1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i][x] != INF && arr[x][i] != INF)
			MAXV = max(MAXV, arr[i][x]+arr[x][i]);
	}
	
	cout << MAXV;
	return 0;
}

