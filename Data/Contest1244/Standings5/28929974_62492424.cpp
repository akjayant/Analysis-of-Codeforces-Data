#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <iomanip>
#include <cstring>

using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 1e5 + 19;


ll c1[MAXN];
ll c2[MAXN];
ll c3[MAXN];


vector<int> g[MAXN];

int color[MAXN];

void dfs1(int ver, int par){
    if (color[ver] == -1)
        color[ver] = (color[par] + 1) % 3;

    for (auto out : g[ver]){
        if (out == par)
            continue;
        dfs1(out, ver);
    }
}

int to_look;
bool dfs3(int ver, int par , int iter){
    if (iter == 3)
        return true;

    if (iter !=0 && color[ver] == to_look)
        return false;

    for (auto out : g[ver]){
        if (out == par)
            continue;

        if (!dfs3(out, ver, iter + 1))
            return false;
    }

    return true;
}

void solve() {


    int n;
    cin >> n;


    for (int i = 0; i <= n; ++i) {
        color[i] = -1;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> c1[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> c2[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c3[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


    for (int i = 1; i <= n; ++ i){
        if (g[i].size() == 1){
            color[i] = 0;
            dfs1(i, -1);
            break;
        }
    }


    for (int i = 1; i <= n; ++i) {
        to_look = color[i];
        if (!dfs3(i, -1, 0)) {
            cout << -1;
            return;
        }
    }
    vector<vector<int>> perm;
    perm.push_back({0, 1, 2});
    perm.push_back({0, 2, 1});
    perm.push_back({1, 0, 2});
    perm.push_back({1, 2, 0});
    perm.push_back({2, 0, 1});
    perm.push_back({2, 1, 0});

    vector<ll> answr;
    answr = {0, 0, 0, 0, 0, 0};

    for (int j = 0; j < 6; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (perm[j][color[i]] == 0) {
                answr[j] += c1[i];
            }

            if (perm[j][color[i]] == 1) {
                answr[j] += c2[i];
            }

            if (perm[j][color[i]] == 2) {
                answr[j] += c3[i];
            }
        }
    }


    ll a = 1e18;
    int ind = -1;

    for (int i = 0; i < 6; ++i) {
        if (a > answr[i]){
            ind = i;
            a = answr[i];
        }
    }

    cout << a << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << 1 + perm[ind][color[i]] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(20);
#ifndef ONLINE_JUDGE
    freopen("../input.in", "r", stdin);
    freopen("../output.out", "w", stdout);
#endif
    solve();
}