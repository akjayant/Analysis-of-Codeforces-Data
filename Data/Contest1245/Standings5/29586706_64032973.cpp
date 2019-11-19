#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;

int n, to[2010], top, r1, r2, r[2010];
int par[2010], rank0[2010];
pii p[maxn * 5];

void init(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        rank0[i] = 0;
    }
    return;
}

int find(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank0[x] < rank0[y])
        par[x] = y;
    else {
        par[y] = x;
        if (rank0[x] == rank0[y]) rank0[x]++;
    }
}

bool same(int x, int y) { return find(x) == find(y); }

struct edge {
    ll c;
    int u, v;
} es[maxn * 5];

bool cmp(edge x1, edge x2) { return x1.c < x2.c; }

ll kruskal() {
    sort(es, es + top, cmp);
    init(n);
    ll res = 0;
    for (int i = 0; i < top; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            if (e.u == 0)
                r[r1++] = e.v;
            else
                p[r2++] = {e.u, e.v};
            res += e.c;
        }
    }
    return res;
}

int x[2010], y[2010];
ll k[2010], c;

int main() {
    cin >> n;
    inc(i, 1, n) cin >> x[i] >> y[i];
    inc(i, 1, n) {
        cin >> c;
        es[top++] = {c, 0, i};
    }
    inc(i, 1, n) cin >> k[i];
    inc(i, 1, n) {
        inc(j, i + 1, n) {
            es[top++] = {(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])),
                         i, j};
        }
    }
    cout << kruskal() << "\n";
    printf("%d\n", r1);
    inc(i, 0, r1 - 1) printf("%d ", r[i]);
    printf("\n%d\n", r2);
    inc(i, 0, r2 - 1) printf("%d %d\n", p[i].fi, p[i].se);
}