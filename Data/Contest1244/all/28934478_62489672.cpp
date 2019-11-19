#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <ctime>
#include <string>
 
using namespace std;

#define int long long

vector<vector<int>> gr;
vector<int> par;
vector<bool> used;
vector<vector<int>> cost;

vector<vector<vector<int>>> dp;
vector<vector<vector<int>>> anc;

const int inf = 1'000'000'000LL * 1'000'000'000LL + 10LL;

void solve(vector<int> base) {
    int n = base.size();
    dp.assign(3, vector<vector<int>>(3, vector<int>(n, inf)));
    anc.assign(3, vector<vector<int>>(3, vector<int>(n, -1)));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j].back() = cost[base.back()][i];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            for (int u = 0; u < 3; u++) {
                for (int k = 0; k < 3; k++) {
                    if (j == u || j == k || u == k) {
                        continue;
                    }
                    if (dp[j][u][i] > dp[u][k][i + 1] + cost[base[i]][j]) {
                        dp[j][u][i] = dp[u][k][i + 1] + cost[base[i]][j];
                        anc[j][u][i] = k;
                    }
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cost.resize(n, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[j][i];
        }
    }
    gr.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (gr[i].size() >= 3) {
            cout << "-1\n";
            return 0;
        }
    }
    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (gr[i].size() == 1) {
            ind = i;
        }
    }
    used.resize(n, false);
    par.resize(n, -1);
    vector<int> path;
    int pos = gr[ind][0];
    int par = ind;
    while (gr[pos].size() != 1) {
        path.push_back(pos);
        if (gr[pos][0] != par) {
            par = pos;
            pos = gr[pos][0];
        } else {
            par = pos;
            pos = gr[pos][1];
        }
    }
    path.push_back(pos);
 
    solve(path);
    int a = -1, b = -1, s = -1;
    int res = inf;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int u = 0; u < 3; u++) {
                if (i == j || i == u || j == u) {
                    continue;
                }
                if (res > dp[j][u][0] + cost[ind][i]) {
                    res = dp[j][u][0] + cost[ind][i];
                    s = i;
                    a = j;
                    b = u;
                }
            }
        }
    }
    cout << res << '\n';
    vector<int> ans(n);
    ans[ind] = s + 1;
    for (int i = 0; i < path.size(); i++) {
        ans[path[i]] = a + 1;
        int next = anc[a][b][i];
        a = b;
        b = next;
    }
    for (int i : ans) {
        cout << i << ' ';
    }
}