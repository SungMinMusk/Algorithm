/*
	문제 :  www.acmicpc.net/problem/11966
	for문으로 2의 제곱수를 반복하며 입력값과  같은지 확인 ! 
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long num;
	long long tmp=1;
	cin>>num;
	for(int i=1;i<=31;i++)
	{
		if(tmp == num)
		{
			cout<<1;
			return 0;
		}
		tmp*=2;
	}
	cout<<0;
	return 0;
}
