
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e5;
int n, rt, sr, st, c[3][nsz + 5], res[nsz + 5], fnl[nsz + 5];
num sum, ans = -1;
vector<int> g[nsz + 5];

void dfs(int u = st, int p = sr, int pp = rt) {
    loop (c, 3) {
        if (c == res[p] || c == res[pp])  continue;
        res[u] = c;
    }
    loop (i, g[u].size()) {
        int v = g[u][i];
        if (v == p)  continue;
        dfs(v, u, p);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    loop (c, 3) {
        cont (u, n) {
            cin >> ::c[c][u];
        }
    }
    cont (i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cont (u, n) {
        if (g[u].size() > 2) {
            cout << -1 << ln;
            return 0;
        }
        if (g[u].size() == 1) {
            rt = u;
        }
    }
    sr = g[rt][0];
    st = g[sr][0] != rt ? g[sr][0] : g[sr][1];
    loop (c1, 3) {
        loop (c2, 3) {
            if (c1 == c2)  continue;
            sum = 0;
            res[rt] = c1;
            res[sr] = c2;
            dfs();
            cont (u, n) {
                sum += c[res[u]][u];
            }
            if (ans == -1 || sum < ans) {
                ans = sum;
                cont (u, n) {
                    fnl[u] = res[u];
                }
            }
        }
    }
    cout << ans << ln;
    cont (u, n) {
        cout << fnl[u] + 1 << ' ';
    }
    cout << ln;
}
