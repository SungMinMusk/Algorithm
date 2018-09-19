// https://www.acmicpc.net/problem/13458
#include<iostream>
using namespace std;
long long arr[1000004];
long long res;
long long n, B, C;
void ans()
{
	res= n;
	for (int i = 1; i <= n; i++)
	{
		arr[i] -= B;
		if (arr[i]>0) 
		{
			if (arr[i] % C)
				res += arr[i] / C + 1;
			else
				res += arr[i] / C;
		}
	}
	cout <<  res;
}
int main()
{
	//입력값 입력
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> B >> C;
	ans();
	return 0;
}
