/*
	문제 : https://www.swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AWSHOpR6f_sDFARw&categoryId=AWSHOpR6f_sDFARw&categoryType=CODE
	풀이 : 시간,오작교이용,오작교생성,정보를 포함한 매개변수를 받는 dfs를 이용하여 구현을 한다.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define INF 0x7fffffff
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[12][12];
bool visit[12][12][2];
int res , n, m;

typedef struct point
{
	int x, y, time; //x,y좌표와 지난 시간
	bool use; // 이전에 오작교를 이용했는지
	bool make; // 이전에 오작교를 만들었는지
}p;

//교차로 확인 , 직각으로 두개씩 확인한다.
bool cross(int x, int y)
{
	if (arr[x + 1][y] == 0 && arr[x][y - 1] == 0)
		return 1;
	if (arr[x + 1][y] == 0 && arr[x][y + 1] == 0)
		return 1;
	if (arr[x - 1][y] == 0 && arr[x][y + 1] == 0)
		return 1;
	if (arr[x - 1][y] == 0 && arr[x][y - 1] == 0)
		return 1;
	return 0;
}

//dfs모든 경우 탐색
void dfs(p point)
{
	// 시간이 이미 초과했으면 볼 필요 없음
	if (point.time >= res) return; 

	// 도착 했을 경우 res에 더 적은 시간 대입
	if (point.x == n && point.y == n)
	{
		res = min(res, point.time);
		return;
	}

	//상하좌우 방향 
	for (int i = 0; i < 4; i++)
	{
		int nx = point.x + dx[i];
		int ny = point.y + dy[i];

		if (arr[nx][ny] != -1) //경계를 넘지 X면
		{
			//오작교를 생성하는 경우
			if (arr[nx][ny] == 0 && !point.use && !point.make && !cross(nx, ny) && !visit[nx][ny][1])
			{
				int t = point.time + m - (point.time % m);
				visit[nx][ny][1] = 1;
		
				dfs({ nx,ny,t,1,1 });

				visit[nx][ny][1] = 0;
			}
			//만들어진 오작교를 이용하는 경우
			else if (arr[nx][ny] > 1 && !point.use && !visit[nx][ny][0])
			{
				int t = point.time + arr[nx][ny] - (point.time % arr[nx][ny]);
				visit[nx][ny][0] = 1;

				dfs({ nx,ny, t ,1,point.make });

				visit[nx][ny][0] = 0;
			}
			//도로를 이용하는 경우
			else if (arr[nx][ny] == 1 && !visit[nx][ny][0])
			{
				visit[nx][ny][0] = 1;

				dfs({ nx,ny,point.time + 1,0,point.make });

				visit[nx][ny][0] = 0;
			}
		}
	}

}

int main()
{
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		//배열 초기화
		memset(arr, -1, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		
		//데이터 입력
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &arr[i][j]);

		//함수 실행
		res = INF;
		dfs({ 1, 1, 0, 0, 0 });

		//결과 출력
		cout << "#" << z << " " << res << '\n';
	}
	return 0;
}
