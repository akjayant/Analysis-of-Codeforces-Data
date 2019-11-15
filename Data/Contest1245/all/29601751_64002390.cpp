#include <fstream>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <random>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define EPS 1e-8
#define LL_INF 0x3fffffffffffffff
#define INF 0x3f3f3f3f3f3f3f3f
#define MEM(a, b) memset(a, b, sizeof(a))
#define PPER(i, n, m) for (int i = n; i >= m; i--)
#define REPP(i, n, m) for (int i = n; i <= m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define PER(i, n, m) for (int i = n; i > m; i--)
#define SA(n) scanf("%d", &(n))
#define SLLA(n) scanf("%lld", &(n))
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define DE(val) cout << #val << ": " << val << endl;
 
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 1, 0,-1};
const int dy4[6] = {1, 0, -1,0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
void update(ll& x,ll v){
    if(x==-1)x=v;
    else if(x>v)x=v;
}
 
ll po(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll inverse(ll a, ll n)
{
    ll d, x, y;
    extgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const int maxn = 1e5 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/


char val[maxn]; 
void solve() {
    int n;
    SA(n);
    int R,P,S;
    SA(R);SA(P);SA(S);
    scanf("%s" , val + 1);

    int cR = 0;
    int cP = 0;
    int cS = 0;
    REPP(i,1,n) {
        if(val[i] == 'R') cR++;
        if(val[i] == 'P') cP++;
        if(val[i] == 'S') cS++;
    }
// R -> S
// P -> R
// S -> P
    int ans = min(cR, P);
    ans += min(cP, S);
    ans += min(cS, R);
    if(ans >= (n + 1)/2) {
        puts("YES");
        string cur;
        REPP(i,1,n) {
            if(val[i] == 'R') {
                if(P > 0) {
                    P--;
                    cur.push_back('P');
                } else {
                    cur.push_back(' ');
                }
            }
            if(val[i] == 'S') {
                if(R > 0) {
                    R--;
                    cur.push_back('R');
                } else {
                    cur.push_back(' ');
                }
            }
            if(val[i] == 'P') {
                if(S > 0) {
                    S--;
                    cur.push_back('S');
                } else {
                    cur.push_back(' ');
                }
            }
        }
        REP(i,0,n) {
            if(cur[i] == ' ') {
                if(P > 0) {
                    P--;
                    cur[i] = 'P';
                } else if(R > 0) {
                    R--;
                    cur[i] = 'R';
                } else {
                    S--;
                    cur[i] = 'S';
                }
            }
        }
        cout<<cur<<endl;
    } else {
        puts("NO");
    }
}

int main()
{   
    //freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int t;
    SA(t);
    REPP(i,1,t) {
        solve();
    }
    return 0;
 
}
 