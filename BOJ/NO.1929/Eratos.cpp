//https://www.acmicpc.net/problem/1929
#include<iostream>
using namespace std;
int n, m;
void eratos()
{
	bool * prime;
	if (m <= 1) return;

	prime = new bool[m + 1];
	//모두 1로 초기화
	for (int i = 2; i <= m; i++) prime[i] = true;
	//에라토스테네스의 체
	for (int i = 2; (i*i) <= m; i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= m; j += i)
				prime[j] = false;
		}
	}
	for (int i = n; i <= m; i++)
		if (prime[i] == true) 
			cout << i << '\n';
}
int main()
{
	cin >> n >> m;
	eratos();
	return 0;
}
