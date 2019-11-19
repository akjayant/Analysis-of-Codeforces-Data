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
const int maxn = 2e3 + 15;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
/*************************************************************************/


struct DSU
{
    int fa[maxn];
    void init(int n)
    {
        for (int i=0;i<=n;i++)
        {
            fa[i] = i;
        }
    }
    int find(int x)
    {
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    int uni(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x==y)return 0;
        if(x<y)swap(x,y);
        fa[x]=y;
        return 1;
    }
}dsu;

 
ll dist(ll x1,ll y1,ll x2, ll y2){
  return (abs(x1 - x2) + abs(y1 - y2));
}

std::vector<pair<ll, pair<int,int>>> v;
ll cx[maxn], cy[maxn], cc[maxn], ck[maxn];

void solve() {
    int n;
    SA(n);
    REPP(i,1,n) {
        SLLA(cx[i]);
        SLLA(cy[i]);
    }
    REPP(i,1,n) {
        SLLA(cc[i]);
    }
    REPP(i,1,n) {
        SLLA(ck[i]);
    }
    REPP(i,1,n) {
        REPP(j,i+1,n) {
            v.push_back(MP(dist(cx[i], cy[i], cx[j], cy[j]) * (ck[i] + ck[j]), MP(i,j)));
        }
    }
    REPP(i,1,n) {
        v.push_back(MP(cc[i], MP(0,i)));
    }
    dsu.init(2005);
    sort(v.begin(), v.end());
    ll ans = 0;
    std::vector<int> v1;
    std::vector<pair<int,int>> v2;
    REP(i,0,v.size()) {
        int wx = v[i].second.first;
        int wy = v[i].second.second;
        if(dsu.find(wx) == dsu.find(wy)) {
            continue;
        }
        if(wx == 0) {
            v1.push_back(wy);
        } else {
            v2.push_back(MP(wx, wy));
        }
        dsu.uni(wx, wy);
        ans += v[i].first;
    }
    printf("%lld\n", ans);
    printf("%d\n", (int)v1.size());
    REP(i,0,v1.size()) {
        printf("%d ", v1[i]);
    }
    printf("\n%d\n",(int)v2.size() );
    REP(i,0,v2.size()) {
        printf("%d %d\n", v2[i].first, v2[i].second);
    }
}


int main()
{   
   // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int t;
    t = 1;
    REPP(i,1,t) {
        solve();
    }
    return 0;
 
}
 