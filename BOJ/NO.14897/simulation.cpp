/*
	문제 : https://www.acmicpc.net/problem/14891
	풀이 : 대충 맵핑해서 풀면 편한 문제.
*/
#include<iostream>
#include<string>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
using namespace std;
/* -----구현부----- */
bool w[5][10];
void rotate(int n,int dir)
{
	if (dir == -1)
	{
		int tmp = w[n][2];
		w[n][2] = w[n][3];
		w[n][3] = w[n][6];
		w[n][6] = w[n][9];
		w[n][9] = w[n][8];
		w[n][8] = w[n][7];
		w[n][7] = w[n][4];
		w[n][4] = w[n][1];
		w[n][1] = tmp;
	}
	else
	{
		int tmp = w[n][2];
		w[n][2] = w[n][1];
		w[n][1] = w[n][4];
		w[n][4] = w[n][7];
		w[n][7] = w[n][8];
		w[n][8] = w[n][9];
		w[n][9] = w[n][6];
		w[n][6] = w[n][3];
		w[n][3] = tmp;
	}
}
int main()
{
	SWS;
	FOR(i, 1, 4)
	{
		string s;
		cin >> s;
		w[i][2] = s[0] - '0';
		w[i][3] = s[1] - '0';
		w[i][6] = s[2] - '0';
		w[i][9] = s[3] - '0';
		w[i][8] = s[4] - '0';
		w[i][7] = s[5] - '0';
		w[i][4] = s[6] - '0';
		w[i][1] = s[7] - '0';
	}
	int n;
	cin >> n;
	while (n--)
	{
		int num, dir;
		cin >> num >>dir;
		bool a=0, b=0, c=0;
		if (w[1][6] != w[2][4]) a = 1;
		if (w[2][6] != w[3][4]) b = 1;
		if (w[3][6] != w[4][4]) c = 1;
		if (num == 1)
		{
			rotate(1, dir);
			if (a)
			{
				rotate(2, -dir);
				if (b)
				{
					rotate(3, dir);
					if (c)
						rotate(4, -dir);
				}
			}
		}
		else if (num == 2)
		{
			rotate(2, dir);
			if (a)
				rotate(1, -dir);
			if (b)
			{
				rotate(3, -dir);
				if (c)
					rotate(4, dir);
			}
		}
		else if (num == 3)
		{
			rotate(3, dir);
			if (c)
				rotate(4, -dir);
			if (b)
			{
				rotate(2, -dir);
				if (a)
					rotate(1, dir);
			}
		}
		else if (num == 4)
		{
			rotate(4, dir);
			if (c)
			{
				rotate(3, -dir);
				if (b)
				{
					rotate(2, dir);
					if (a)
						rotate(1, -dir);
				}
			}
		}
	}
	cout << w[1][2] + 2*w[2][2] + 4*w[3][2] + 8*w[4][2];
	return 0;
}
