/*
  문제 : https://www.acmicpc.net/problem/15778
  풀이 : 어려운 구현문제, 규칙을 잘 읽고 구현한다. 말이 놓일수 있는 공강을 맵핑하는게 중요
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int> > pqii;
typedef pair<int, int > pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int > >vii;
typedef set<int> seti;
const int INF = 0x7fffffff;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dz[2] = { -1, 1 };
/* -----구현부----- */
string arr[33] =
{
	"..----..----..----..----..----..",
	"..    ..    ..    ..    ..    ..",
	"| \\                          / |",
	"|  \\                        /  |",
	"|   \\                      /   |",
	"|    ..                  ..    |",
	"..   ..                  ..   ..",
	"..     \\                /     ..",
	"|       \\              /       |",
	"|        \\            /        |",
	"|         ..        ..         |",
	"|         ..        ..         |",
	"..          \\      /          ..",
	"..           \\    /           ..",
	"|             \\  /             |",
	"|              ..              |",
	"|              ..              |",
	"|             /  \\             |",
	"..           /    \\           ..",
	"..          /      \\          ..",
	"|         ..        ..         |",
	"|         ..        ..         |",
	"|        /            \\        |",
	"|       /              \\       |",
	"..     /                \\     ..",
	"..   ..                  ..   ..",
	"|    ..                  ..    |",
	"|   /                      \\   |",
	"|  /                        \\  |",
	"| /                          \\ |",
	"..    ..    ..    ..    ..    ..",
	"..----..----..----..----..----..",
	"end"
};
int n;
vii pos[31];
pii nxt[31];
int horse[8];
void init()
{
	int idx = 1;
	bool visit[32][32];
	memset(visit, 0, sizeof(visit));
	FOR(i, 0, 31)
	{
		FOR(j, 0, 31)
		{
			if (arr[i][j] == '.' && !visit[i][j])
			{
				pos[idx].push_back({ i,j });
				pos[idx].push_back({ i,j + 1 });
				pos[idx].push_back({ i + 1,j });
				pos[idx].push_back({ i + 1,j + 1 });
				visit[i][j] = 1;
				visit[i][j + 1] = 1;
				visit[i + 1][j] = 1;
				visit[i + 1][j + 1] = 1;
				idx++;
			}
		}
	}
	pos[0].push_back({ 32,0 });
	pos[0].push_back({ 32,0 });
	pos[0].push_back({ 32,0 });
	pos[0].push_back({ 32,0 });
	pos[30].push_back({ 32,0 });
	pos[30].push_back({ 32,0 });
	pos[30].push_back({ 32,0 });
	pos[30].push_back({ 32,0 });

	nxt[0] = { 21,21 };
	nxt[1] = { 7,9 };
	nxt[2] = { 1,1 };
	nxt[3] = { 2,2 };
	nxt[4] = { 3,3 };
	nxt[5] = { 4,4 };
	nxt[6] = { 8,5 };
	nxt[7] = { 11,11 };
	nxt[8] = { 12,12 };
	nxt[9] = { 13,13 };
	nxt[10] = { 6,6 };
	nxt[11] = { 15,15 };
	nxt[12] = { 15,15 };
	nxt[13] = { 16,16 };
	nxt[14] = { 10,10 };
	nxt[15] = { 19,18 };
	nxt[16] = { 20,20 };
	nxt[17] = { 14,14 };
	nxt[18] = { 22,22 };
	nxt[19] = { 23,23 };
	nxt[20] = { 24,24 };
	nxt[21] = { 17,17 };
	nxt[22] = { 24,24 };
	nxt[23] = { 29,29 };
	nxt[24] = { 25,25 };
	nxt[25] = { 26,26 };
	nxt[26] = { 27,27 };
	nxt[27] = { 28,28 };
	nxt[28] = { 29,29 };
	nxt[29] = { 30,30 };
	nxt[30] = { 30,30 };
	FOR(i, 0, 7)
		horse[i] = 0;
}
int yut_how_much(string s)
{
	int res = 0;
	FOR(i, 0, 4)
		if (s[i] == 'F')
			res++;
	if (res == 0) return 5;
	else return res;
}
void next(char m,int t)
{
	int mal;
	if (m >= 'A'&&m <= 'D')
		mal = m - 'A';
	else
		mal = m - 'a' + 4;
	vi v;

	//말을 업어보자
	if (horse[mal] != 0)
	{
		if (mal >= 0 && mal <= 3)
		{
			FOR(i, 0, 3)
				if (horse[i] == horse[mal]) v.push_back(i);
		}
		else if (mal >= 4 && mal <= 7)
		{
			FOR(i, 4, 7)
				if (horse[i] == horse[mal]) v.push_back(i);
		}
	}
	else v.push_back(mal);

	// 나아가자
	bool fast;
	if (horse[mal] == 6)
	{
		FOR(i, 0, v.size() - 1)
			horse[v[i]] = nxt[horse[v[i]]].first;
		t--;
		fast = 0;
	}
	else if (horse[mal] == 1 || horse[mal] == 15 || horse[mal] == 7 || horse[mal] == 11) fast = 1;
	else fast = 0;

	FOR(i, 1, t)
	{
		if (fast)
		{
			FOR(i, 0, v.size() - 1)
				horse[v[i]] = nxt[horse[v[i]]].first;
		}
		else
		{
			FOR(i, 0, v.size() - 1)
				horse[v[i]] = nxt[horse[v[i]]].second;
		}
	}
	
	// 적을 잡으면!
	if (mal >= 0 && mal <= 3)
	{
		FOR(i, 4, 7)
			if (horse[i] == horse[mal]) horse[i] = 0;
	}
	else if (mal >= 4 && mal <= 7)
	{
		FOR(i, 0, 3)
			if (horse[i] == horse[mal]) horse[i] = 0;
	}

}
int main()
{
	init();
	cin >> n;
	FOR(i, 1, n)
	{
		char mal; int go; string yut;
		cin >> mal >> yut;
		go = yut_how_much(yut);
		next(mal, go);
	}
	arr[pos[horse[0]][0].first][pos[horse[0]][0].second] = 'A';
	arr[pos[horse[1]][1].first][pos[horse[1]][1].second] = 'B';
	arr[pos[horse[2]][2].first][pos[horse[2]][2].second] = 'C';
	arr[pos[horse[3]][3].first][pos[horse[3]][3].second] = 'D';
	arr[pos[horse[4]][0].first][pos[horse[4]][0].second] = 'a';
	arr[pos[horse[5]][1].first][pos[horse[5]][1].second] = 'b';
	arr[pos[horse[6]][2].first][pos[horse[6]][2].second] = 'c';
	arr[pos[horse[7]][3].first][pos[horse[7]][3].second] = 'd';
	FOR(i, 0, 31)
		cout << arr[i] << endl;

	return 0;
}
