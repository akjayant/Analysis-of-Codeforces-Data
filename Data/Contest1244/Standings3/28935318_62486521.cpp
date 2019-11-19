#include <bits/stdc++.h>
using namespace std;

const int N = 100800;
int c[N][3];
int d[N], v[N];
vector<int> G[N];
int n, x, y, st;
int color[][3] = {
    {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}
};

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j) scanf("%d", &c[j][i]);

    for (int i = 0; i < n-1; ++i) {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        d[x]++;
        d[y]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (d[i] > 2) { printf("-1\n"); return 0; }
        if (d[i] == 1) st = i;
    }

    long long s, ans = 1e18;
    int mk = -1;
    for (int i = 0; i < 6; ++i) {
        s = 0;
        memset(v, 0, sizeof v);
        int cur = st;
        for (int j = 0; j < n; ++j) {
            v[cur] = 1;
            s += c[cur][color[i][j%3]];
            for (int k = 0; k < G[cur].size(); ++k) {
                if (!v[G[cur][k]]) { cur = G[cur][k]; break; }
            }
        }
        if (s < ans) { ans = s; mk = i; }
    }

    cout << ans << endl;
    memset(v, 0, sizeof v);
    int cur = st;
    for (int j = 0; j < n; ++j) {
        v[cur] = 1;
        d[cur] = color[mk][j%3] +1;
        for (int k = 0; k < G[cur].size(); ++k) {
            if (!v[G[cur][k]]) { cur = G[cur][k]; break; }
        }
    }
    for (int j = 1; j <= n; ++j) cout << d[j] << " ";
    cout << endl;
    return 0;
}

