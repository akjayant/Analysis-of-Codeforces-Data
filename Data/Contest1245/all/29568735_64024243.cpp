#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e3 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n, x[N], y[N];
int c[N], k[N];
struct edge {
    int u, v;
    LL w;
    bool operator < (const edge& r) const { return w < r.w; }
} E[N*N];
int tot, p[N];
int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }
int pt[N];
vector<pii> V;
int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
    rep(i, 1, n) scanf("%d", &c[i]);
    rep(i, 1, n) scanf("%d", &k[i]);
    rep(i, 1, n) rep(j, i+1, n) {
        LL w = 1LL*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
        E[tot++] = {i, j, w};
    }
    rep(i, 1, n) E[tot++] = {0, i, 1LL*c[i]};
    sort(E, E+tot);
    rep(i, 0, n) p[i] = i;
    LL ans = 0;
    int aa = 0, bb = 0;
    rep(i, 0, tot-1) {
        int u = E[i].u, v = E[i].v;
        LL w = E[i].w;
        int fx = Find(u), fy = Find(v);
        if(fx != fy) {
            ans += w;
            p[fx] = fy;
            if(u == 0 || v == 0) pt[aa++] = (u ? u : v);
            else V.pb(mk(u, v));
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", aa);
    if(aa) {
        rep(i, 0, aa-1) printf("%d ", pt[i]);
        puts("");
    }
    printf("%d\n", V.size());
    for(auto i : V) printf("%d %d\n", i.fi, i.se);

    return 0;
}