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

vector<set<int>> g;
vector<vector<int>> g2;
vector<bool> used;

void dfs(int u) {
    used[u] = 1;
    for(auto v : g2[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
}

signed main() {
    seriy();
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    g2.resize(n + 1);
    used.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i = 0; i < n; i++) {
        g[i].insert(n);
        g[i].insert(-1);
    }
    for(int i = 0; i < n; i++) {
        if(g[i].size() == n + 2) {
            continue;
        }
        for(auto j = next(g[i].begin()); j != g[i].end(); j++) {
            if(*j - *prev(j) != 1) {
                int v = *prev(j) + 1;
                g[i].insert(v);
                g[v].insert(i);
                g2[i].push_back(v);
                g2[v].push_back(i);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1;
    return 0;
}