#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

namespace UnionFindSet {
template <int N>
struct UnionFindSet {
    int fa[N];
    UnionFindSet() {
        for (register int i = 0; i < N; ++i) fa[i] = i;
    }
    int getf(int x) { return fa[x] = (fa[x] == x ? x : getf(fa[x])); }
    inline void merge(int x, int y) { fa[getf(x)] = getf(y); }
    inline bool same(int x, int y) { return getf(x) == getf(y); }
};
};  // namespace UnionFindSet

const int N = 2020;

UnionFindSet::UnionFindSet<N> ufs;

struct City{
    ll x, y, k, c;
} a[N];

ll calc(const City &a, const City &b){
    return (abs(a.x-b.x)+abs(a.y-b.y))*(a.k + b.k);
}

struct Edge{
    int u, v;
    ll w;
} e[N*N*2];

bool cmp(const Edge& a, const Edge& b){
    return a.w < b.w;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i].x >> a[i].y;
    rep(i, 1, n) cin >> a[i].c;
    rep(i, 1, n) cin >> a[i].k;
    int cnt = 0;
    rep(i, 1, n){
        e[cnt].u = 0, e[cnt].v = i, e[cnt].w = a[i].c; ++cnt;
    }
    rep(i, 1, n){
        rep(j, 1, n){
            if (i == j) continue;
            e[cnt].u = i, e[cnt].v = j, e[cnt].w = calc(a[i], a[j]); ++cnt;
        }
    }
    std::sort(e, e+cnt, cmp);
    ll ans = 0;
    std::vector<int> st;
    std::vector<pii> p;
    rep(i, 0, cnt-1){
        if (!ufs.same(e[i].u, e[i].v)){
            if (e[i].u == 0) st.push_back(e[i].v);
            else p.push_back({e[i].u, e[i].v});
            ufs.merge(e[i].u, e[i].v);
            ans += e[i].w;
        }
    }
    cout << ans << endl;
    cout << st.size() << endl;
    for(auto x : st) cout << x << ' '; cout << endl;
    cout << p.size() << endl;
    for(auto x : p) cout << x.first << ' ' << x.second << '\n';
    return 0;
}
