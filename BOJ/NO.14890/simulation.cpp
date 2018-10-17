/*
문제 : https://www.acmicpc.net/problem/14890
풀이 : 높이가 낮아지면 경사로의 길이만큼 평지인지 탐색, 높이가 높아지면 지금까지 L길이의 평지인지 확인
계속 평지인 경우 평지의 길이를 계속 누적해간다.
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
int arr[102][102], n, l, res;
void ansY(int x, int y)
{
	int cont = 1;
	while (1)
	{
		//평지
		if (arr[x][y + 1] == arr[x][y])
		{
			cont++;
			y++;
		}
		//정지
		else if (arr[x][y + 1] == 0)
			break;
		//내려갈때
		else if (arr[x][y + 1] == arr[x][y] - 1)
		{
			FOR(i, 1, l)
			{
				if (arr[x][y + i] != arr[x][y] - 1 || arr[x][y + i] == 0)
					return;
			}
			y += l;
			cont = 0;
		}
		//올라감
		else if (arr[x][y + 1] == arr[x][y] + 1)
		{
			if (cont >= l)
			{
				y++;
				cont = 1;
			}
			else return;
		}
		else return;
	}
	res++;
}
void ansX(int x, int y)
{
	int cont = 1;
	while (1)
	{
		//평지
		if (arr[x + 1][y] == arr[x][y])
		{
			cont++;
			x++;
		}
		//정지
		else if (arr[x + 1][y] == 0)
			break;
		//내려갈때
		else if (arr[x + 1][y] == arr[x][y] - 1)
		{
			FOR(i, 1, l)
			{
				if (arr[x + i][y] != arr[x][y] - 1 || arr[x + i][y] == 0)
					return;
			}
			x += l;
			cont = 0;
		}
		//올라감
		else if (arr[x + 1][y] == arr[x][y] + 1)
		{
			if (cont >= l)
			{
				x++;
				cont = 1;
			}
			else return;
		}
		else return;
	}
	res++;
}
int main()
{
	SWS;
	cin >> n >> l;
	FOR(i, 1, n)
		FOR(j, 1, n)
		cin >> arr[i][j];

	FOR(i, 1, n)
	{
		ansX(1, i);
		ansY(i, 1);
	}
	cout << res;
	return 0;
}
