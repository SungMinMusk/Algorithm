/*
	문제: https://www.acmicpc.net/problem/14490 
	최대공약수를 구하고 나눔 
*/
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	int r = a%b;
	a=b;
	b=r;
	gcd(a,b); 
}

int main()
{
	int n,m;
	scanf("%d:%d",&n,&m);
	//최대 공약수 
	int tmp = gcd(n,m);
	//결과 
	printf("%d:%d",n/tmp,m/tmp);
	return 0;
}
