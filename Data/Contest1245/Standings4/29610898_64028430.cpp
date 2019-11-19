#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define lc rt << 1
#define rc rt << 1 | 1
#define X first
#define Y second
inline int lowbit(int x) { return x & -x; }
typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
const int N = 2000 + 10;
const int M = 4e6 + 10;
const int maxn = 2e3 + 10;
const int maxm = 4e3 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const db eps = 1e-5;

int c[N];
int k[N];
pii p[N];
int fa[N];
LL wt[N];
struct E {
    int u, v;
    LL w;
    bool operator < (const E &rhs) const {
        return w < rhs.w;
    }
}e[M];

inline LL getW(int u, int v) {
    return 1LL * (k[u] + k[v]) * (abs(p[u].X - p[v].X) + abs(p[u].Y - p[v].Y));
}
inline int getFa(int u) { return fa[u] == u ? u : fa[u] = getFa(fa[u]); }
vector<pii> edge;
vector<int> one;

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = pii(x, y);
    }

    LL sum = 0;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        cin >> c[i];
        wt[i] = c[i];
        sum += c[i];
    }

    for (int i = 1; i <= n; i++)
        cin >> k[i];

    int tot = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            e[++tot] = {i, j, getW(i, j)};
    }

    sort(e + 1, e + 1 + tot);

    for (int i = 1; i <= tot; i++) {
        int du = getFa(e[i].u);
        int dv = getFa(e[i].v);
        if (du != dv) {
            if (e[i].w < max(wt[du], wt[dv])) {
                edge.emplace_back(e[i].u, e[i].v);
                sum += e[i].w - max(wt[du], wt[dv]);
                if (wt[du] < wt[dv]) {
                    fa[dv] = du;
                    wt[dv] = wt[du];
                } else {
                    fa[du] = dv;
                    wt[du] = wt[dv];
                }
            }
        }
    }

    cout << sum << "\n";

    for (int i = 1; i <= n; i++) if (getFa(i) == i)
        one.emplace_back(i);

    int sz = one.size();

    cout << sz << "\n";

    if (sz) {
        for (int i = 0; i < sz; i++)
            cout << one[i] << " \n"[i == sz - 1];
    }


    sz = edge.size();

    cout << sz << "\n";

    if (sz) {
        for (int i = 0; i < sz; i++)
            cout << edge[i].X << " " << edge[i].Y << "\n";
    }

    return 0;
}
