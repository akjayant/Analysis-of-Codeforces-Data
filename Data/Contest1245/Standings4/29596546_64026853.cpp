/*
  |\      _,,,---,,_
  /,`--'`'    -.  ;-;;,_
 |,4-. ) )-,_..;\ (  `'-'
'--'' (_/`--' `-'\_)
*/

#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef pair<int, int> II;

const int N = 2005;
const int oo = 1000000007;

int p[N], n, x[N], y[N], c[N], k[N];
vector<pair<ll, pair<int, int> > > edges;
ll adj[N][N];

int getroot(int u) {
    return p[u] = (p[u] == u) ? u : getroot(p[u]);
}

void merge(int u, int v) {
    p[getroot(v)] = getroot(u);
}

int main() {
#ifdef THELAZYCAT
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // THELAZYCAT

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i) {
        cin >> adj[0][i];
        adj[i][0] = adj[0][i];
        edges.push_back(make_pair(adj[0][i], make_pair(0,i)));
    }
    for (int i = 1; i <= n; ++i) cin >> k[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j) {
            adj[i][j] = adj[j][i] = (ll)(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            edges.push_back(make_pair(adj[i][j], make_pair(i,j)));
        }
    
    sort(edges.begin(), edges.end());
    for (int i = 0; i <= n; ++i) p[i] = i;
    vector<pair<int, int> > selected;
    for (int i = 0; i < edges.size(); ++i) {
        if (selected.size() == n) break; // n+1 nodes
        ll w = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (getroot(u) == getroot(v)) continue;
        merge(u, v);
        selected.push_back(make_pair(u, v));
    }
    ll ans = 0;
    vector<int> stations;
    for (int i = 0; i < selected.size(); ++i) {
        int u = selected[i].first, v=selected[i].second;
        ans += adj[u][v];
        if (u == 0 || v == 0) {
            stations.push_back((u == 0) ? v : u);
        }
    }
    cout << ans << endl;
    cout << stations.size() << endl;
    for (int st : stations) cout << st << ' ';
    cout << endl;
    cout << n-stations.size() << endl;
    for (int i = 0; i < selected.size(); ++i) {
        int u = selected[i].first, v=selected[i].second;
        if (u != 0 && v != 0) {
            cout << u << ' ' <<  v << endl;
        }
    }




}