// CF D
// DeP
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 2005, MAXM = MAXN * MAXN;

struct Edge {
    int from, to; LL w;
    bool operator < (const Edge& rhs) {
        return w < rhs.w;
    }
} edges[MAXM];

int n, nE;
int X[MAXN], Y[MAXN]; LL C[MAXN], K[MAXN];
bool Mark[MAXM];
vector<int> Power;
vector<Edge> E;

namespace DSU {
    int fa[MAXN], rnk[MAXN];

    inline void init() {
        for (int i = 0; i <= n; ++i) fa[i] = i, rnk[i] = 1;
    }

    int findfa(int x) {
        return fa[x] = fa[x] == x? x: findfa(fa[x]);
    }

    inline void join(int x, int y) {
        x = findfa(x); y = findfa(y);
        if (x == y) return;
        if (rnk[x] < rnk[y]) fa[x] = y;
        else {
            fa[y] = x;
            if (rnk[x] == rnk[y]) ++rnk[x];
        }
    }
}

namespace Kruksal {
    void solve() {
        LL ans = 0; int cnt = 0;
        sort(edges+1, edges+1+nE);
        DSU::init();
        for (int i = 1; i <= nE; ++i) {
            const Edge& e = edges[i];
            if (DSU::findfa(e.from) != DSU::findfa(e.to)) {
                Mark[i] = true; ans += e.w;
                DSU::join(e.from, e.to);
                if (++cnt == n) break;
            }
        }
        for (int i = 1; i <= nE; ++i) if (Mark[i]) {
            const Edge& e = edges[i];
            if (!e.from) Power.push_back(e.to);
            else E.push_back(e);
        }
        // output
        printf("%I64d\n", ans);
        printf("%d\n", (int)Power.size());
        for (size_t i = 0; i < Power.size(); ++i) printf("%d ", Power[i]);
        putchar('\n');
        printf("%d\n", (int)E.size());
        for (size_t i = 0; i < E.size(); ++i) printf("%d %d\n", E[i].from, E[i].to);
    }
}

LL Abs(LL x) { return x < 0? -x: x; }

int main() {
    // input
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", X+i, Y+i);
    for (int i = 1; i <= n; ++i) scanf("%I64d", C+i);
    for (int i = 1; i <= n; ++i) scanf("%I64d", K+i);
    // solve
    int S = 0;
    for (int i = 1; i <= n; ++i)
        edges[++nE] = (Edge){ S, i, C[i] };
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            edges[++nE] = (Edge){ i, j, (K[i] + K[j]) * (Abs(X[i] - X[j]) + Abs(Y[i] - Y[j])) };
    Kruksal::solve();
    return 0;
}
