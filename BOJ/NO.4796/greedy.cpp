//https://www.acmicpc.net/problem/4796
#include<iostream>
using namespace std;
int a, b, c;
int res = 0;
int ans()
{
	int res = 0;
	res += (c / b)*a;
	if (c%b > a)
		res += a;
	else
		res += c % b;
	return res;
}
int main()
{
	int cs = 0;
	while (1)
	{
		cs++;
		cin >> a >> b >> c;
		if (a != 0 && b != 0 && c != 0)
			cout << "Case " << cs << ": " << ans()<<endl;
		else
			break;
	} 
	return 0;
}
