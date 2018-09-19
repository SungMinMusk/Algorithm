#include<iostream>
#define MIN(x,y) (x)>(y) ? (y) : (x)
using namespace std;
int tmp[1000005] = { 0,};

int find(int N)
{	
	if (tmp[N] != 0)
		return tmp[N];
	else
	{
		if (N % 3 == 0 && N % 2 == 0) tmp[N] = MIN(MIN(find(N/3)+1,find(N/2)+1),find(N-1));
		else if (N % 3 == 0) tmp[N] = MIN(find(N/3)+1, find(N - 1)+1);
		else if (N % 2 == 0) tmp[N] = MIN(find(N/2)+1, find(N - 1)+1);
		else tmp[N] = find(N - 1)+1;
	}
	return tmp[N];
}
int main()
{	
	tmp[2] = 1;
	tmp[3] = 1;
	int N = 0;
	
	cin >> N;
	if (N == 1)
		cout << "0";
	else {
		for (int i = 4; i < N; i++)
			find(i);

		cout << find(N);
	}
	return 0;
}
