/*
  문제 : http://codeforces.com/contest/1029/problem/A
  풀이 : 같은 문자열 두개를 앞부터 밀어가면서 비교하며, 시작부터 끝까지 일치하는 다음 부분부터 반복 출력한다.
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
typedef vector<pair<int, int > >vpii;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[51];

int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	string tmp;
	cin >> s;
	tmp = s;
	cout << s;
	int idx=0;
	for (int i = 1; i < s.length(); i++)
	{
		int k = 0; 
		bool f = 1;
		for (int j = i; j < s.length(); j++)
		{
			if (s[j] != tmp[k++])
			{
				f = 0;
				break;
			}
		}
		if (f == 1)
		{
			idx = k;
			break;
		}
	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = idx; j < s.length(); j++)
			cout << s[j];
	}
	

	return 0;
}
