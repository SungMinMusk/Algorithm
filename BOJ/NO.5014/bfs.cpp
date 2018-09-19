/*
문제 : https://www.acmicpc.net/problem/5014
풀이 : BFS
*/
#include<iostream>
#include<queue>
using namespace std;
int f, s, g, u, d;
int res = 100000000;
bool visit[1000001];
void ans(int start)
{
	queue <pair<int, int>>q;
	q.push(make_pair(start, 0));
	visit[start] = 1;
	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		if (now == g)
		{
			res = cnt;
			return;
		}
		q.pop();

		int next = now + u;
		//위로 가는 경우
		if (next <= f && visit[next] == 0)
		{
			q.push(make_pair(next, cnt + 1));
			visit[next] = 1;
		}
		//아래로 가는 경우
		next = now - d;
		if (next >= 1 && visit[next] == 0)
		{
			q.push(make_pair(next, cnt + 1));
			visit[next] = 1;
		}
	}

}
int main()
{
	//데이터 입력
	cin >> f >> s >> g >> u >> d;

	//시작점이 도착점이면 바로 0 출력
	if (s == g)
	{
		cout << "0";
		return 0;
	}

	//함수 호출
	ans(s);

	//결과 출력
	if (res == 100000000)
		cout << "use the stairs";
	else
		cout << res;
	return 0;
}
