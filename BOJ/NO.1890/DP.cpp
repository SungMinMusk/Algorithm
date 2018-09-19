// https://www.acmicpc.net/problem/1890
#include<iostream>
#include<vector>
using namespace std;
int a[101][101];
long long d[101][101];
void ans(int n) 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == 0) continue;
			if (i == j&& j == n) break;
			int jump = a[i][j];
			if (i + jump <= n)
			{
				d[i + jump][j] += d[i][j] ;
				//cout << i<<","<<j<<"->" << i + jump << "," << j << "," << d[i + jump][j] << endl;
			}
			if (j + jump <= n)
			{
				d[i][j + jump] += d[i][j] ;
				//cout << i << "," << j << "->" << i << "," << j + jump << "," << d[i][j + jump] << endl;
			}
			
		}
		
	}
	cout << d[n][n];
}
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> a[i][j];

	d[1][1] = 1;
	ans(N);
	return 0;
}
