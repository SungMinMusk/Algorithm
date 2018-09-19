/*
  문제 : https://www.acmicpc.net/problem/10815
  풀이 : 이분 탐색으로 카드를 소유 여부를 알아낸다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
vector<int>v;
int arr[500000];
int main()
{
	int n, m;
	//가진 숫자 카드 입력
	cin >> n;
	while (n--)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	//찾을 숫자 카드 입력
	cin >> m;
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);

	//가진 숫자카드 정렬
	sort(v.begin(), v.end());

	//이분 탐색
	vector<int>::iterator it;
	for (int i = 0; i < m; i++)
	{
		it = lower_bound(v.begin(), v.end(), arr[i]);
		if (*it == arr[i])
			printf("1 ");
		else
			printf("0 ");
	}
	return 0;
}
