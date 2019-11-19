


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 100000 + 5;

int n, c[3][MaxN], p[MaxN], r[MaxN];
vector<int> adj[MaxN];

bool solve() {
    int v = 0;
    for (int k = 1; k <= n; ++ k) {
        if (adj[k].size() > 2) return false;
        if (adj[k].size() == 1) v = k;
    }
    p[0] = v;
    for (int k = 1; k < n; ++ k) {
        int cur = p[k - 1];
        for (int t = 0; t < adj[cur].size(); ++ t)
            if (cur == v || adj[cur][t] != p[k - 2]) p[k] = adj[cur][t];
    }
    
    long long minc = 1LL << 50, clr[3] = {-1, -1, -1}, q[3];
    for (q[0] = 0; q[0] < 3; ++ q[0])
        for (q[1] = 0; q[1] < 3; ++ q[1]) {
            if (q[0] == q[1]) continue;
            q[2] = 3 - q[0] - q[1];
            long long cost = 0;
            for (int k = 0; k < n; ++ k)
                cost += c[q[k % 3]][p[k]];
            if (cost < minc) {
                minc = cost;
                clr[0] = q[0];
                clr[1] = q[1];
            }
        }
    cout << minc << endl;
    clr[2] = 3 - clr[0] - clr[1];
    for (int k = 0; k < n; ++ k)
        r[p[k]] = k % 3;
    for (int k = 1; k < n; ++ k)
        printf("%d ", clr[r[k]] + 1);
    printf("%d\n", clr[r[n]] + 1);
    
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++ i)
        for (int j = 1; j <= n; ++ j)
            scanf("%d", &c[i][j]);
    for (int k = 0; k <= n; ++ k)
        adj[k].clear();
    for (int k = 1; k < n; ++ k) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (!solve()) puts("-1");
    
    return 0;
}
