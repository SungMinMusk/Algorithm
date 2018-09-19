// https://www.acmicpc.net/problem/15685
#include<iostream>
#include<vector>
using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int map[101][101];
int n, x, y, d, g ,answer=0 ;

void ans()
{
	vector<int>v;
	map[x][y] = 1;
	x += dx[d];
	y += dy[d];
	map[x][y] = 1;
	v.push_back(d);
	
	while (g--)
	{
		for (int i = v.size() - 1; i >= 0; i--)
		{
			int new_dir = (v[i] + 1) % 4;
			x += dx[new_dir];
			y += dy[new_dir];
			map[x][y] = 1;
			v.push_back(new_dir);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> y >> x >> d >> g;
		ans();
	}
	
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				answer++;
		}
	}
	cout << answer;

	return 0;
}
