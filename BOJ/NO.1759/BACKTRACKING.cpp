//https://www.acmicpc.net/problem/1759
//백트래킹 이용 해결
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char arr[16];
int l, c;
void back_tracking(int pos, int son,int mom, string str)
{
	if (son+mom == l)
	{
		if (son < 2 || mom < 1)
			return;

		cout << str << '\n';
		return;
	}
	for (int i = pos; i < c; i++)
	{
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			back_tracking(i+1, son, mom+1, str + arr[i]);
		else 
			back_tracking(i+1, son+1, mom, str + arr[i]);
	}
}

int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + c);
	back_tracking(0,0,0,"");
	return 0;
}
