// https://www.acmicpc.net/problem/1309

#include<iostream>
using namespace std;
int n, k;
int d[100001][3];
void ans()
{
	d[1][0] = 1;
	d[1][1] = 1;
	d[1][2] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][1])%9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][2])%9901;
	}
	cout << (d[n][0] + d[n][1] + d[n][2])%9901;
}
int main()
{
	cin >> n;
	ans();
	return 0;
}
