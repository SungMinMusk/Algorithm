/*
	문제 : https://www.acmicpc.net/problem/15683
	풀이 : CCTV의 기능적인 함수를 구현하고, 백트래킹으로 모든 경우의 수를 탐색한다.
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

int arr[10][10];
int n, m;	
vii v;
int result = INF;
void left(int x, int y)
{
	for (int i = y - 1; i >= 1; i--)
	{
		if (arr[x][i] == 0)
			arr[x][i] = 9;
		else if (arr[x][i] == 6)
			break;
	}
}
void right(int x, int y)
{
	for (int i = y + 1; i <= m; i++)
	{
		if (arr[x][i] == 0)
			arr[x][i] = 9;
		else if (arr[x][i] == 6)
			break;
	}
}
void up(int x, int y)
{
	for (int i = x - 1; i >= 1; i--)
	{
		if (arr[i][y] == 0)
			arr[i][y] = 9;
		else if (arr[i][y] == 6)
			break;
	}
}
void down(int x, int y)
{
	for (int i = x + 1; i <= n; i++)
	{
		if (arr[i][y] == 0)
			arr[i][y] = 9;
		else if (arr[i][y] == 6)
			break;
	}
}
void copy(int a[10][10], int b[10][10])
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = a[i][j];
}
int zero_counter()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == 0) res++;

	return res;
}
void cctv(int a,int dir,int x,int y) //
{
	switch (a)
	{
	case 1:
	{
		//0123 상 하 좌 우
		if (dir == 0)
			up(x, y);

		else if (dir == 1)
			down(x, y);
		
		else if (dir == 2)
			left(x, y);
		
		else
			right(x, y);
		
		break;
	}
	case 2:
	{
		if (dir == 0) //상하
		{
			up(x, y);
			down(x, y);
		}
		else //좌우
		{
			left(x, y);
			right(x, y);
		}
		break;
	}
	case 3:
	{
		if (dir == 0) //상우
		{
			up(x, y);
			right(x, y);
		}
		else if (dir == 1) // 상좌
		{
			up(x, y);
			left(x, y);
		}
		else if (dir == 2) //하우
		{
			down(x, y);
			right(x, y);
		}
		else if (dir == 3) //하좌
		{
			down(x, y);
			left(x, y);
		}
		break;
	}
	case 4:
	{
		if (dir == 0) //상하좌
		{
			up(x, y);
			down(x, y);
			left(x, y);
		}
		else if (dir == 1) //상하우
		{
			up(x, y);
			down(x, y);
			right(x, y);
		}
		else if (dir == 2) //좌우상
		{
			up(x, y);
			left(x, y);
			right(x, y);
		}
		else if (dir == 3) //좌우하
		{
			down(x, y);
			left(x, y);
			right(x, y);
		}
		break;
	}
	case 5:
	{
		up(x, y);
		down(x, y);
		left(x, y);
		right(x, y);
		break;
	}
	}
}

void ans(int cnt)
{
	if (cnt == v.size()) // 종료 조건
	{
		int count = zero_counter();
		result = min(result, count);
		return;
	}

	int x = v[cnt].first;
	int y = v[cnt].second;
	int t = arr[x][y]; //cctv타입
	int tmp[10][10];
	copy(arr, tmp);

	if (t == 1 || t == 3 || t == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			cctv(t, i, x, y);
			ans(cnt + 1);
			copy(tmp, arr);
		}
	}
	else if(t==2)
	{
		for (int i = 0; i < 2; i++)
		{
			cctv(t, i, x, y);
			ans(cnt + 1);
			copy(tmp, arr);
		}
	}
	else
	{
		cctv(t, 0, x, y);
		ans(cnt + 1);
		copy(tmp, arr);
	}

}
int main()
{
	SWS;
	memset(arr, -1, sizeof(arr));
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6)
				v.push_back(make_pair(i,j));
		}
	}

	ans(0);
	cout << result;
	return 0;
}
