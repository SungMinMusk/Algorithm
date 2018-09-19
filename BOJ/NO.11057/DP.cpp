#include<iostream>
#define MOD 10007
using namespace std;
int d[1001][11];

void ans(int n)
{
	for (int i = 0; i <= 9; i++) d[1][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for(int k = 0 ; k <= j ; k++)
				 d[i][j] += d[i - 1][j - k];
			d[i][j] %= MOD;
		} 
	}
}

int main()
{
	int a=0;
	int n;
	cin >> n;
	ans(n);
	for (int i = 0; i <= 9; i++) a += d[n][i];
	cout << a % MOD;
	return 0;
}
