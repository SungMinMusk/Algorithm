#include<iostream>
using namespace std;
long long int d[101];
void ans(int n)
{
	for (int i = 4; i <= n; i++)
		d[i] = d[i - 2] + d[i - 3];
}
int main()
{
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans(n);
		cout << d[n] <<'\n';
	}
	return 0;
}
