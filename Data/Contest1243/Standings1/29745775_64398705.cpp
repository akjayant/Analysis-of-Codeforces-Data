#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long long;

vector<int> dsu(100500);
vector<int> g[100500];

int get(int x) {
    return (x == dsu[x] ? x : dsu[x] = get(dsu[x]));
}

void unite(int a, int b) {
    dsu[get(a)] = get(b);
}

bool cmp(int a, int b) {
    return g[a].size() < g[b].size();
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        v[i - 1] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    int ans = n;
    vector<int> used(n + 1);
    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (dsu[x] != x) continue;
        for (int i = 1; i <= n; i++) used[i] = 0;
        for (int i : g[x]) used[i] = 1;
        for (int i = 1; i <= n; i++) {
            if (get(i) != get(x) && !used[i]) {
                unite(i, x);
                ans--;
            }
        }
    }
    vector<int> cnt[n + 1];
    map<pair<int, int>, int> u;
    for (int i = 1; i <= n; i++) {
        cnt[get(i)].push_back(i);
        for (int x : g[i]) {
            if (get(x) != get(i)) u[{get(x), get(i)}]++;
        }
    }
    vector<pair<int, int>> sl;
    for (auto e : u) {
        int a = e.first.first;
        int b = e.first.second;
        int c = e.second;
        ll need = (cnt[a].size() * 1ll * cnt[b].size());
        if (need != c) {
            sl.push_back({a, b});
        }
    }
    for (auto e : sl) {
        int a = e.first;
        int b = e.second;
        if (get(a) != get(b)) {
            unite(a, b);
            ans--;
        }
    }
    cout << ans - 1;
}
