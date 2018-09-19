//https://www.acmicpc.net/problem/1149
#include<iostream>
using namespace std;
int a[1001][3]; //0:R 1:G 2:B
long long dp[1001][3];
int min(int a, int b) //숫자 두개 비교
{
	return (a > b) ? b : a;
}
void ans(int n)
{
	for (int i = 2; i <= n; i++) 
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + a[i][2];
	}
	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]); //결과 출력
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) //데이터 입력
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	dp[1][0] = a[1][0]; dp[1][1] = a[1][1]; dp[1][2] = a[1][2]; //데이터 초기화
	ans(n);
	return 0;
}
