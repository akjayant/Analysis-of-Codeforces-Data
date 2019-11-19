#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

const long long INF = 1e15;

signed main() {
    cin.tie(0);
    int n;
    cin >> n;
    int d[n + 1] = {};
    vector <int> tree[n + 1];
    long long c[n + 1][3];
    for (int i = 0; i < n; i++) {
        cin >> c[i + 1][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i + 1][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i + 1][2];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        d[v]++; d[u]++;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int maxd = 0, start = -1;
    for (int i = 1; i <= n; i++) {
        maxd = max(maxd, d[i]);
        if (d[i] == 1) {
            start = i;
        }
    }
    if (maxd > 2) {
        cout << -1;
        return 0;
    }
    long long min_cost = INF, min_cost_id = -1;
    int patern[] = {123, 132, 213, 231, 312, 321};
    for (int p = 0; p < 6; p++) {
        long long local_cost = 0;
        bool used[n + 1] = {};
        used[start] = 1;
        int pat[] = {patern[p] / 100 - 1, patern[p] / 10 % 10 - 1, patern[p] % 10 - 1};
        int v = start;
        for (int i = 0; i < n; i++) {
            local_cost += c[v][pat[i % 3]];
            used[v] = true;
            for (int u : tree[v]) {
                if (!used[u]) {
                    v = u;
                    break;
                }
            }
        }

        if (local_cost < min_cost) {
            min_cost = local_cost;
            min_cost_id = p;
        }
    }
    int v;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            v = i;
        }
    }
    int used1[n + 1] = {};
    int color[n + 1];
    used1[v] = 1;
    int pat[] = {patern[min_cost_id] / 100 - 1, patern[min_cost_id] / 10 % 10 - 1, patern[min_cost_id] % 10 - 1};
    for (int i = 0; i < n; i++) {
        color[v] = pat[i % 3] + 1;
        used1[v] = true;
        for (int u : tree[v]) {
            if (!used1[u]) {
                v = u;
                break;
            }
        }
    }
    cout << min_cost << endl;
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
}
