/*
	문제 : https://www.acmicpc.net/problem/9663
	풀이 : N-Queen의 해를 백트래킹으로 구한다, 퀸은 한 행,열에 하나 밖에 없다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#define INF 0x7fffffff
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int > >vii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[17][17];
int n,res=0;

bool check(int x,int y)
{
	for (int i = 1; i <= n; i++)
	{
		//대각선 위 오른방향
		if (x - i >= 1 && y + i <= n)
			if (arr[x - i][y + i] == 1) return 0;
		//대각선 위 왼방향
		if (x - i >= 1 && y - i >= 1)
			if (arr[x - i][y - i] == 1) return 0;
		//위측
		if (x - i >= 1) 
			if (arr[x - i][y] == 1) return 0;
	}
	return 1;
}
void ans(int x,int y ,int cnt)
{
	if (cnt == n) 
	{
		res++;
		return; 
	}
	
	for (int j = 1; j <= n; j++)
	{
		if (check(x, j))
		{
			arr[x][j] = 1;
			ans(x+1, 1, cnt + 1);
			arr[x][j] = 0;
		}
	}
}
int main()
{
	cin >> n;
	ans(1,1,0);
	cout << res;
	return 0;
}
