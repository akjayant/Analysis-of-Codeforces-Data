#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
typedef pair<int, int> ii;

const int mod = 1e9 + 7;


int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}

const int N = 1e5 + 5;

int n, c[N][4], pref[N][4][4], dp[N][4][4], ans[N], node[N];

vector<int> graph[N];

const int inf = 1e9 * 1e9;

void dfs(int u, int p, int val) {
    node[val] = u;
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(v == p) continue;
        dfs(v, u, val + 1);
    }
}

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++)
            cin >> c[j][i];
    }
    //cout << c[2][1] << "\n";
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int hihi;
    for(int i = 1; i <= n; i++) {
        if(graph[i].size() >= 3) {
            cout << "-1\n";
            exit(0);
        }
        if(graph[i].size() == 1)
            hihi = i;
    }
    dfs(hihi, hihi, 1);
    for(int j = 1; j <= 3; j++) {
        for(int l = 1; l <= 3; l++) {
            if(j == l) continue;
            dp[node[2]][j][l] = c[node[2]][j] + c[node[1]][l];
            //cout << dp[node[2]][j][l] << " " << j << " " << l << "\n";
        }
    }
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int l = 1; l <= 3; l++) {
                if(j == l) continue;
                dp[node[i]][j][l] = inf;
                for(int k = 1; k <= 3; k++) {
                    if(j == k || k == l) continue;
                    //cout << j << " " << k << " " << l << "\n";
                    if(dp[node[i - 1]][l][k] + c[node[i]][j] < dp[node[i]][j][l]) {
                        //cout << dp[node[i - 1]][l][k] + c[node[i]][j] << " " << j << " " << l << " " << k << " " << c[node[i]][j] << "\n";
                        dp[node[i]][j][l] = min(dp[node[i]][j][l], dp[node[i - 1]][l][k] + c[node[i]][j]);
                        pref[node[i]][j][l] = k;
                    }
                }
            }
        }
    }
    int id, mn = inf, id1;
    for(int j = 1; j <= 3; j++) {
        for(int k = 1; k <= 3; k++) {
            if(j == k) continue;
            if(dp[node[n]][j][k] < mn) {
                mn = dp[node[n]][j][k];
                id = j; id1 = k;
            }
        }
    }
    cout << mn << "\n";
    int pos = n;
    //cout << id << " " << id1 << "\n";
    while(pos > 1) {
        ans[node[pos]] = id;
        ans[node[pos - 1]] = id1;
        //id = id1;
        int id2 = pref[node[pos]][id][id1];
        id = id1;
        id1 = id2;
        pos--;
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
