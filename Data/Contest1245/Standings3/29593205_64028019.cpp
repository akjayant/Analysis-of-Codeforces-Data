#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int x[2005], y[2005];
ll build_cost[2005];
ll k[2005];
bool nyala[2005];
int par[2005];

int get_par(int u) {
    if (par[u] == u) return u;
    return par[u] = get_par(par[u]);
}

bool same(int u, int v) {
    return get_par(u) == get_par(v);
}

void join(int u, int v) {
    if (nyala[get_par(v)] || nyala[get_par(u)]) {
        nyala[get_par(v)] = true;
        nyala[get_par(u)] = true;
    }
    par[get_par(u)] = get_par(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) cin >> build_cost[i];
    for (int i = 0; i < n; i++) cin >> k[i];

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>> > pq;
    for (int i = 0; i < n; i++) {
        pq.push({build_cost[i], {i, i}});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll jarak = abs(1LL * x[i] - 1LL * x[j]) + abs(1LL * y[i] - 1LL * y[j]);
            pq.push({jarak * (k[i] + k[j]), {i, j}});
        }
    }

    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    
    ll ans = 0;
    vector<int> ans_build;
    vector<pair<int, int>> ans_pair;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        ll cost = cur.first;
        int u = cur.second.first;
        int v = cur.second.second;

        if (u == v) {
            if (!nyala[get_par(u)]) {
                //cout << "nyala: " << u << ", cost: " << cost << ", par: "<< get_par(u) << endl;
                nyala[get_par(u)] = true;
                ans += cost;
                ans_build.push_back(u + 1);
            }
        } else {
            
            if ((!nyala[get_par(u)] || !nyala[get_par(v)]) && !same(u, v)) {
                //cout << "gabung: " << u  << " " << v << ", cost: " << cost << endl;
                join(u, v);
                ans += cost;
                ans_pair.push_back({u + 1, v + 1});
            }
        }
    }

    cout << ans << "\n";
    cout << (int)ans_build.size() << "\n";
    for (int i = 0; i < (int)ans_build.size(); i++) {
        cout << ans_build[i] << (i == (int)ans_build.size() - 1? "\n" : " ");
    }
    cout << (int)ans_pair.size() << "\n";
    for (int i = 0; i < (int)ans_pair.size(); i++) {
        cout << ans_pair[i].first << " " << ans_pair[i].second << "\n";
    }
    return 0;
}