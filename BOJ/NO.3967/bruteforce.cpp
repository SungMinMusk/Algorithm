/*
  문제 : https://www.acmicpc.net/problem/3967
  풀이 : 채워야하는 좌표를 벡터에 넣고, 남은 알파벳끼리 순열을 만들어 완전탐색한다.
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
#define FOR(a,b,c) for(int a=b;a<=(int)c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef stack<int> sti;
typedef stack<pair<int, int> > stii;
typedef queue<int> qi;
typedef queue<pair<int, int> > qii;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int> > pqii;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;
typedef set<int> seti;
/* -----구현부----- */
char arr[7][11],temp[7][11];
vector<char> per;
bool visit[30];
vii v;
bool check()
{
	if (arr[1][5] + arr[2][4] + arr[3][3] + arr[4][2] - 4 * 'A' != 22) return 0;
	if (arr[1][5] + arr[2][6] + arr[3][7] + arr[4][8] - 4 * 'A' != 22) return 0;
	if (arr[4][2] + arr[4][4] + arr[4][6] + arr[4][8] - 4 * 'A' != 22) return 0;
	if (arr[2][2] + arr[2][4] + arr[2][6] + arr[2][8] - 4 * 'A' != 22) return 0;
	if (arr[2][2] + arr[3][3] + arr[4][4] + arr[5][5] - 4 * 'A' != 22) return 0;
	if (arr[2][8] + arr[3][7] + arr[4][6] + arr[5][5] - 4 * 'A' != 22) return 0;
	return 1;
}
int main()
{
	SWS;
	FOR(i, 1, 5)
	{
		FOR(j, 1, 9)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'x')
				v.push_back({ i, j });
			else if (arr[i][j] != '.')
				visit[arr[i][j]-'A'] = 1;
		}
	}
	
	FOR(i, 'A', 'L') 
		if (!visit[i - 'A'])
			per.push_back(i);
	do
	{
		FOR(i, 0, v.size() - 1)
			arr[v[i].first][v[i].second] = per[i];
		if (check()) break;
	} while (next_permutation(per.begin(), per.end()));

	FOR(i, 1, 5)
	{
		FOR(j, 1, 9)
			cout << arr[i][j];
		cout << endl;
	}
	return 0;
}
