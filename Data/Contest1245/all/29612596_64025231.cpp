//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
long long ans;
int x[N], y[N];
int c[N];
int mn[N];
long long k[N];
multiset<long long> st[N];
bool vis[N];
int par[N];

int getpar(int x) {
    if (par[x] == x) return x;
    return par[x] = getpar(par[x]);
}

void merge(int a, int b) {
    a = getpar(a);
    b = getpar(b);
    if (a == b) return;
    mn[b] = min(mn[b], mn[a]);
    par[a] = b;
}


int main() {
    //freopen("in.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
        par[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", c + i);
        mn[i] = c[i];
        ans += c[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", k + i);
    }
    vector<pair<long long, pair<int, int>>> vec;
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            if (a == b) continue;
            long long d = abs(x[a] - x[b]) + abs(y[a] - y[b]);
            d *= (k[a] + k[b]);
            vec.push_back({d, {a, b}});
        }
    }

    vector<int> el;
    vector<pair<int, int>> edg;
    sort(vec.begin(), vec.end());
    for (auto &e:vec) {
        long long d = e.first;
        int a = e.second.first;
        int b = e.second.second;
        if (getpar(a) == getpar(b)) continue;
        long long ca = mn[getpar(a)], cb = mn[getpar(b)];
        long long v = d - ca - cb + min(ca, cb);
        if (v <= 0) {
            edg.push_back({a, b});
            merge(a, b);
            ans += v;
        }
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[getpar(i)].push_back(i);
    }
    for (auto C:mp) {
        int mn = 1e9+5;
        int v = -1;
        for (auto x:C.second) {
            if (c[x] < mn) {
                mn = c[x];
                v = x;
            }
        }
        el.push_back(v);
    }
    printf("%lld\n", ans);
    printf("%d\n", el.size());
    for (auto x:el) printf("%d ", x + 1);
    puts("");
    printf("%d\n", edg.size());
    for (auto p:edg) printf("%d %d\n", p.first + 1, p.second + 1);
}