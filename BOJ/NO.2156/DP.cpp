#include<iostream>
using namespace std;
int d[10001][3];
int a[10001];
int max(int n)
{
	int res=-1;
	for (int i = 0; i <= 2; i++)
	{
		if (res <= d[n-1][i]) res = d[n-1][i];
	}
	return res;
}
void ans(int n)
{

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (j == 0)
			{
				d[i][j] = max(i);
			}
			else if (j == 1) d[i][j] = d[i - 1][0] + a[i];
			else if (j == 2) d[i][j] = d[i - 1][1] + a[i];
		}
	}
	cout << max(n + 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1][0] = 0;
	d[1][1] = a[1];
	ans(n);
	/*
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}

