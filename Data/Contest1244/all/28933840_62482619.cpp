#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;
vector<int> g[MAXN];
int cur_color[MAXN];
long long cur_ans;
int c[MAXN][3];

void dfs(int v, int pre_1, int pre_2) {
    //cout << v << endl;
    cur_color[v] = 3 - cur_color[pre_1] - cur_color[pre_2];
    cur_ans += (long long)c[v][cur_color[v]];
    for (int i = 0; i < g[v].size(); ++i) {
        if (cur_color[g[v][i]] == -1) {
            dfs(g[v][i], pre_2, v);
        }
    }
}

main() {
    cout.precision(20);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i][0];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i][1];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i][2];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) start = i;
        if (g[i].size() >= 3) {
            cout << -1;
            return 0;
        }
    }
    int v1 = start;
    int v2 = g[v1][0];
    long long answer = 1e18;
    int a1 = 0, a2 = 1;
    int start_2 = v2;
    if (g[v2][0] == v1) start_2 = g[v2][1];
    else start_2 = g[v2][0];
    for (int c1 = 0; c1 < 3; ++c1) {
        for (int c2 = 0; c2 < 3; ++c2) {
            if (c1 == c2) continue;
            for (int i = 0; i < n; ++i) cur_color[i] = -1;
            cur_ans = c[v1][c1] + c[v2][c2];
            cur_color[v1] = c1;
            cur_color[v2] = c2;
            dfs(start_2, v1, v2);
            if (cur_ans < answer) {
                answer = cur_ans;
                a1 = c1;
                a2 = c2;
            }
        }
    }
    for (int i = 0; i < n; ++i) cur_color[i] = -1;
    cur_ans = c[v1][a1] + c[v2][a2];
    cur_color[v1] = a1;
    cur_color[v2] = a2;
    dfs(start_2, v1, v2);
    cout << cur_ans << endl;
    for (int i = 0; i < n; ++i) cout << cur_color[i] + 1 << ' ';
    return 0;
}