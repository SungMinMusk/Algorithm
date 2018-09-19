//https://www.acmicpc.net/problem/14501
#include<iostream>
using namespace std;
int arr[16][2];
int n;
int res = 0;
void ans(int day,int pay)
{
	if (day == n+1)
	{
		res = (pay > res) ? pay : res;
		return;
	}
	ans(day + 1, pay);
	if(day+ arr[day][0] <= n+1)
		ans(day + arr[day][0], pay + arr[day][1]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];

	ans(1,0);
	cout << res;
	return 0;
}
