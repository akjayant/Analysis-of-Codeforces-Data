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
vector<bool> used;

void dfs(int u) {
    used[u] = 1;
    for(auto v : g[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
}

signed main() {
    seriy();
    int n;
    cin >> n;
    vector<int> d, c;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            d.push_back(i);
            if(n / i != i) d.push_back(n / i);
        }
    }
    c = d;
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());
    if(c.size() == 0) {
        return cout << n, 0;
    }
    g.resize(c[0]);
    used.resize(c[0]);
    for(int i = 0; i < c[0]; i++) {
        for(int j = 1; j < c.size(); j++) {
            int u = i;
            int v = (c[j] + i) % c[0];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int cnt = 0;
    for(int i = 0; i < c[0]; i++) {
        if(!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}