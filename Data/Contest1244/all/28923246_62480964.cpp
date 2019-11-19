#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <memory>
#include <initializer_list>
#include <iomanip>
#include <stack>
#include <bitset>
#include <cstdio>
// #include <complex>
#include <random>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// const ll INF = 1e9;
// const ld INF = 1e20;
// const ll MOD = 1e9 + 7;
//const double EPS = 1e-9;
//const double PI = acos(-1);

vector<vector<int>> g;
vector<int> cost[3];
vector<int> order;
vector<int> used;

void dfs(int v) {
    used[v] = 1;
    order.push_back(v);
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

vector<int> color;
ll kek() {
    ll cnt = cost[color[order[0]] - 1][order[0]] + cost[color[order[1]] - 1][order[1]];
    for (int i = 2; i < order.size(); ++i) {
        int c = 6 - color[order[i - 1]] - color[order[i - 2]];
        cnt += cost[c - 1][order[i]];
        color[order[i]] = c;
    }
    return cnt;
}


void solve() {
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    cost[0].resize(n);
    cost[1].resize(n);
    cost[2].resize(n);
    color.resize(n);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> u >> v;
        --u;
        --v;
        g[v].push_back(u);
        g[u].push_back(v);
        if (g[v].size() > 2 || g[u].size() > 2) {
            cout << -1;
            return;
        } 
    }
    int st = -1;
    for (int i = 0 ; i < n; ++i) {
        if (g[i].size() == 1) {
            st = i;
        }
    }
    dfs(st);
    vector<int> res;
    ll best = 10000000000000000;
    ll t;
    color[order[0]] = 1;
    color[order[1]] = 2;
    t = kek();
    if (t < best) {
        best = t;
        res = color;
    }
    color[order[0]] = 1;
    color[order[1]] = 3;
    t = kek();
    if (t < best) {
        best = t;
        res = color;
    }
    color[order[0]] = 2;
    color[order[1]] = 1;
    t = kek();
    if (t < best) {
        best = t;
        res = color;
    }
    color[order[0]] = 2;
    color[order[1]] = 3;
    t = kek();
    if (t < best) {
        best = t;
        res = color;
    }
    color[order[0]] = 3;
    color[order[1]] = 1;
    t = kek();
    if (t < best) {
        best = t;
        res = color;
    }
    color[order[0]] = 3;
    color[order[1]] = 2;
    t = kek();
    if (t < best) {
        best = t;
        res = color;
    }

    cout << best << "\n";

    for (int x : res) {
        cout << x << " ";
    }



}

int main() {
    // freopen("moscow.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
