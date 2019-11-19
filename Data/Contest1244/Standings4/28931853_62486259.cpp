#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans = 0;
vector < vector <int> > c(3);


int dfs(vector < vector <int> > &g, int v, int c_c, int c_from, int from) {
    ans += c[c_c][v];
    for (int to : g[v]) {
        if (to != from) {
            int c_t = 0;
            if (c_c == 0) {
                if (c_from == 2) c_t = 1;
                else c_t = 2;
            }
            if (c_from == 0) {
                if (c_c == 1) c_t = 2;
                else c_t = 1;
            }
            dfs(g, to, c_t, c_c, v);
        }
    }
}

vector <int> aans;

int dfs1(vector < vector <int> > &g, int v, int c_c, int c_from, int from) {
    aans[v] = c_c;
    for (int to : g[v]) {
        if (to != from) {
            int c_t = 0;
            if (c_c == 0) {
                if (c_from == 2) c_t = 1;
                else c_t = 2;
            }
            if (c_from == 0) {
                if (c_c == 1) c_t = 2;
                else c_t = 1;
            }
            dfs1(g, to, c_t, c_c, v);
        }
    }
}

main() {
    int n;
    cin >> n;
    c[0].resize(n);
    c[1].resize(n);
    c[2].resize(n);
    for (int i = 0; i < n; i++) cin >> c[0][i];
    for (int i = 0; i < n; i++) cin >> c[1][i];
    for (int i = 0; i < n; i++) cin >> c[2][i];
    vector < vector <int> > g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        if (g[a - 1].size() > 2 || g[b - 1].size() > 2) {
            cout << -1;
            return 0;
        }
    }
    int st = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) st = i;
    }
    int ans_mn = 0, ans_c1 = 0, ans_c2 = 1;
    ans = c[0][st];
    dfs(g, g[st][0], 1, 0, st);
    ans_mn = ans;
    ans = c[0][st];
    dfs(g, g[st][0], 2, 0, st);
    if (ans < ans_mn) {
        ans_mn = ans;
        ans_c1 = 0, ans_c2 = 2;
    }
    ans = c[1][st];
    dfs(g, g[st][0], 0, 1, st);
    if (ans < ans_mn) {
        ans_mn = ans;
        ans_c1 = 1, ans_c2 = 0;
    }
    ans = c[1][st];
    dfs(g, g[st][0], 2, 1, st);
    if (ans < ans_mn) {
        ans_mn = ans;
        ans_c1 = 1, ans_c2 = 2;
    }
    ans = c[2][st];
    dfs(g, g[st][0], 0, 2, st);
    if (ans < ans_mn) {
        ans_mn = ans;
        ans_c1 = 2, ans_c2 = 0;
    }
    ans = c[2][st];
    dfs(g, g[st][0], 1, 2, st);
    if (ans < ans_mn) {
        ans_mn = ans;
        ans_c1 = 2, ans_c2 = 1;
    }
    aans.resize(n);
    aans[st] = ans_c1;
    dfs1(g, g[st][0], ans_c2, ans_c1, st);
    cout << ans_mn << '\n';
    for (int i : aans) {
        cout << i + 1 << ' ';
    }
}
