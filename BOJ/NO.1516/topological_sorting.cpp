/*
	문제 : https://www.acmicpc.net/problem/1516
	풀이 : 위상 정렬 알고리즘을 이용해 풀이한다. 단, indeg가 0이 되게 하는 정점이 아니여도 
	시간에 영향을 줄 수 있다.(max값 활용)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n;
long long arr[501];
long long time[501];
int indeg[501];
vector<int> v[501];
int main()
{
	ios::sync_with_stdio(false);
	
	//건물 갯수 입력
	cin >> n;
	//건물 정보 입력
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		while (1)
		{
			int tmp;
			cin >> tmp;
			//-1입력시 정지
			if (tmp == -1) break;

			v[tmp].push_back(i);
			indeg[i]++;
		}
	}

	//큐에 바로 지을 수 있는 건물 푸시
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0)
		{
			q.push(i);
			time[i] = arr[i];
		}
	}
	//위상 정렬 알고리즘
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
	
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (--indeg[next] == 0)
				q.push(next);
			//indeg가 0이 되게 해야만 시간에 영향을 주는 것이 아님!!
			time[next] = max(time[now] + arr[next], time[next]);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", time[i]);
	return 0;
}
