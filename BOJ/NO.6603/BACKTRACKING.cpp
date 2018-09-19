// https://www.acmicpc.net/problem/6603
#include<iostream>
#include<string>
using namespace std;
int arr[15];
int k;

void back_tracking(int pos, int cnt ,string str)
{
	if (cnt == 6)
	{
		cout << str << endl;
		return;
	}
	
	for (int i = pos; i <= k; i++)
	{
		back_tracking(i + 1, cnt + 1, str + to_string(arr[i]) + ' ');
	}
}
int main()
{
	int tmp;
	while (1)
	{
		cin >> k;
		if (!k) break;
		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
		}
		back_tracking(1,0,"");
		cout << endl;
	}
	return 0;
}
