/*

 ∧＿∧
( ･ω･｡)つ━☆・*。
⊂　 ノ 　　　・゜
しーＪ　　 Accepted

*/



// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define all(x) begin(x), end(x)
#define x first
#define y second
#define int long long

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld PI = atan2(0, -1);

void seriy() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(14);
    #ifdef _offline
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

const int MAXN = 1e6 + 10;
const int MAXM = 600;
const int INF = 1e18;
const int BASE = 47;
const int MOD = 1e9 + 7;
const int MAXLOG = 21;

vector<vector<int>> g;
vector<vector<vector<int>>> dp;
vector<vector<vector<pair<int, int>>>> res;
vector<vector<int>> a;
vector<int> lol;

void dfs(int u, int p, int i) {
    lol.push_back(u);
    if(p != -1) {
        dp[i][0][1] = dp[i - 1][1][2] + a[u][0];
        res[i][0][1] = {1, 2};
        dp[i][0][2] = dp[i - 1][2][1] + a[u][0];
        res[i][0][2] = {2, 1};

        dp[i][1][0] = dp[i - 1][0][2] + a[u][1];
        res[i][1][0] = {0, 2};
        dp[i][1][2] = dp[i - 1][2][0] + a[u][1];
        res[i][1][2] = {2, 0};

        dp[i][2][0] = dp[i - 1][0][1] + a[u][2];
        res[i][2][0] = {0, 1};
        dp[i][2][1] = dp[i - 1][1][0] + a[u][2];
        res[i][2][1] = {1, 0};
    }
    else {
        for(int j = 0; j < 3; j++) {
            dp[i][0][j] = a[u][0];
            dp[i][1][j] = a[u][1];
            dp[i][2][j] = a[u][2];
        }
        for(int j = 0; j < 3; j++) {
            dp[i][j][j] = INF;
        }
    }
    for(auto v : g[u]) {
        if(v != p) {
            dfs(v, u, i + 1);
        }
    }
}

signed main() {
    seriy();
    int n;
    cin >> n;
    g.resize(n);
    dp.resize(n, vector<vector<int>>(3, vector<int>(3, INF)));
    res.resize(n, vector<vector<pair<int, int>>>(3, vector<pair<int, int>>(3, {-1, -1})));
    a.resize(n, vector<int>(3));
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < n; i++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st;
    for(int i = 0; i < n; i++) {
        if(g[i].size() > 2) {
            return cout << -1, 0;
        }
        if(g[i].size() == 1) {
            st = i;
        }
    }
    dfs(st, -1, 0);
    int ans = INF;
    pair<int, int> wh;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(ans > dp[n - 1][i][j]) {
                ans = dp[n - 1][i][j];
                wh = {i, j};
            }
        }
    }
    cout << ans << '\n';
    int cur = n - 1;
    vector<int> kek(n);
    while(cur >= 0) {
        kek[lol[cur]] = wh.x;
        wh = res[cur][wh.x][wh.y];
        cur--;
    }
    for(auto i : kek) {
        cout << i + 1 << " ";
    }
    return 0;
}