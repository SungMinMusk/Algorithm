// https://www.acmicpc.net/problem/2504
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool wrong(string s)
{
	stack<char> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		if (s[i] == '[')
			st.push(s[i]);
		if (s[i] == ')')
		{
			if (st.empty() || st.top() =='[')
				return 0;
			else
				st.pop();
		}
		if (s[i] == ']')
		{
			if (st.empty() || st.top() == '(')
				return 0;
			else
				st.pop();
		}
	}
	if (st.empty())
		return 1;
	else
		return 0;
}

void ans(string s)
{
	if (!wrong(s))
	{
		cout << 0;
		return;
	}

	int res = 0;
	stack<int> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
		{
			st.push(s[i]);
		}
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}

		else if (s[i] == ']')
		{
			int tmp = 0;
			while (st.top() != '[')
			{
				tmp += st.top();
				st.pop();
			}
			st.pop();
			if (tmp == 0)
				st.push(3);
			else
				st.push(tmp * 3);
			if (st.size() == 1)
			{
				res += st.top();
				st.pop();
			}

		}

		else if (s[i] == ')')
		{
			int tmp = 0;
			while (st.top() != '(')
			{
				tmp += st.top();
				st.pop();
			}
			st.pop();

			if (tmp == 0)
				st.push(2);
			else
				st.push(tmp * 2);

			if (st.size() == 1)
			{
				res += st.top();
				st.pop();
			}
		}
	}

	cout << res << endl;
}
int main()
{
	string s;
	cin >> s;
	ans(s);

	return 0;
}
