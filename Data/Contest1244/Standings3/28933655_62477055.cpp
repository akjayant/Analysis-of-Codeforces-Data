#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int s; // start of line
int c[3][100100];
int ans[100100];
int p[100100];
int np = 0;
int e[100100];
vector<int> gr[100100];
ll dp[100100][3];

bool bad2() {
    for (int i = 0; i < n; i++) {
        // printf("%d ", e[i]);
        if (e[i] > 2)
            return true;
        else if (e[i] == 1)
            s = i;
    }

    return false;
}

void dfs(int v, int par=-1) {
    p[np++] = v;

    for (auto u: gr[v]) {
        if (u == par)
            continue;
        dfs(u, v);
    }
}

int main() {
    scanf("%d", &n);

    for (int j = 0; j < 3; j++)
    for (int i = 0; i < n; i++)
        scanf("%d", c[j]+i);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        u--;
        v--;

        e[u]++;
        e[v]++;

        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    if (bad2()) {
        printf("-1\n");
        return 0; 
    }

    dfs(s);

    assert (np == n);

    int perm[3] = {0, 1, 2};
    ll mincost = 1000000000LL * 100100LL;
    do {
        ll cost = 0;
        for (int i = 0; i < n; i++)
            cost += c[ perm[i%3] ][ p[i] ];

        if (mincost > cost) {
            mincost = cost;
            for (int i = 0; i < n; i++)
                ans[ p[i] ] = perm[i%3];
        }
    } while (next_permutation(perm, perm+3));

    printf("%I64d\n", mincost);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]+1);


    return 0;
}
