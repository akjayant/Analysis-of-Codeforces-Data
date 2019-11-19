#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;

const int MAXN = 2010;
ll x[MAXN], y[MAXN], c[MAXN], k[MAXN];

int parent[MAXN];
int f(int i) {
    if (i == parent[i]) return i;
    return parent[i] = f(parent[i]);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) 
        cin >> c[i];
    for (int i = 1; i <= n; i++) 
        cin >> k[i];

    parent[0] = 0;
    vector<pair<ll, pair<int, int>>> edges;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        edges.push_back({c[i], {i, 0}});
        
        for (int j = 1; j < i; j++) {
            ll cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    vector<int> sol_stations;
    vector<pair<int, int>> sol_edges;
    ll total_cost = 0;

    for (auto it : edges) {
        ll cost = it.first;
        int i = it.second.first, j = it.second.second;

        int i_parent = f(i);
        int j_parent = f(j);
        if (i_parent == j_parent) continue;

        parent[i_parent] = j_parent;
        total_cost += cost;

        if (j == 0) sol_stations.push_back(i);
        else sol_edges.push_back({i, j});
    }

    cout << total_cost << "\n" << sol_stations.size() << "\n";
    for (int i : sol_stations) cout << i << " ";
    cout << "\n" << sol_edges.size() << "\n";
    for (auto it : sol_edges) cout << it.first << " " << it.second << "\n";

    return 0;
}

