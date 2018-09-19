/*
	문제 : https://www.acmicpc.net/problem/1717
	풀이 : union - find를 이용한다.
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int n, m;
int arr[1000005];
int find(int a)
{
	if (a == arr[a])
		return arr[a];
	else
		return arr[a] = find(arr[a]);
}
void uni(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	arr[pa] = pb;
}
int main()
{

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}
	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			uni(b, c);
		}
		else
		{
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
