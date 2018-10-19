/*
  문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl
  풀이 : 출구가 2개므로 각 사람마다 출구를 배정하는 모든 조합에 대해 완전탐색한다.
    계단에서 대기하는 인원의 큐를 준비해서 큐에서 사람을 빼고, 종료 조건 확인하고, 사람을 넣고를 반복한다.
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
int arr[12][12],n,res;
vii man, ex;
int diff(pii a, pii b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
	/*---- 제거 하고 제출 ----*/
	freopen("tc.txt", "r", stdin);
	/*----------------------*/
	SWS;
	int t;
	cin >> t;
	FOR(z, 1, t)
	{
		//초기화
		memset(arr, 0, sizeof(arr));
		man.clear();
		ex.clear();
		res = INF;
		//입력
		cin >> n;
		FOR(i, 1, n)
		{
			FOR(j, 1, n)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
					man.push_back({ i,j });
				else if (arr[i][j] > 1)
					ex.push_back({ i,j });
			}
		}

		int size = (int)man.size();
		
		FOR(i, 0, size)
		{
			vi per;
			FOR(j, 1, size-i) per.push_back(0);
			FOR(j, 1, i) per.push_back(1);
			do
			{
				pqi ex0, ex1;
				FOR(j, 0, size - 1)
				{
					if (per[j] == 0)
						ex0.push(-diff(man[j], ex[0]));
					else
						ex1.push(-diff(man[j], ex[1]));
				}

				qi q0, q1;
				int time = 0, comp = 0;
				while (1)
				{
					time++;
					if (time >= res) break;
					
					//계단 나가기
					while (!q0.empty())
					{
						if (q0.front() + arr[ex[0].first][ex[0].second] == time)
						{
							q0.pop();
							comp++;
						}
						else break;
					}
					while (!q1.empty())
					{
						if (q1.front() + arr[ex[1].first][ex[1].second] == time)
						{
							q1.pop();
							comp++;
						}
						else break;
					}
					//종료
					if (comp == size) break;

					//계단 들어가기
					while (!ex0.empty() && -ex0.top() <= time-1)
					{
						if ((int)q0.size() < 3)
						{
							q0.push(time);;
							ex0.pop();
						}
						else break;
					}
					while (!ex1.empty() && -ex1.top() <= time -1)
					{
						if ((int)q1.size() < 3)
						{
							q1.push(time);
							ex1.pop();
						}
						else break;
					}
				}
				res = min(time, res);
			} while (next_permutation(per.begin(), per.end()));
		}
		cout << "#" << z << " " << res << endl;
	}
	return 0;
}
