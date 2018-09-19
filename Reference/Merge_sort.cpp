#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector>
using namespace std;
int a[10000];

void merge(int arr[], int ls, int le, int rs, int re)
{
	int p = ls; int q = rs;
	int tmp[10000];
	int i = 0;
	while (p <= le && q <= re)
	{
		if (arr[p] >= arr[q])
		{
			tmp[i++] = arr[q];
			q++;
		}
		else
		{
			tmp[i++] = arr[p];
			p++;
		}
	}
	if (p > le)
	{
		for (int j = q; j <= re; j++)
			tmp[i++] = arr[j];
	}
	else
	{
		for (int j = p; j <= le; j++)
			tmp[i++] = arr[j];
	}

	for (int j = ls; j <= re; j++)
		arr[j] = tmp[j-ls];
}
void merge_sort(int arr[], int s, int e)
{
	if (s >= e) return;

	int mid = (s + e) / 2;
	merge_sort(arr, s, mid); 
	merge_sort(arr, mid + 1, e);
	merge(arr, s, mid, mid + 1, e);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	merge_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << '\n';
	
	return 0;
}
