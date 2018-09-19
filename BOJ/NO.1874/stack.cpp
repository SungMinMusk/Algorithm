// https://www.acmicpc.net/problem/1874
#include<iostream>
#include<stack>
#include<vector>

using namespace std;
bool flag = 0;
int n = 0;
int arr[100001];
vector<char> v;
void ans()
{
	stack<int> st;
	int tmp[100001];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = i + 1;
	}
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (st.empty() && j<n)
		{
			st.push(tmp[j++]);
			v.push_back('+');
		}
		while (st.top() != arr[i] && j<n)
		{
			st.push(tmp[j++]);
			v.push_back('+');
		}
		if (st.top() == arr[i])
		{
			st.pop();
			v.push_back('-');
		}
	}
	if (!st.empty())
	{
		cout << "NO";
		flag = 1;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ans();
	if (flag == 0)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << '\n';
	}
	return 0;
}
