#include <cstdio>
#include <vector>

using namespace std;
using LL=long long;

int n, col[3][100005], a, b, c, res[100005];
LL ans = 1E18, tmp;
vector<int> E[100005];

inline bool check(int x, int y, int z) {
    return x != y && y != z && x != z;
}

LL dfs(int u, int fa, int x, int y, int z) {
    tmp += col[x][u];
    for (int &j:E[u])
        if (j != fa)
            dfs(j, u, y, z, x);
}

void tag(int u, int fa, int x, int y, int z) {
    res[u] = x;
    for (int &j:E[u])
        if (j != fa)
            tag(j, u, y, z, x);
}

int main() {
    scanf("%d", &n);
    for (int j = 0; j < 3; j++)
        for (int i = 1; i <= n; i++)
            scanf("%d", &col[j][i]);
    for (int i = 1, u, v; i < n; i++)
        scanf("%d%d", &u, &v), E[u].push_back(v), E[v].push_back(u);
    int s;
    for (int i = 1; i <= n; i++) {
        if (E[i].size() >= 3) {
            printf("-1");
            return 0;
        }
        if(E[i].size()==1)
            s=i;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (check(i, j, k)) {
                    tmp = 0;
                    dfs(s, 0, i, j, k);
                    if (tmp < ans)
                        a = i, b = j, c = k, ans = tmp;
                }
    printf("%lld\n", ans);
    tag(s, 0, a, b, c);
    for (int i = 1; i <= n; i++)
        printf("%d ", res[i] + 1);
    return 0;
}