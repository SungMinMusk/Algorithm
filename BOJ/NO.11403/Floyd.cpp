/*
	문제 : https://www.acmicpc.net/problem/11403
	풀이 : 플로이드-워셜 알고리즘을 이용하여 간선을 구한다.
*/
#include<iostream>
#include<cstdio>
using namespace std;
int arr[200][200];
int main()
{
  //간선 정보 입력
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
      
	//플로이드 워셜 알고리즘 이용
	for (int k = 1; k <= n; k++)
		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= n; i++)
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
        
	//전체 간선 정보 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}
