#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <queue>
#include <utility>
#define rep(x,y,z) for(long long x=y;x<z;++x)
#define dwn(x,y,z) for(long long x=y;x>z;--x)
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    array<vector<ll>, 3> cost;
    vector<vector<ll>> perms = {
            {0, 1, 2},
            {0, 2, 1},
            {1, 0, 2},
            {1, 2, 0},
            {2, 0, 1},
            {2, 1, 0}
    };
    for (auto& vec : cost) {
        vec.resize(n);
        for (auto& x : vec) {
            cin >> x;
        }
    }
    vector<vector<ll>> g(n);
    vector<ll> colors(n);
    array<vector<ll>, 3> c_;
    rep(i,0,n) {
        colors[i] = -1;
    }
    rep(i,0,(n - 1)) {
        ll u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll list_num = -1;
    rep(i,0,n) {
        if (g[i].size() == 1) {
            list_num = i;
            break;
        }
    }

    queue<pair<ll, ll>> q;
    q.push(make_pair(list_num, 0));
    bool bad_end = false;
    while (!q.empty()) {
        auto p = q.front();
        ll v = p.first;
        ll c = p.second;
        colors[v] = c;
        c_[c].push_back(v);
        q.pop();
        if (g[v].size() > 2) {
            bad_end = true;
            break;
        }
        rep(i,0,(g[v].size())) {
            if (colors[g[v][i]] == -1) {
                q.push(make_pair(g[v][i], (c + 1) % 3));
            }
        }
    }
    if (bad_end) {
        cout << -1 << endl;
        return 0;
    }

    array<array<ll, 3>, 3> sums;

    rep(i,0,3) {
        sums[i][0] = sums[i][1] = sums[i][2] = 0;
        rep(j,0,(c_[i].size())) {
            sums[i][0] += cost[0][c_[i][j]];
            sums[i][1] += cost[1][c_[i][j]];
            sums[i][2] += cost[2][c_[i][j]];
        }
    }

    ll min_perm = 0;
    ll min_res = sums[0][perms[0][0]] + sums[1][perms[0][1]] + sums[2][perms[0][2]];
    rep(p,0,6) {
        ll res = sums[0][perms[p][0]] + sums[1][perms[p][1]] + sums[2][perms[p][2]];
        if (res < min_res) {
            min_res = res;
            min_perm = p;
        }
    }
    cout << min_res << endl;
    rep(i,0,n) {
        cout << perms[min_perm][colors[i]] + 1 << " ";
    }
    cout << endl;
    return 0;
}
