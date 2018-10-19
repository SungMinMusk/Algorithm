/*
  문제 : https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu
  풀이 : 약물을 투여 할 위치의 조합 * 0과1중 어떤 약물을 투여 할것인가에 대한 조합을 전부따진다.
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
int n, m, k;
int arr[15][22];
int tmp[15][22];
void copy(int a[15][22], int b[15][22])
{
    FOR(i, 0, 14) FOR(j, 0, 21) b[i][j] = a[i][j];
}
bool check()
{
    if (k == 1) return true;
    FOR(j, 1, m)
    {
        int num = arr[1][j];
        int cnt = 1;
        bool f = 1;
        FOR(i, 2, n)
        {
            if (arr[i][j] == num)
                cnt++;
            else
            {
                num = arr[i][j];
                cnt = 1;
            }
            if (cnt == k)
            {
                f = 0;
                break;
            }
        }
        if (f) return false;
    }
    return true;
}
void YAK(int a, int y)
{
    FOR(i, 1, m) arr[a][i] = y;
}
bool game(const vi &per)
{
    vi d;
    FOR(i, 0, (int)per.size() - 1)
        if (per[i] == 1) d.push_back(i + 1);
    int size = d.size();
 
    FOR(i, 0, size)
    {
        vi p;
        FOR(j, 1, size - i) p.push_back(0);
        FOR(j, 1, i) p.push_back(1);
        do
        {
             
            FOR(j, 0, size - 1)
                YAK(d[j], p[j]);
 
            if (check()) return true;
        } while (next_permutation(p.begin(), p.end()));
    }
    return false;
}
int main()
{
    SWS;
    int t;
    cin >> t;
    FOR(z, 1, t)
    {
        memset(arr, 0, sizeof(arr));
        memset(tmp, 0, sizeof(tmp));
        cin >> n >> m >> k;
        FOR(i, 1, n) FOR(j, 1, m) cin >> arr[i][j];
        copy(arr, tmp);
        if (check())
        {
            cout << "#" << z << " " << 0 << endl;
            continue;
        }
 
        FOR(i, 1, n)
        {
            vi per;
            FOR(j, 1, n - i) per.push_back(0);
            FOR(j, 1, i) per.push_back(1);
            bool f = 1;
            do
            {
                copy(tmp, arr);
                if (game(per))
                {
                    cout << "#" << z << " " << i << endl;
                    f = 0;
                    break;
                }
            } while (next_permutation(per.begin(), per.end()));
            if (!f) break;
        }
    }
    return 0;
}
