#include <bits/stdc++.h>

#define lo(i, n, m) for (int i = n; i < m; i++)
#define loe(i, n, m) for (int i = n; i <= m; i++)
#define rlo(i, n, m) for (int i = n - 1; i >= m; i--)
#define rloe(i, n, m) for (int i = n; i >= m; i--)
#define pb push_back
#define mk make_pair
#define scd(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define sclf(x) scanf("%lf", &x)
#define scll(x) scanf("%lld", &x)
#define clr(a, b) memset((a), (b), sizeof(a))
typedef long long LL;
using namespace std;
// const int INF = 0x3f3f3f3f;
// const int INF = 0x7fffffff;
// const LL INF = 0x3f3f3f3f3f3f3f3f;
// const LL INF = 0x7fffffffffffffff;
const int NIL = -1;
template <class T>
inline T mx(T a, T b) {return a > b ? a : b;}
template <class T>
inline T mi(T a, T b) {return a < b ? a : b;}
template <class T>
inline void sw(T &a, T &b) {
    T t = a; a = b; b = t;
}
template <class T>
inline T mabs(T x) {return x < 0 ? -x : x;}
inline char gc() {
    char ret;
    while ((ret = getchar()) == ' ' || ret == '\n' || ret == '\t');
    return ret;
}
template <class T>
inline T sq(T x) {return x * x;}

const int lim = 2e3 + 10;
LL adj[lim][lim];
int x[lim], y[lim];
LL cc[lim], kk[lim];
struct Node {
    int a, b;
    LL cst;
    Node (int na = 0, int nb = 0, LL nc = 0ll) : a(na), b(nb), cst(nc) {}
    bool operator < (const Node &n) const {
        return cst < n.cst;
    }
};
vector<Node> dat;
bool vis[lim];
int fa[lim];
int Find(int x) {
    if (x != fa[x]) return fa[x] = Find(fa[x]);
    return x;
}
inline bool Union(int x, int y) {
    int nx = Find(x), ny = Find(y);
    if (nx != ny && (!vis[nx] || !vis[ny])) {
        fa[nx] = ny;
        if (vis[nx]) vis[ny] = true;
        return true;
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    lo(i, 0, n) scanf("%d%d", &x[i], &y[i]);
    lo(i, 0, n) scanf("%lld", cc + i);
    lo(i, 0, n) scanf("%lld", kk + i);
    lo(i, 0, n) {
        fa[i] = i;
        lo(j, 0, n) adj[i][j] = ((LL)std::abs(x[i] - x[j]) + (LL)std::abs(y[i] - y[j])) * (kk[i] + kk[j]);
    }
    lo(i, 0, n) {
        dat.pb(Node(i, -1, cc[i]));
        lo(j, 0, n) {
            if (j != i) dat.pb(Node(i, j, adj[i][j]));
        }
    }
    sort(dat.begin(), dat.end());
    LL ans = 0;
    vector<pair<int, int> > e;
    vector<int> dd;
    lo(i, 0, dat.size()) {
        if (dat[i].b == -1) {
            if (!vis[Find(dat[i].a)]) ans += dat[i].cst, vis[Find(dat[i].a)] = true, dd.pb(dat[i].a + 1);
        } else {
            if (Union(dat[i].a, dat[i].b)) {
                ans += dat[i].cst, e.pb(mk(dat[i].a + 1, dat[i].b + 1));
            }
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", (int)dd.size());
    lo(i, 0, dd.size()) {
        if (i) putchar(' ');
        printf("%d", dd[i]);
    }
    printf("\n%d\n", (int)e.size());
    lo(i, 0, e.size()) printf("%d %d\n", e[i].first, e[i].second);
    return 0;
}
