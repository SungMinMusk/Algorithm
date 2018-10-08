/*
  문제 : https://www.acmicpc.net/problem/15949
  풀이 : 풀이랄게 없다. 쓰여있는 그대로 구현
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef queue<int> qi;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
/* -----구현부----- */
int DP = 2, CC = 1 ,n,m; //DP 1234 상우하좌 //CP 12 좌우
int now_block;
int arr[102][102];
bool visit[102][102];
map<int, char> color_map;
vector<char> res;
int nextDP()
{
	if (DP == 4)
		return 1;
	else
		return DP + 1;
}
int nextCC()
{
	if (CC == 1) return 2;
	else return 1;
}
int find(int start)
{
	vii v;
	pii point;
	if (DP == 1)
	{
		bool f = 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if (arr[i][j] == start)
				{
					v.push_back({ i,j });
					f = 0;
				}
			}
			if (!f) break;
		}
	}
	else if (DP == 2)
	{
		bool f = 1;
		for(int j=m;j>=1;j--)
		{
			for(int i=1;i<=n;i++)
			{
				if (arr[i][j] == start)
				{
					v.push_back({ i,j });
					f = 0;
				}
			}
			if (!f) break;
		}
	}
	else if (DP == 3)
	{
		bool f = 1;
		for (int i = n; i >= 1; i--)
		{
			for (int j=m;j>=1;j--)
			{
				if (arr[i][j] == start)
				{
					v.push_back({ i,j });
					f = 0;
				}
			}
			if (!f) break;
		}
	}
	else if (DP == 4)
	{
		bool f = 1;
		for (int j = 1; j<=m;j++)
		{
			for (int i=n;i>=1;i--)
			{
				if (arr[i][j] == start)
				{
					v.push_back({ i,j });
					f = 0;
				}
			}
			if (!f) break;
		}
	}
	if (CC == 1) point = v[0];
	else point = v[v.size() - 1];
	//반환 
	pii next;
	if (DP == 1) next = { point.first-1,point.second };
	else if (DP == 2) next = { point.first,point.second+1 };
	else if (DP == 3) next = { point.first+1,point.second };
	else if (DP == 4) next = { point.first,point.second - 1 };
	return arr[next.first][next.second];
}
void bfs(pii start,int num)
{
	int color = arr[start.first][start.second];
	qii q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		arr[now.first][now.second] = num;
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] == color)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
int main()
{
	SWS;
	//입력
	FOR(i, 0, 101) FOR(j, 0, 101) arr[i][j] = 'X';
	cin >> n >> m;
	FOR(i, 1, n)
	{
		string s;
		cin >> s;
		FOR(j, 1, m)
		{
			arr[i][j] = s[j - 1];
			if (i == 1 && j == 1)
				res.push_back(arr[i][j]);
		}
	}
	int num = 0;
	FOR(i, 1, n)
	{
		FOR(j, 1, n)
		{
			if (!visit[i][j] && arr[i][j] != 'X')
			{
				color_map[num] = arr[i][j];
				bfs({ i,j }, num);
				num++;
			}
            if(num=='X') num++;
		}
	}
	while (1)
	{
		int next;
		int ch_cnt=0;
		bool is_cc_ch = 0 , is_dp_ch = 1;
		next = find(now_block);
		//8가지 경우 탐색
		while (ch_cnt < 7 && next == 'X')
		{
			ch_cnt++;
			if (is_cc_ch == 1)
			{
				is_cc_ch = 0;
				is_dp_ch = 1;
				DP = nextDP();	
			}
			else if (is_dp_ch == 1)
			{
				is_cc_ch = 1;
				is_dp_ch = 0;
				CC = nextCC();
			}
			next = find(now_block);
		}
	
		if (ch_cnt == 7)
		{
			FOR(i, 0, res.size() - 1)
				cout << res[i];
			return 0;
		}
		res.push_back(color_map[next]);
		now_block = next;
	}
	return 0;
}
