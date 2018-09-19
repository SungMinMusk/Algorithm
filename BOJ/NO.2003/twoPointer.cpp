/*
	문제 : https://www.acmicpc.net/problem/2003
	-풀이-
	두개의 포인터를 두어 목표값과 비교하여 시작포인터 또는 끝포인터를 움직인다.
*/
#include<iostream>
using namespace std;
int arr[10010];
int main()
{
	int n, m, res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//포인터 두개 선언 
	int i = 0, j = 0;
	int tmp = arr[0];
	while (i<n && j<n)
	{
		// 목표값과 같으면 포인터 둘다 ++
		if (tmp == m)
		{
			res++;
			tmp += arr[++j];
			tmp -= arr[i++];
		}
		//목적보다 크면 시작 포인터 증가
		else if (tmp > m)
			tmp -= arr[i++];
		//목적보다 작으면 끝 포인터 증가
		else
			tmp += arr[++j];
	}
	cout << res;
	return 0;
}
