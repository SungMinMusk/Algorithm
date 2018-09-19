/*
	문제 : https://www.acmicpc.net/problem/1520
*/
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int arr[503][503];
int d[503][503];
int n, m;

int ans(int a, int b)
{
	if (a == n && b == m)
		return 1;

	if (d[a][b] != -1)
		return d[a][b];
	
	d[a][b] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (arr[nx][ny] < arr[a][b])
		{
			d[a][b] += ans(nx, ny);
		}
	}
	return d[a][b];
}
int main()
{
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			arr[i][j] = 1000000;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	cout<< ans(1, 1);
	return 0;
}
