//https://www.acmicpc.net/problem/9012
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
void ans(string s)
{
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		if (s[i] == ')')
		{
			if (st.empty())
			{
				cout << "NO";
				return;
			}
			else
				st.pop();
		}
	}
	if (st.empty())
		cout << "YES";
	else
		cout << "NO";
}
int main()
{
	int a;
	cin >> a;
	while (a--)
	{
		string s;
		cin >> s;
		ans(s);
		cout << endl;
	}
	return 0;
}
