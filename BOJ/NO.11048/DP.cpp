// https://www.acmicpc.net/problem/11048
#include<iostream>
#include<vector>
using namespace std;
int d[1001][1001];
int f[1001][1001];

void ans(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		int a=0, b=0, c=0;
		for (int j = 1; j <= m; j++)
		{
			if (i - 1 > 0) a = d[i - 1][j];
			if (j - 1 > 0) b = d[i][j - 1];
			if (i - 1 > 0 && j - 1 > 0) c = d[i - 1][j - 1];
			//a,b,c중에 max값
			d[i][j] = (c > ((a > b) ? a : b)) ? c : ((a > b) ? a : b) + f[i][j];
		}
	}
}
int main()
{

	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> f[i][j];

	ans(n, m);
	cout << d[n][m];
	return 0;
}
