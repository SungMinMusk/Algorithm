/*
  문제 : https://www.acmicpc.net/problem/12886
  풀이 : 완전탐색을 한다. 중복 탐색을 하지 않기 위해 스트링으로 만들어 map에 기록한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<string.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
map<string, bool>visit;
string tostr(int a, int b, int c)
{
	int arr[3] = { a,b,c };
	sort(arr, arr + 3);
	return to_string(arr[0]) + to_string(arr[1]) + to_string(arr[2]);
}
void ans(int a, int b, int c)
{
	visit[tostr(a, b, c)] = 1;
	string tmp;
	if (a == b && b == c)
	{
		cout << 1;
		exit(0);
	}
	if (a > b)
	{
		tmp = tostr(a - b, b + b, c);
		if (!visit[tmp])
			ans(a - b, b + b, c);
	}
	if (b > a)
	{
		tmp = tostr(a + a, b - a, c);
		if (!visit[tmp])
			ans(a + a, b - a, c);
	}
	if (b > c)
	{
		tmp = tostr(a, b - c, c + c);
		if (!visit[tmp])
			ans(a, b - c, c + c);
	}
	if (c > b)
	{
		tmp = tostr(a, b + b, c - b);
		if (!visit[tmp])
			ans(a, b + b, c - b);
	}
	if (a > c)
	{
		tmp = tostr(a - c, b, c + c);
		if (!visit[tmp])
			ans(a - c, b, c + c);	
	}
	if (c > a)
	{
		tmp = tostr(a + a, b, c - a);
		if (!visit[tmp])
			ans(a + a, b, c - a);
	}
}
int main()
{
	SWS;
	int a, b, c;
	cin >> a >> b >> c;
	ans(a, b, c);
	cout << 0;
	return 0;
}
