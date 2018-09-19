// https://www.acmicpc.net/problem/14502
#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#define MAX 10
using namespace std;
int arr[MAX][MAX];
int temp_arr[MAX][MAX];
int xp[4] = { 0,0,1,-1 };
int yp[4] = { 1,-1,0,0 };
bool visit[MAX][MAX];
int N = 0, M = 0;
typedef struct Point
{
	int x, y;
}Point;
void copy(int a[MAX][MAX], int b[MAX][MAX])
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}
int v()
{
	queue <Point> qp;
	Point tmp;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 2 && visit[i][j] == 0)
			{
				qp.push({i,j});
			}
			while (!qp.empty())
			{
				tmp = qp.front();
				visit[tmp.x][tmp.y] = 1;
				qp.pop();
				for (int k = 0; k <4; k++)
				{
					int x = tmp.x + xp[k];
					int y = tmp.y + yp[k];
					if (arr[x][y] == 0 && visit[x][y] == 0)
					{
						arr[x][y] = 2;
						qp.push({x,y});
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			if (arr[i][j] == 0) res++;
	}
	return res;
}

int main()
{
	vector <Point> vp;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			arr[i][j] = -1;
		}
	}
	//입력 시작
	scanf("%d %d", &N, &M);
	Point tmp;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				tmp.x = i;
				tmp.y = j;
				vp.push_back(tmp);
			}
		}
	}
	copy(arr, temp_arr);
	int max = vp.size();
	int min = 0;
	for (int i = 0; i <= max -3; i++)
	{
		for (int j = i+1; j <= max - 2; j++)
		{
			for (int k = j + 1; k <= max-1; k++)
			{
				arr[vp[i].x][vp[i].y] = 1;
				arr[vp[j].x][vp[j].y] = 1;
				arr[vp[k].x][vp[k].y] = 1;
				int a=v();
				if (min < a) min = a;
				for (int i = 0; i < MAX; i++)
					for (int j = 0; j < MAX; j++)
						visit[i][j] = 0;
				copy(temp_arr, arr);
			}
		}
	}
	cout << min << endl;
	return 0;
}
