// https://www.acmicpc.net/problem/2193
#include<iostream>
using namespace std;
long long d[91][2];
void ans(int n)
{
	for (int i = 2; i <= n; i++)
	{
		d[i][1] = d[i - 1][0];
		d[i][0] = d[i - 1][1] + d[i - 1][0];
	}
	cout << d[n][1] + d[n][0];
}
int main()
{
	int n;
	cin >> n;
	d[1][1] = 1;
	d[1][0] = 0;
	ans(n);
	return 0;
}
