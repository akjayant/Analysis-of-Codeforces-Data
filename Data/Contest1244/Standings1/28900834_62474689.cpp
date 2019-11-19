#include <bits/stdc++.h>

using namespace std;

#define int long long

const int big = 1e18;

struct cost {
    int a, b, c;
};

void solve() {
    int n;
    cin >> n;
    vector <cost> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].a;
    for (int i = 0; i < n; ++i) cin >> a[i].b;
    for (int i = 0; i < n; ++i) cin >> a[i].c;
    vector <vector <int> > g(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= 3) {
            cout << -1;
            return;
        }
    }
    int st = 0;
    for (int i = 0; i < n; ++i) if (g[i].size() == 1) st = i;
    queue <int> q;
    q.push(st);
    vector <int> dist(n, big);
    dist[st] = 0;
    //cout << 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    vector <int> a1, a2, a3;
    for (int i = 0; i < n; ++i) {
        if ((dist[i] % 3) == 0) a1.push_back(i);
        if ((dist[i] % 3) == 1) a2.push_back(i);
        if ((dist[i] % 3) == 2) a3.push_back(i);
    }
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
    for (int i = 0; i < a1.size(); ++i) {
        sum1 += a[a1[i]].a;
        sum2 += a[a1[i]].a;
        sum3 += a[a1[i]].b;
        sum4 += a[a1[i]].b;
        sum5 += a[a1[i]].c;
        sum6 += a[a1[i]].c;
    }
    for (int i = 0; i < a2.size(); ++i) {
        sum1 += a[a2[i]].b;
        sum2 += a[a2[i]].c;
        sum3 += a[a2[i]].a;
        sum4 += a[a2[i]].c;
        sum5 += a[a2[i]].a;
        sum6 += a[a2[i]].b;
    }
    for (int i = 0; i < a3.size(); ++i) {
        sum1 += a[a3[i]].c;
        sum2 += a[a3[i]].b;
        sum3 += a[a3[i]].c;
        sum4 += a[a3[i]].a;
        sum5 += a[a3[i]].b;
        sum6 += a[a3[i]].a;
    }
    int anss;
    vector <int> ans(n);
    if (sum1 <= sum2 && sum1 <= sum3 && sum1 <= sum4 && sum1 <= sum5 && sum1 <= sum6) {
        for (int i = 0; i < a1.size(); ++i) ans[a1[i]] = 1;
        for (int i = 0; i < a2.size(); ++i) ans[a2[i]] = 2;
        for (int i = 0; i < a3.size(); ++i) ans[a3[i]] = 3;
        anss = sum1;
    }
    else if (sum2 <= sum1 && sum2 <= sum3 && sum2 <= sum4 && sum2 <= sum5 && sum2 <= sum6) {
        for (int i = 0; i < a1.size(); ++i) ans[a1[i]] = 1;
        for (int i = 0; i < a2.size(); ++i) ans[a2[i]] = 3;
        for (int i = 0; i < a3.size(); ++i) ans[a3[i]] = 2;
        anss = sum2;
    }
    else if (sum3 <= sum2 && sum3 <= sum1 && sum3 <= sum4 && sum3 <= sum5 && sum3 <= sum6) {
        for (int i = 0; i < a1.size(); ++i) ans[a1[i]] = 2;
        for (int i = 0; i < a2.size(); ++i) ans[a2[i]] = 1;
        for (int i = 0; i < a3.size(); ++i) ans[a3[i]] = 3;
        anss = sum3;
    }
    else if (sum4 <= sum2 && sum4 <= sum3 && sum4 <= sum1 && sum4 <= sum5 && sum4 <= sum6) {
        for (int i = 0; i < a1.size(); ++i) ans[a1[i]] = 2;
        for (int i = 0; i < a2.size(); ++i) ans[a2[i]] = 3;
        for (int i = 0; i < a3.size(); ++i) ans[a3[i]] = 1;
        anss = sum4;
    }
    else if (sum5 <= sum2 && sum5 <= sum3 && sum5 <= sum4 && sum5 <= sum1 && sum5 <= sum6) {
        for (int i = 0; i < a1.size(); ++i) ans[a1[i]] = 3;
        for (int i = 0; i < a2.size(); ++i) ans[a2[i]] = 1;
        for (int i = 0; i < a3.size(); ++i) ans[a3[i]] = 2;
        anss = sum5;
    }
    else {
        for (int i = 0; i < a1.size(); ++i) ans[a1[i]] = 3;
        for (int i = 0; i < a2.size(); ++i) ans[a2[i]] = 2;
        for (int i = 0; i < a3.size(); ++i) ans[a3[i]] = 1;
        anss = sum6;
    }
    cout << anss << '\n';
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}

signed main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    solve();
    return 0;
}
