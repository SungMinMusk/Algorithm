// https://www.acmicpc.net/problem/11004
#include<iostream>
using namespace std;
int arr2[5000001];

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	int j = r;
	while(1)
	{
		do i++; while (arr[i] < pivot);
		do j--; while (arr[j] > pivot);
		if (i >= j) break;
		int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
	}
	int temp = arr[i]; arr[i] = arr[r]; arr[r] = temp;
	return i;
}

void qsort(int arr[], int l, int r)
{
	if (r > l)
	{
		int i = partition(arr, l, r); // i는 이미 정렬된 녀석
		qsort(arr, l, i - 1);
		qsort(arr, i + 1, r);
	}
}

int qsch(int arr[], int l, int r,int k)
{
	int i = partition(arr, l, r); // i는 이미 정렬된 녀석
	if (i == k) return arr[k];
	else if(i>k)
		qsch(arr, l, i - 1,k);
	else 
		qsch(arr, i + 1, r,k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr2[i];
	cout << qsch(arr2, 0, n - 1, m - 1);
	return 0;
}
