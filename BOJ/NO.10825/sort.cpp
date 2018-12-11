/*
  문제 : https://www.acmicpc.net/problem/10825
  풀이 : 조건에 맞게 compare함수를 재정의
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
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
typedef struct stu
{
	int k, e, m;
	string name;
}stu;
bool comp(stu a,stu b)
{
	if (a.k == b.k && a.e==b.e && a.m == b.m)
		return a.name < b.name;
	else if (a.k == b.k && a.e == b.e)
		return a.m > b.m;
	else if (a.k == b.k)
		return a.e < b.e;
	else
		return a.k > b.k;
}
int main()
{
	SWS;
	int n;
	cin >> n;

	vector<stu> v;
	while (n--)
	{
		stu a;
		cin >> a.name >> a.k >> a.e >> a.m;
		v.push_back(a);
	}
	sort(v.begin(), v.end(),comp);
	for (auto &i : v)
		cout << i.name << endl;
	return 0;
}
