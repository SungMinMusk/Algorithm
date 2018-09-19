// https://www.acmicpc.net/problem/14888
#include<iostream>
#include<vector>
using namespace std;

int arr[101];
int n;
long long MIN=1000000000;
long long MAX=-1000000000;
vector<int>op; // + - * /

void ans(int cnt, long long sum, vector<int> v)
{
	if (cnt == n)
	{
		if (sum < MIN) MIN = sum;
		if (sum > MAX) MAX = sum;
		return;
	}

	long long tmp_sum = sum;
	int tmp_v;
	for (int i = 1; i < v.size();i++)
	{
		tmp_v = v[i];
		if (tmp_v == -1) continue;
		if (tmp_v == 0) sum += arr[cnt];
		else if (tmp_v == 1) sum -= arr[cnt];
		else if (tmp_v ==2) sum *= arr[cnt];
		else if(tmp_v ==3) sum /= arr[cnt];
		v[i] = -1;
		//다음 호출
		ans(cnt + 1, sum, v);
		//원상 복귀
		v[i] = tmp_v;
		sum = tmp_sum;
	}
}
int main()
{ //인덱스 맞추는 용
	op.push_back(-1);
  //입력데이터 입력
	cin >> n; 	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
	{
		int cnt;
		cin >> cnt;
		while (cnt--) op.push_back(i);
	}
  // 함수 호출
	ans(1,arr[0],op);
  // 정답 출력
	cout << MAX << '\n';
	cout << MIN ;
	return 0;
}
