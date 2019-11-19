#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

int n;
ll ans;
vector <int> step;
vector <int> color, color_ans;
vector <vector <int> > cost, g;

void dfs(int v, int from, int now, ll &res) {
    res += cost[step[now]][v];
    color[v] = step[now];
    now = (now + 1) % 3;

    for(auto to : g[v]) {
        if (to != from) {
            dfs(to, v, now, res);
        }
    }
}

void solve(int start, int x, int y, int z) {
    step = {x, y, z};

    ll res = 0;
    dfs(start, -1, 0, res);

    if (res < ans || ans == 0) {
        ans = res;
        color_ans = color;
    }
}

void dfs1(int v, int from, int &res) {
    int leaf = 1;
    for(auto to : g[v]) {
        if (to != from) {
            dfs1(to, v, res);
            leaf = 0;
        }
    }

    if (!leaf) {
        res = v;
    }
}

int find_start() {
    int res = 0;
    dfs1(0, -1, res);

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    cost.resize(3, vector <int> (n));
    for(int i = 0; i < n; i++) {
        cin >> cost[0][i];
    }

    for(int i = 0; i < n; i++) {
        cin >> cost[1][i];
    }

    for(int i = 0; i < n; i++) {
        cin >> cost[2][i];
    }

    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int start = -1;
    for(int i = 0; i < n; i++) {
        if (g[i].size() > 2) {
            return cout << "-1\n", 0;
        }

        if (g[i].size() == 1) {
            start = i;
        }
    }

    color.resize(n);
    step.resize(3);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int q = 0; q < 3; q++) {
                if (i != j && i != q && j != q) {
                    solve(start, i, j, q);
                }
            }
        }
    }


    cout << ans << "\n";
    for(auto i : color_ans) {
        cout << ++i << " ";
    }
    return 0;
}
/*

*/
