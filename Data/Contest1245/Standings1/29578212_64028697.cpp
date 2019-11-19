/*================================================================
*   Copyright (C) 2019 Sangfor Ltd. All rights reserved.
*
*   创 建 者： badcw
*   创建日期： 2019-11-01 22:35:15
*
================================================================*/
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int maxn = 2005;
const int mod = 1e9+7;
ll qp(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template <class T>
inline bool scan(T& ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; // EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

//template <class T>
//inline void out(T x) {
//    if (x > 9) out(x / 10);
//    putchar(x % 10 + '0');
//}

int n;
int x[maxn], y[maxn];
int pre[maxn];
ll c[maxn], k[maxn];

struct edge {
    int from, to;
    ll sz;
    int vis;
    bool operator < (const edge& oth) const {
        return sz < oth.sz;
    }
};

ll dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int F(int x) { return x == pre[x] ? x : pre[x] = F(pre[x]); }

int main(int argc, char* argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        pre[i] = i;
        scanf("%d%d", &x[i], &y[i]);
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]), res += c[i];
    for (int i = 1; i <= n; ++i) scanf("%lld", &k[i]);
    vector<edge> E(n * n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            E[(i - 1) * n + j - 1] = {i, j, (k[i] + k[j]) * dist(i, j), 0};
        }
    }
    sort(E.begin(), E.end());
    int rese = 0;
    for (auto &i : E) {
        int u = F(i.from), v = F(i.to);
        if (u == v) continue;
        if (c[u] > c[v]) swap(u, v);
        if (c[v] >= i.sz) {
            pre[v] = u;
            i.vis = 1;
            rese ++;
            res += i.sz - c[v];
        }
    }
    printf("%lld\n", res);
    vector<int> resn;
    for (int i = 1; i <= n; ++i) {
        resn.push_back(F(i));
    }
    sort(resn.begin(), resn.end());
    resn.erase(unique(resn.begin(), resn.end()), resn.end());
    printf("%ld\n", resn.size());
    for (auto i : resn) {
        printf("%d ", i);
    }
    printf("\n");
    printf("%d\n", rese);
    for (auto i : E) {
        if (i.vis) printf("%d %d\n", i.from, i.to);
    }
    return 0;
}