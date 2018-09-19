/*
	문제 : https://www.acmicpc.net/problem/9536
	풀이 : 각 동물의 울음소리를 set에 넣고 녹음 소리에서 set에 없는 소리만 출력
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

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		string arr[300];
		set<string> st;

		//녹음된 소리 입력
		int idx = 0;
		while (1)
		{
			char k;
			cin >> arr[idx++];
			k = getchar();
			if (k == '\n') break;
		}
		//각 동물 소리 입력
		while (1)
		{
			string a, b, c;
			cin >> a >> b >> c;
			if (b == "does") break;
			st.insert(c);
		}
		//여우 소리만 출력
		FOR(i, 0, idx - 1)
			if (st.find(arr[i]) == st.end()) cout << arr[i] << " ";
		cout << endl;

		//남은 입력값 제거
		string buffer;
		getline(cin, buffer);
	}

	return 0;
}
