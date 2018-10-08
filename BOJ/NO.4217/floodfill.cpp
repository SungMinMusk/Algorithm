/*
  문제 : https://www.acmicpc.net/problem/4217
  풀이 : 각 신성문자의 구별은 빈공간의 갯수로 한다.
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
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
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
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
char arr[202][202];
int visit[202][202];

string trans(char a)
{
	if (a == '0')
		return "0000";
	if (a == '1')
		return "0001";
	if (a == '2')
		return "0010";
	if (a == '3')
		return "0011";
	if (a == '4')
		return "0100";
	if (a == '5')
		return "0101";
	if (a == '6')
		return "0110";
	if (a == '7')
		return "0111";
	if (a == '8')
		return "1000";
	if (a == '9')
		return "1001";
	if (a == 'a')
		return "1010";
	if (a == 'b')
		return "1011";
	if (a == 'c')
		return "1100";
	if (a == 'd')
		return "1101";
	if (a == 'e')
		return "1110";
	if (a == 'f')
		return "1111";
}
void back_ground(pii start)
{
	qii q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] == '0')
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
void ffill(pii start,int number)
{
	qii q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii now = q.front();
		q.pop();
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] == '1')
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
				arr[nx][ny] = number;
			}
		}
	}
}
char find(pii start)
{
	qii q;
	pii now;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		FOR(i, 0, 3)
		{
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (!visit[nx][ny] && arr[nx][ny] == '0')
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	FOR(i, 0, 3)
	{
		int nx = now.first + dx[i];
		int ny = now.second + dy[i];
		if (arr[nx][ny] != '0')
			return arr[nx][ny];
	}
}
int main()
{
	SWS;
	int test = 1;
	while (1)
	{
		//초기화
		FOR(i, 0, 201)
		{
			FOR(j, 0, 201)
				arr[i][j] = '0';
		}
		memset(visit, 0, sizeof(visit));
		map<char, int> letter;

		//값 입력
		int h, w;
		cin >> h >> w;
		w *= 4;
		if (!h && !w) return 0;
		FOR(i, 1, h)
		{
			string s,tmp;
			cin >> s;
			FOR(j, 0, s.length() - 1)
				tmp += trans(s[j]);
			FOR(j, 1, w)
				arr[i][j] = tmp[j - 1];
		}
		//배경 제외
		back_ground({ 0,0 });
		//플러드 필
		int letter_num = 1;
		FOR(i, 1, h)
		{
			FOR(j, 1, w)
			{
				if (!visit[i][j]&&arr[i][j]=='1')
				{
					ffill({ i,j }, letter_num);
					letter[letter_num] = 0;
					letter_num++;
				}
			}
		}
		//find
		FOR(i, 1, h)
		{
			FOR(j, 1, w)
			{
				if (!visit[i][j] && arr[i][j] == '0')
				{
					int l = find({ i,j });
					letter[l]++;
				}
			}
		}
		//
		vector<char>v;
		for (auto it = letter.begin(); it != letter.end(); it++)
		{
			if (it->second == 0)
				v.push_back('W');
			else if (it->second == 1)
				v.push_back('A');
			else if (it->second == 3)
				v.push_back('J');
			else if (it->second == 5)
				v.push_back('D');
			else if (it->second == 4)
				v.push_back('S');
			else if (it->second == 2)
				v.push_back('K');
		}
		//출력
		sort(v.begin(), v.end());
		cout << "Case " << test << ": ";
		FOR(i, 0, v.size() - 1)
			cout << v[i];
		cout << endl;
		test++;
	}
	return 0;
}
