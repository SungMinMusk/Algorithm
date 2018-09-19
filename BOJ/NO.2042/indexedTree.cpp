/*
	문제 : https://www.acmicpc.net/problem/2042
	-풀이-
	indexed tree를 이용하여 부분곱을 구한다.
*/
#include<iostream>
using namespace std;
//N의 4배로 넉넉하게 선언
long arr[4000000];
int n, m, k;
int leaf = 2;

//특정 값이 변경되어 indexed tree를 갱신하는 함수
void update(int a, int b)
{
	int idx = leaf - 1 + a;
	arr[idx] = b;
	idx /= 2;
	while (idx >= 1)
	{
		arr[idx] = arr[idx * 2 + 1] + arr[idx * 2];
		idx /= 2;
	}
}
//부분 곱을 찾는 함수
long find(int start, int end)
{
	long res = 0;
	start = start + leaf - 1;
	end = end + leaf - 1;
	while (start <= end)
	{
		if (start % 2 != 0)
		{
			res += arr[start];
			start++;
		}
		if (end % 2 == 0)
		{
			res += arr[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
//초기 indexed tree 세팅
void setting(int root)
{
	if (root * 2 < leaf)
		setting(root * 2);
	if (root * 2 + 1 < leaf)
		setting(root * 2 + 1);
	arr[root] = arr[root * 2] + arr[root * 2 + 1];
}
int main()
{
	//리프 노드 생성
	cin >> n >> m >> k;

	for (int i = 0; i < 31; i++)
	{
		if (n < leaf) break;
		leaf *= 2;
	}
	for (int i = leaf; i < leaf + n; i++)
		cin >> arr[i];
	for (int i = leaf + n; i < 2 * leaf; i++)
		arr[i] = 0;
	setting(1);


	//명령어 수행
	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << find(b, c) << endl;
	}
	return 0;
}
