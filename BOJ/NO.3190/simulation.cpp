/*
  문제 : https://www.acmicpc.net/problem/3190
  풀이 : 구현문제! 원하는 대로 구현하자
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<float.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
int arr[102][102], n, k, m;
qii q;

int nextdir(int a,int n)
{ //동서남북 0123
	if (a == 0)
	{
		if (n == 'D') return 2;
		else return 3;
	}
	else if (a == 1)
	{
		if (n == 'D') return 3;
		else return 2;
	}
	else if (a == 2)
	{
		if (n == 'D') return 1;
		else return 0;
	}
	else if (a == 3)
	{
		if (n == 'D') return 0;
		else return 1;
	}
}
pii go(int d)
{
	if (d == 0) return { 0,1 };
	else if (d == 1) return { 0,-1 };
	else if (d == 2) return { 1,0 };
	else if (d == 3) return { -1,0 };
}
int main()
{
	memset(arr, -1, sizeof(arr));
	//입력
	cin >> n >> k;
	FOR(i, 1, n) FOR(j, 1, n) arr[i][j] = 0;
	arr[1][1] = 2;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	cin >> m;
	while (m--)
	{
		int a; char b;
		cin >> a >> b;
		q.push({ a+1,b });
	}

	pii tail = { 1,1 }, head = { 1,1 }, op = q.front();
	qii snake;
	int dir = 0, time = 0;
	q.pop();
	
	while (1)
	{
		time++;
		if (op.first == time)
		{
			dir = nextdir(dir,op.second);
			if (!q.empty())
			{
				op = q.front();
				q.pop();
			}
		}
		pii next = go(dir);
		head = { head.first + next.first,head.second + next.second };
		snake.push(head);

		if (arr[head.first][head.second] == 2 || arr[head.first][head.second] == -1)
			break;

		else if (arr[head.first][head.second] == 0)
		{
			arr[tail.first][tail.second] = 0;
			tail = snake.front();
			snake.pop();
		}
		arr[head.first][head.second] = 2;
	}
	cout << time;
	return 0;
}
