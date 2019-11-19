#include <bits/stdc++.h>
#define N ((int)1e5+10)
#define MD ((int)1e9+7)

using namespace std;

int c[6][N], n, b[9][N];
int d[10][10];

vector<int> g[N];

long long x[9];

int idx = 0;
long long ans = 1e18;

long long dfs(int x, int p, int v) {
    long long res = c[d[idx][v]][x];
    b[idx][x] = d[idx][v];
    for (int i = 0; i < g[x].size(); i++) {
        if (g[x][i] == p)
            continue;
        res += dfs(g[x][i], x, (v + 1) % 3);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int j = 1; j <= 3; j++)
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[j][i]);
        }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    int l = -1;

    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            l = i;
            cnt++;
        }
    }
    if (cnt > 2) {
        printf("-1\n");
        return 0;
    }

    int mv[6][3] = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
    };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            d[i][j] = mv[i][j];
        }
    }

    int ansIdx = -1;
    for (int i = 0; i < 6; i++) {
        long long tmp = dfs(l, -1, 0);
        if (tmp < ans) {
            ans = tmp;
            ansIdx = i;
        }
        idx++;
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d", b[ansIdx][i]);
        if (i == n) {
            printf("\n");
        } else {
            printf(" ");
        }
    }




    return 0;
}
