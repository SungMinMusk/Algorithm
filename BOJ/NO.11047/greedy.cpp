//https://www.acmicpc.net/problem/11047
#include<iostream>
using namespace std;
int n, k;
int arr[11];
void ans()
{
	int res = 0;
	for (int i = n; i >= 1; i--)
	{
		if (k >= arr[i])
		{
			res += k / arr[i];
			k -= k / arr[i] * arr[i];
		}
	}
	cout << res;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	ans();
	return 0;
}
