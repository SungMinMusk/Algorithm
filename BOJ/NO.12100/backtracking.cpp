/*
	문제 : https://www.acmicpc.net/problem/12100
	풀이 : 최대 5번을 움직므로 상하좌우 모든 경우의 수를 탐색한다.
		이동하는 방향에 같지 않은 숫자가 있다면 그 위에 숫자가 쌓인다.
		이동하는 방향에 같은 숫자가 있다면 그 위치에 숫자가 두배가 된다.
		5번 이동 후 보드에서 제일 큰 숫자를 result값으로 취한다.
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
#define pb push_back
#define pob pop_back
#define fi first
#define sc second 
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
int arr[22][22];
int n, res =-1;

void copy(int a[][22],int b[][22])
{
	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 22; j++)
			b[i][j] = a[i][j];
}

void game(int a[][22],int dir)
{
	if (dir == 0) //left
	{
		for (int i = 1; i <= n; i++)
		{
			qi q;
			for (int j = 1; j <= n; j++)
				if (arr[i][j] != 0)
					q.push(j);
			
			int k = 1;
			while (!q.empty())
			{
				int f = q.front();
				q.pop();
				if (q.empty())
				{
					arr[i][k] = arr[i][f];
					k++;
				}
				else if (arr[i][f] == arr[i][q.front()])
				{
					arr[i][k] = 2 * arr[i][f];
					q.pop();
					k++;
				}
				else
				{
					arr[i][k] = arr[i][f];
					k++;
				}
			}		
			for (int j = k; j <= n; j++) arr[i][j] = 0;
		}
	}
	else if (dir == 1) //right
	{
		for (int i = 1; i <= n; i++)
		{
			qi q;
			for (int j = n; j >= 1; j--)
				if (arr[i][j] != 0)
					q.push(j);

			int k = n;
			while (!q.empty())
			{
				int f = q.front();
				q.pop();
				if (q.empty())
				{
					arr[i][k] = arr[i][f];
					k--;
				}
				else if (arr[i][f] == arr[i][q.front()])
				{
					arr[i][k] = 2 * arr[i][f];
					q.pop();
					k--;
				}
				else
				{
					arr[i][k] = arr[i][f];
					k--;
				}
			}
			for (int j = k; j >= 1; j--) arr[i][j] = 0;
		}
	}
	else if (dir == 2) //up
	{
		for (int j = 1; j <= n; j++)
		{
			qi q;
			for (int i = 1; i <= n; i++)
				if (arr[i][j] != 0)
					q.push(i);

			int k = 1;
			while (!q.empty())
			{
				int f = q.front();
				q.pop();
				if (q.empty())
				{
					arr[k][j] = arr[f][j];
					k++;
				}
				else if (arr[f][j] == arr[q.front()][j])
				{
					arr[k][j] = 2 * arr[f][j];
					q.pop();
					k++;
				}
				else
				{
					arr[k][j] = arr[f][j];
					k++;
				}
			}
			for (int i = k; i <=n ; i++) arr[i][j] = 0;
		}
	}
	else //down
	{
		for (int j = 1; j <= n; j++)
		{
			qi q;
			for (int i = n; i >= 1; i--)
				if (arr[i][j] != 0)
					q.push(i);

			int k = n;
			while (!q.empty())
			{
				int f = q.front();
				q.pop();
				if (q.empty())
				{
					arr[k][j] = arr[f][j];
					k--;
				}
				else if (arr[f][j] == arr[q.front()][j])
				{
					arr[k][j] = 2 * arr[f][j];
					q.pop();
					k--;
				}
				else
				{
					arr[k][j] = arr[f][j];
					k--;
				}
			}
			for (int i = k; i >= 1; i--) arr[i][j] = 0;
		}
	}
}

void ans(int cnt)
{
	//종료조건
	if (cnt == 5)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				res = max(res,arr[i][j]);
		return;
	}

	int tmp[22][22];  
	copy(arr, tmp);

	for (int i = 0; i < 4; i++)
	{
		game(arr, i);
		ans(cnt + 1);
		copy(tmp,arr);
	}
}
int main()
{
	SWS;
	//보드값 입력
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	ans(0);
	cout << res;
	return 0;
}
