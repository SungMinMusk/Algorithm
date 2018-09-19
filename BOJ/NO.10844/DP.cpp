//https://www.acmicpc.net/problem/10844
#include<iostream>
#define MOD 1000000000
using namespace std;
int d[101][11];

void ans(int n)
{
	for (int i = 1; i <= 9; i++) d[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j-1 >= 0) d[i][j] += d[i - 1][j - 1];
			if (j+1 <= 9 ) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= MOD;
		} 
	}
}

int main()
{
	long long a=0;
	int n;
	cin >> n;
	ans(n);
	for (int i = 0; i <= 9; i++) a += d[n][i];
	cout << a % MOD;
	return 0;
}
