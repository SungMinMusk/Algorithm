#include<iostream>
using namespace std;
int d[31];
void ans(int n)
{
	for (int i = 3; i <= n; i++)
	{
		d[i] += 3 * d[i - 2];
		for (int j = 4; i - j >= 0; j += 2)
		{
			d[i] += 2 * d[i - j];
		}
	}
}
int main()
{
	int n;
	cin >> n;
	d[0] = 1;
	d[1] = 0;
	d[2] = 3;
	ans(n);
	cout << d[n];
	return 0;
}
