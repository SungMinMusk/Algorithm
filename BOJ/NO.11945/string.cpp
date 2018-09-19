/*
	문제 :  www.acmicpc.net/problem/11945
	문자열 배열 생성 후 입력 받아 반대부터 출력 
*/
#include<iostream>
#include<string>
using namespace std;
string arr[12];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
			cout<<arr[i][j];
		cout<<endl;
	}
	return 0;
}
