#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;
typedef long long int ll;

const int MAXN = 2001;
int x[MAXN];
int y[MAXN];
ll c[MAXN];
ll k[MAXN];
int ind[MAXN];
ll dist[MAXN];
bool used[MAXN];

ll calc_dist(int v1, int v2) {
    return (k[v1] + k[v2]) * (abs(x[v1] - x[v2]) + abs(y[v1] - y[v2]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int xx, yy;
        cin >> xx >> yy;
        x[i] = xx;
        y[i] = yy;
    }
    ll summary = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        dist[i] = c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    fill(ind, ind + n, -1);
    unordered_set<int> e;
    vector<pair<int, int>> ans;
    set<pair<ll, int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.insert({c[i], i});
    }
    while (!pq.empty()) {
        int v = (*pq.begin()).second;
        pq.erase(pq.begin());
        used[v] = true;
        if (ind[v] == -1) {
            summary += dist[v];
            e.insert(v);
        } else {
            summary += calc_dist(v, ind[v]);
            ans.push_back({v, ind[v]});
        }
        for (int i = 0; i < n; ++i) {
            ll t = calc_dist(v, i);
            if (!used[i] && t < dist[i]) {
                ind[i] = v;
                pq.erase({dist[i], i});
                pq.insert({t, i});
                dist[i] = t;
            }
        }
    }
    cout << summary << "\n";
    cout << e.size() << "\n";
    for (int v : e) {
        cout << v + 1 << " ";
    }
    cout << "\n";
    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
    return 0;
}
