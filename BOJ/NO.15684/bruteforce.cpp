/*
  문제 : https://www.acmicpc.net/problem/15684
  풀이 : 사다리를 놓을 수 있는 위치를 완전 탐색한다.
*/

#include<iostream>
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
int arr[12][32],n, m, h, a, b, maxv, sadari[32][12][12];
bool game(){
	FOR(i, 1, n){
		int s = i;
		int f;
		FOR(j, 1, h + 1){
			if (sadari[j][s-1][s]) s = s - 1;
			else if (sadari[j][s][s + 1]) s = s + 1;
			if (j == h + 1) f=arr[s][j];
		}
		if (i != f) return false;
	}
	return true;
}
void dfs(int cnt,int r){
	if (cnt == maxv){
		if (game())	{
			cout << cnt;
			exit(0);
		}
		else return;
	}
	FOR(i, r, h){
		FOR(j, 2, n){
			if (!sadari[i][j - 2][j - 1] && !sadari[i][j-1][j])	{
				sadari[i][j - 1][j] = 1;
				dfs(cnt + 1,i);
				sadari[i][j - 1][j] = 0;
			}	
		}	
	}
}
int main(){
	cin >> n >> m >> h;
	FOR(i, 1, n) arr[i][h + 1] = i;
	FOR(i, 1, m){
		cin >> a >> b;
		sadari[a][b][b + 1] = true;
	}
	FOR(i, 0, 3){
		maxv = i;
		dfs(0,1);
	}
	cout << -1;
	return 0;
}
