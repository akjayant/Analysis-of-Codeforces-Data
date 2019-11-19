#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SET(x, a) memset(x, a, sizeof x)

int n;
ll c[4][100005];
int deg[100005];
vector<int> adj[100005];
ll col[100005][4][4];

ll dfs (int x, int pc, int pc2, bool t, int p = -1) {
    // cout << x << endl;
    if (!t && deg[x] == 1) return col[x][pc][pc2] = c[pc][x];
    if (col[x][pc][pc2] != -1) return col[x][pc][pc2];
    ll ans = LLONG_MAX;
    for (int i = 0; i < adj[x].size(); ++i) {
        int v = adj[x][i]; if (v == p) continue;
        for (int j = 1; j <= 3; ++j) {
            if (j != pc && j != pc2) {
                ans = min(ans, dfs(v, j, pc, 0, x));
            }
        } 
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
        exit(0);
    }
    return col[x][pc][pc2] = ans + c[pc][x];
}
ll output[100005];
void trace (int x, int pc, int pc2, bool t, int p = -1) {
    output[x] = pc;
    if (!t && deg[x] == 1) return;
    for (int i = 0; i < adj[x].size(); ++i) {
        int v = adj[x][i]; if (v == p) continue;
        for (int j = 1; j <= 3; ++j) {
            if (j == pc || j == pc2) continue;
            if (dfs(v, j, pc, 0, x) + c[pc][x] == col[x][pc][pc2]) {
                trace(v, j, pc, 0, x);
            }
        } 
    }
    return ;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    
    cin >> n;
    for(int i = 1; i <= 3; ++i)
        for (int j = 1; j <= n; ++j) cin >> c[i][j];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int st = -1, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) cnt++, st = i;
        else if (deg[i] > 2) return cout << -1 << endl, 0;
    }
    if (cnt > 2 || cnt == 0) return cout << -1 << endl, 0;
    SET(col, -1);
    ll a = dfs(st, 1, 0, 1), b = dfs(st, 2, 0, 1), c = dfs(st, 3, 0, 1);
    if (min(a, min(b, c)) == a) {
        trace(st, 1, 0, 1);
    } else if(min(a, min(b, c)) == b) {
trace(st, 2, 0, 1);
    } else {
        trace(st, 3, 0, 1);
    }
    cout << min(a, min(b, c)) << endl;
    for (int i = 1; i <= n; ++i) cout << output[i] << " ";
    cout << endl;
}