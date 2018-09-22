/*
	문제 : https://www.acmicpc.net/problem/9573
	풀이 : 완전 탐색을 통하여 자물쇠를 열 수 있는 모든 경우를 찾는다.
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
int N, master[3], jon[3];
int dn[5] = { -2,-1,0,1,2 };
vi v;
int main()
{
	//입력값
	cin >> N;
	cin >> jon[0] >> jon[1] >> jon[2];
	cin >> master[0] >> master[1] >> master[2];


	FOR(i, 1, N - 3) v.push_back(0);
	FOR(i, 1, 3) v.push_back(1);

	int res = 0;
	FOR(x, 1, N)
	{
		FOR(y, 1, N)
		{
			FOR(z, 1, N)
			{
				vi a;
				a.push_back(x);
				a.push_back(y);
				a.push_back(z);

				int f = 1;
				FOR(i, 0, 2)
				{
					FOR(j, 0, 4)
					{
						int vs = jon[i] + dn[j];
						if (vs > N) vs -= N;
						else if (vs <= 0) vs += N;
						if (vs == a[i])
						{
							f <<= (i + 1);
							break;
						}
					}
				}
				if (f == 64)
				{
					res++;
					continue;
				}

				f = 1;
				FOR(i, 0, 2)
				{
					FOR(j, 0, 4)
					{
						int vs = master[i] + dn[j];
						if (vs > N) vs -= N;
						else if (vs <= 0) vs += N;

						if (vs == a[i])
						{
							f <<= (i + 1);
							break;
						}
					}
				}
				if (f == 64)
					res++;
			}
		}

	}
	cout << res;
	return 0;
}
