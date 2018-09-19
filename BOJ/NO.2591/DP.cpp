//https://www.acmicpc.net/problem/2591
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int dp[40];
int main()
{
	string a;
	cin >> a;
	dp[0] = 1;
	dp[1] = 1;
	//시작 부터 0일때
	if (a[0] == '0')
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i < a.length(); i++)
	{
		//40같은 거 넣으면 안대~
		if (a[i - 1] - 48 >= 4 && a[i] == '0')
		{
			cout << 0;
			return 0;
		}
		//앞자리가 0이면 경우의수는 바뀌지 않는다 
		else if (a[i-1] == '0')
			dp[i + 1] = dp[i];
		//현자리 및 앞자리가 34보다작고 10의배수 아니면 앞 n-1자리 n-2자리 경우의수의 합이다
		else if ((a[i] - 48) + (a[i-1] - 48) * 10 <= 34 && a[i] !='0' )
			dp[i + 1] = dp[i] + dp[i - 1];
		//현자리 및 앞자리가 34보다작고 10의배수면 n-2자리의 경우를 따른다
		else if ((a[i] - 48) + (a[i - 1] - 48) * 10 <= 34 && a[i] == '0')
			dp[i + 1] = dp[i-1];
		//현자리및 앞자리가 34보다크면 n-1자리 경우를 따른다
		else if ((a[i] - 48) + (a[i - 1] - 48) * 10 > 34)
			dp[i + 1] = dp[i];
	}
	cout << dp[a.length()];
	return 0;
}
