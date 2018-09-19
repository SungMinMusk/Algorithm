#include<iostream>
using namespace std;
int p[10001];

void ans(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (p[i] < p[i - j] + p[j]) p[i] = p[i - j] + p[j];
		}
	}
	cout << p[n];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	ans(n);
	return 0;
}
