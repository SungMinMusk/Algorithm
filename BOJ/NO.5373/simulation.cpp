/*
  문제 : https://www.acmicpc.net/problem/5373
  풀이 : 큐브를 회전할때 바뀌는 위치를 전부 해본다. 반시계 방향 = 시계 방향 3번과 같다.
  -삼성 기출문제-
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef queue<pair<int, int> > qii;
typedef pair<int, int > pii;
typedef vector<int> vi;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
char arr[7][10];
int d[9] = {  7,4,1,8,5,2,9,6,3  };
void init()
{
	FOR(j, 1, 9) arr[1][j] = 'r';
	FOR(j, 1, 9) arr[2][j] = 'g';
	FOR(j, 1, 9) arr[3][j] = 'b';
	FOR(j, 1, 9) arr[4][j] = 'o';
	FOR(j, 1, 9) arr[5][j] = 'y';
	FOR(j, 1, 9) arr[6][j] = 'w';
}
void ans(char a)
{
	if (a == 'U')
	{
		int tmp[9];
		FOR(i, 0, 8)
			tmp[i] = arr[6][d[i]];
		FOR(i, 1, 9)
			arr[6][i] = tmp[i - 1];
		int a = arr[4][3], b = arr[4][2], c = arr[4][1];
		arr[4][3] = arr[2][3];
		arr[4][2] = arr[2][2];
		arr[4][1] = arr[2][1];

		arr[2][1] = arr[1][1];
		arr[2][2] = arr[1][2];
		arr[2][3] = arr[1][3];

		arr[1][3] = arr[3][3];
		arr[1][2] = arr[3][2];
		arr[1][1] = arr[3][1];

		arr[3][3] = a;
		arr[3][2] = b;
		arr[3][1] = c;
	}
	if (a == 'D')
	{
		int tmp[9];
		FOR(i, 0, 8)
			tmp[i] = arr[5][d[i]];
		FOR(i, 1, 9)
			arr[5][i] = tmp[i - 1];
		int a = arr[1][7], b = arr[1][8], c = arr[1][9];

		arr[1][7] = arr[2][7];
		arr[1][8] = arr[2][8];
		arr[1][9] = arr[2][9];

		arr[2][7] = arr[4][7];
		arr[2][8] = arr[4][8];
		arr[2][9] = arr[4][9];

		arr[4][7] = arr[3][7];
		arr[4][8] = arr[3][8];
		arr[4][9] = arr[3][9];

		arr[3][7] = a;
		arr[3][8] = b;
		arr[3][9] = c;
	}
	if (a == 'F')
	{
		int tmp[9];
		FOR(i, 0, 8)
			tmp[i] = arr[1][d[i]];
		FOR(i, 1, 9)
			arr[1][i] = tmp[i - 1];
		int a = arr[6][7], b = arr[6][8], c = arr[6][9];

		arr[6][7] = arr[2][9];
		arr[6][8] = arr[2][6];
		arr[6][9] = arr[2][3];

		arr[2][3] = arr[5][1];
		arr[2][6] = arr[5][2];
		arr[2][9] = arr[5][3];

		arr[5][1] = arr[3][7];
		arr[5][2] = arr[3][4];
		arr[5][3] = arr[3][1];

		arr[3][7] = c;
		arr[3][4] = b;
		arr[3][1] = a;
	}
	if (a == 'B')
	{
		int tmp[9];
		FOR(i, 0, 8)
			tmp[i] = arr[4][d[i]];
		FOR(i, 1, 9)
			arr[4][i] = tmp[i - 1];
		int a = arr[6][3], b = arr[6][2], c = arr[6][1];

		arr[6][3] = arr[3][9];
		arr[6][2] = arr[3][6];
		arr[6][1] = arr[3][3];

		arr[3][9] = arr[5][7];
		arr[3][6] = arr[5][8];
		arr[3][3] = arr[5][9];

		arr[5][7] = arr[2][1];
		arr[5][8] = arr[2][4];
		arr[5][9] = arr[2][7];

		arr[2][1] = a;
		arr[2][4] = b;
		arr[2][7] = c;
	}
	if (a == 'L')
	{
		int tmp[9];
		FOR(i, 0, 8)
			tmp[i] = arr[2][d[i]];
		FOR(i, 1, 9)
			arr[2][i] = tmp[i - 1];
		int a = arr[6][1], b = arr[6][4], c = arr[6][7];

		arr[6][1] = arr[4][9];
		arr[6][4] = arr[4][6];
		arr[6][7] = arr[4][3];

		arr[4][9] = arr[5][1];
		arr[4][6] = arr[5][4];
		arr[4][3] = arr[5][7];

		arr[5][1] = arr[1][1];
		arr[5][4] = arr[1][4];
		arr[5][7] = arr[1][7];

		arr[1][1] = a;
		arr[1][4] = b;
		arr[1][7] = c;
	}
	if (a == 'R')
	{
		int tmp[9];
		FOR(i, 0, 8)
			tmp[i] = arr[3][d[i]];
		FOR(i, 1, 9)
			arr[3][i] = tmp[i - 1];
		int a = arr[6][9], b = arr[6][6], c = arr[6][3];

		arr[6][9] = arr[1][9];
		arr[6][6] = arr[1][6];
		arr[6][3] = arr[1][3];

		arr[1][9] = arr[5][9];
		arr[1][6] = arr[5][6];
		arr[1][3] = arr[5][3];

		arr[5][9] = arr[4][1];
		arr[5][6] = arr[4][4];
		arr[5][3] = arr[4][7];

		arr[4][1] = a;
		arr[4][4] = b;
		arr[4][7] = c;
	}
}
int main()
{
	SWS;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		init();
		while (n--)
		{
			char a, b;
			cin >> a >> b;
			if (b == '-')
			{
				ans(a);
				ans(a); 
				ans(a);
			}
			else
				ans(a);
		}
		FOR(i, 1, 9)
		{
			cout << arr[6][i];
			if (i % 3 == 0) cout << endl;
		}
	}
	return 0;
}
