#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2010;

int x[maxn], y[maxn];
ll c[maxn], k[maxn];
int n;
struct node {
    int u, v; ll w;
    inline bool operator < (const node &p) const {
        return w < p.w;
    }
}a[maxn*maxn];
int fa[maxn];
bool vis[maxn];

int fnd(int x) {
    return fa[x] ==x ? fa[x] : fa[x] = fnd(fa[x]);
}

ll dist(int i, int j) {
    return (k[i] + k[j]) * (abs(x[i]-x[j]) + abs(y[i] - y[j]));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", x+i, y+i);
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) scanf("%lld", c+i);
    for (int i = 1; i <= n; ++i) scanf("%lld", k+i);

    int pn = 0;
    for (int i = 1; i <= n; ++i) a[++pn] = {0, i, c[i]};
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j)
            a[++pn] = {i, j, dist(i, j)};
    }
    sort(a+1, a+1+pn);

    ll ans = 0;
    vector<node> vec;
    vector<int> res;
    for (int i = 1; i <= pn; ++i) {
        int x = a[i].u, y = a[i].v;
        int fx = fnd(x), fy = fnd(y);
        if(fx != fy) {
            if(x == 0) res.push_back(y), ans += c[y];
            else {
                vec.push_back({x, y});
                ans += dist(x, y);
            }
            fa[fy] = fx;
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", res.size());
    for (auto v: res) printf("%d ", v); puts("");
    printf("%d\n", vec.size());
    for (auto cur: vec) {
        printf("%d %d\n", cur.u, cur.v);
    }
    return 0;
}