#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cassert>
#include <unordered_map>

#define ll long long
#define int long long

using namespace std;

ll INF = 1e16; 
signed main() {
    int n;
    cin >> n;
    vector<vector<int>> c(3, vector<int>(n));
    for (int i = 0; i < 3; ++i) {
        for (auto &c : c[i]) {
            cin >> c;
        }
    }

    vector<int> p(n);

    vector<vector<int>> gr(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        ++p[u];
        ++p[v];
    }

    for (auto el : p) {
        if (el > 2) {
            cout << -1;
            return 0;
        }
    }
    vector<vector<int>> perms;
    vector<int> pp = {0, 1, 2};
    do {
        perms.push_back(pp);
    } while (next_permutation(pp.begin(), pp.end()));

    vector<int> used(n);
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (3, vector<ll>(3, INF)));
    vector<vector<ll>> from(n, vector<ll> (3, -1));
    vector<int> pars(n, -1);
    vector<int> colors(n);
    ll ans = 0;
    for (int j = 0; j < n; ++j) {
        int pprev = -1;
        int prev = -1;
        if (p[j] == 1 && !used[j]) {
            int i = j;
            while (1) {
                used[i] = 1;
                for (auto &perm : perms) {
                    ll cur = c[perm[2]][i];
                    if (prev != -1) {
                        cur += dp[prev][perm[1]][perm[0]];
                    }

                    if (cur < dp[i] [perm[2]] [perm[1]]) {
                        dp[i][perm[2]][perm[1]] = cur;
                        from[i][perm[2]] = perm[1];
                    }

                }
                pprev = prev;
                pars[i] = prev;
                prev = i;

                for (auto to : gr[i]) {
                    if (to != prev && to != pprev) {
                        i = to;
                    }
                }
                if (prev == i) {
                    int f = 0;
                    int s = 0;
                    ll nn = INF;
                    for (int q = 0; q < 3; ++q) {
                        for (int qq = 0; qq < 3; ++qq) {
                            if (nn > dp[i][q][qq]) {
                                nn = min(nn, dp[i][q][qq]);
                                f = q;
                                s = qq;
                            }
                        }
                    }
                    colors[i] = f;
                    while (pars[i] != -1) {
//                        int fc = from[i][f];
                        i = pars[i];
                        colors[i] = s;
                        int oth = (3 - f - s);
                        f = s;
                        s = oth;
                    }
                    ans += nn;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        cout << colors[i] + 1 << " ";
    }

}
