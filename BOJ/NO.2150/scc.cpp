/*
	문제 : https://www.acmicpc.net/problem/2150
	풀이 : 타잔 알고리즘을 이용한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
typedef stack<int> sti;
typedef queue<int> qi;
typedef vector<int> vi;
typedef vector<pair<int, int > >vii;


const int MAX = 10001;
int id, par[MAX];
bool finished[MAX];
vi v[MAX];
vector<vi> scc;
sti st;

int dfs(int x)
{
	par[x] = ++id;
	st.push(x);

	int parent = par[x];
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		// 방문 하지 않은 이웃
		if (par[next] == 0) parent = min(parent, dfs(next));
		// 처리 중인 이웃
		else if (!finished[next]) parent = min(parent, par[next]);
	}
	if (parent == par[x])
	{
		vector<int> s;
		while (1)
		{
			int t = st.top();
			st.pop();
			s.push_back(t);
			finished[t] = true;
			if (t == x)
				break;
		}
		scc.push_back(s);
	}
	return parent;
}
int main()
{
	SWS;
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <=V; i++)
		if(par[i]==0) dfs(i);

	//scc의 갯수 출력
	cout << scc.size() << endl;

	//scc 정렬
	for (int i = 0; i < scc.size(); i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end());

	//scc 목록 출력
	for (int i = 0; i < scc.size(); i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << " ";
		cout << "-1" << '\n';
	}
	return 0;
}
