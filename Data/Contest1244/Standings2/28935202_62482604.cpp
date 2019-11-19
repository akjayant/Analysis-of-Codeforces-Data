#include <bits/stdc++.h>
using i64 = long long;

std::vector<std::vector<int>> g;
i64 cost[100010][3];

int main() {
    int n;
    scanf("%d", &n);
    g.resize(n);
    for (int i = 0; i < 3; i++) for (int j = 0; j < n; j++) {
        i64 in;
        scanf("%lld", &in);
        cost[j][i] = in;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (std::any_of(g.begin(), g.end(), [](const auto &v) { return v.size() > 2; })) {
        printf("-1\n");
        return 0;
    }

    int s = std::find_if(g.begin(), g.end(), [](const auto &v) { return v.size() == 1; }) - g.begin();

    std::vector v { s, g[s].front() };
    while (g[v.back()].size() > 1) {
        int w = v.back();
        int t = g[w][0] + g[w][1] - v[v.size() - 2];
        v.push_back(t);
    }

    i64 ret = std::numeric_limits<i64>::max();
    std::pair<int, int> rp;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (i != j) {
        int arr[] { i, j, 3 - i - j };
        i64 c = 0;
        for (int k = 0; k < n; k++) c += cost[v[k]][arr[k % 3]];
        if (ret > c) {
            ret = c;
            rp = std::make_pair(i, j);
        }
    }

    printf("%lld\n", ret);
    int arr[] { rp.first, rp.second, 3 - rp.first - rp.second };
    std::vector<int> color(n);
    for (int i = 0; i < n; i++) color[v[i]] = arr[i % 3];
    for (int i = 0; i < n; i++) printf("%d ", color[i] + 1);
    printf("\n");

    return 0;
}
