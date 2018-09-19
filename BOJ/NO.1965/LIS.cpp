/*
	문제 : https://www.acmicpc.net/problem/1965
	풀이 : LIS를 구하는 문제이다. 이분탐색을 이용한 풀이를 한다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int arr[1001];
vector<int>v;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	v.push_back(arr[1]);
	for (int i = 2; i <= n; i++)
	{
		int e = v.size() - 1;
		int s = 0;
		//수열의 가장 큰 수보다 크다면
		if (v[e] < arr[i])
			v.push_back(arr[i]);
		// 아니면 이분 탐색
		else
		{
			int m;
			while (s<=e)
			{
				m = (s + e) / 2;
				if (v[m] == arr[i])
					break;
				else if (v[m] > arr[i])
					e = m - 1;
				else if (v[m] < arr[i])
					s = m + 1;
			}
			//arr[i]가 크기 순서에 맞는 위치에 들어가야 함
			if (v[m] < arr[i])
				v[m + 1] = arr[i];
			else
				v[m] = arr[i];
		}
	}
	cout << v.size();
	return 0;
}
