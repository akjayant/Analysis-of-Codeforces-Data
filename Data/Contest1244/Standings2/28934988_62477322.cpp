#include <bits\stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> E[maxn];
int c[maxn][3];
int a[maxn];
int res[maxn];
void dfs(int now, int f1, int f2)
{
    a[now] = 6 - a[f1] - a[f2];
    for (auto it : E[now]) {
        if (it == f2)
            continue;
        dfs(it, f2, now);
    }
}
typedef long long LL;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i][0]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i][1]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i][2]);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    int p;
    for (int i = 1; i <= n; i++) {
        if (E[i].size() > 2) {
            printf("-1\n");
            return 0;
        } else if (E[i].size() == 1)
            p = i;
    }
    int q = E[p][0];
    long long ans = 1e18;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == j)
                continue;
            a[p] = i;
            a[q] = j;
            for (auto it : E[q]) {
                if (it == p)
                    continue;
                dfs(it, p, q);
            }
            long long sum = 0;
            for (int k = 1; k <= n; k++)
                sum += LL(c[k][a[k] - 1]);
            if (sum < ans) {
                ans = sum;
                for (int k = 1; k <= n; k++)
                    res[k] = a[k];
            }
        }
    }
    printf("%I64d\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%d ", res[i]);
    return 0;
}