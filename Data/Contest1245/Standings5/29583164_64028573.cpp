#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;

struct City {
    ll x;
    ll y;
    int c;
    int k;
};

ll dist(vector<City>& a, int i, int j) {
    return abs((a[i].x - a[j].x)) + abs((a[i].y - a[j].y));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<City> cities(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cities[i].x = x, cities[i].y = y;
    }
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        cities[i].c = c;
    }

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cities[i].k = k;
    }

    vector< vector<ll> > g(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; ++i) {
        g[i][n] = g[n][i] = cities[i].c;
        for (int j = i + 1; j < n; ++j) {
            g[i][j] = g[j][i] = (0ll + cities[i].k + cities[j].k) * dist(cities, i, j);
        }
    }

    const ll INF = 1e18;
    vector<ll> dist(n + 1, INF);
    vector<int> from(n + 1, -1);
    vector<int> used(n + 1, false);
    dist[0] = 0;

    vector< pair<int, int> > spanning;

    for (int IT = 0; IT <= n; ++IT) {
        int closest = -1;
        ll best = INF + 1;
        for (int i = 0; i <= n; ++i) {
            if (used[i]) continue;
            if (dist[i] < best) {
                best = dist[i];
                closest = i;
            }
        }
        if (from[closest] != -1) {
            spanning.push_back({from[closest], closest});
        }
        for (int i = 0; i <= n; ++i) {
            if (used[i]) continue;
            if (g[closest][i] < dist[i]) {
                dist[i] = g[closest][i];
                from[i] = closest;
            }
        }
        used[closest] = true;
    }
    ll w = 0;
    for (auto e : spanning) {
        if (e.first == -1 || e.second == -1) continue;
        w += g[e.first][e.second];
    }

    vector<int> stations;
    for (auto& e: spanning) {
        if (e.first == n) {
            stations.push_back(e.second);
        } else if (e.second == n) {
            stations.push_back(e.first);
        }
    }

    cout << w << "\n";
    cout << stations.size() << "\n";
    for (int x : stations) {
        cout << (x + 1) << " ";
    }
    cout << "\n" << n - stations.size() << "\n";
    for (auto& e: spanning) {
        if (e.first == n || e.second == n) continue;
        cout << (e.first + 1) << " " << (e.second + 1) << "\n";
    }

    return 0;
}