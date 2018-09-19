// https://www.acmicpc.net/problem/14889
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int arr[21][21];
vector <int> res;
int n;

void ans(int start, int cnt, int prev, vector<int> v)
{
	if (prev != 0) v.push_back(prev); //선택한 것을 벡터에 삽입
	if (cnt == n / 2)
	{
		int sum1 = 0, sum2 = 0;
		bool visit[21] = { 0, };
		
		for (int i = 0; i < v.size(); i++)  //방문한곳 체크
			visit[v[i]] = true;
		
		for (int i = 1; i <= n; i++)    //team1 
			for (int j = 1; j <= n; j++)
				if (visit[i] == true && visit[j] == true)
					sum1 += (arr[i][j]);
	
		for (int i = 1; i <= n; i++) 	//team2
			for (int j = 1; j <= n; j++)
				if (visit[i] == false && visit[j] == false)
					sum2 += (arr[i][j]);
	
		if (sum1 - sum2 > 0) 	//team1-team2를 res벡터에 삽입
			res.push_back(sum1 - sum2);
		else
			res.push_back(sum2 - sum1);
		return; //종료
	}
	for (int i = start; i <= n; i++)
	{
		ans(i + 1, cnt + 1, i, v); //i가 선택되고 i+1을 선택하러감
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	ans(1, 0, 0, {});
	sort(res.begin(), res.end()); //정렬하여 최솟값 출력 
	cout << res[0];
	return 0;
}
