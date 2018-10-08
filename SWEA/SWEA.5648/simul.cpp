/*
  문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo&categoryId=AWXRFInKex8DFAUo&categoryType=CODE
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<float.h>
#define SWS ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define endl '\n'
#define FOR(a,b,c) for(int a=b;a<=c;++a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef stack<int> sti;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef stack<pair<int, int> > stii;
typedef queue<pair<int, int> > qii;
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
typedef struct point
{
    int x, y, d, k;
}point;
int n;
int arr[4005][4005];
point atom[1001];
int check[1001];
int res = 0;
void ans()
{
    for (int i = 1; i <= n; i++)
    {
        if (!check[i]) continue;
        int x = atom[i].x;
        int y = atom[i].y;
 
        if (atom[i].d == 0)
        {
            if (y + 1 > 4001)
            {
                check[i] = 0;
                arr[x][y] = 0;
            }
            else
            {
                arr[x][y]--;
                arr[x][y + 1]++;
                atom[i].y = y + 1;
            }
        }
        else if (atom[i].d == 1)
        {
            if (y - 1 < 0)
            {
                check[i] = 0;
                arr[x][y] = 0;
            }
            else
            {
                arr[x][y]--;
                arr[x][y - 1]++;
                atom[i].y = y - 1;
            }
        }
        else if (atom[i].d == 2)
        {
            if (x - 1 < 0)
            {
                check[i] = 0;
                arr[x][y] = 0;
            }
            else
            {
                arr[x][y]--;
                arr[x - 1][y]++;
                atom[i].x = x - 1;
            }
        }
        else if (atom[i].d == 3)
        {
            if (x + 1 > 4001)
            {
                check[i] = 0;
                arr[x][y] = 0;
            }
            else
            {
                arr[x][y]--;
                arr[x + 1][y]++;
                atom[i].x = x + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = atom[i].x;
        int y = atom[i].y;
        if (arr[x][y] >= 2)
        {
            FOR(i, 1, n)
            {
                if (check[i] && atom[i].x == x && atom[i].y == y)
                {
                    res += atom[i].k;
                    check[i] = 0;
                }
            }
            arr[x][y] = 0;
        }
    }
}
int main()
{
    SWS;
    int t;
    cin >> t;
    FOR(z, 1, t)
    {
        //초기화
        res = 0;
        memset(atom, 0, sizeof(atom));
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        cin >> n;
        FOR(i, 1, n)
        {
            int x, y, d, k;
            cin >> x >> y >> d >> k;
 
            arr[2 * (x + 1000)][2 * (y + 1000)] = 1;
            atom[i] = { 2 * (x + 1000),2 * (y + 1000), d,k };
            check[i] = 1;
        }
        FOR(i,1,4500)
            ans();
        cout << "#" << z << " " << res << endl;
    }
    return 0;
}
