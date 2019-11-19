#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int fa[N], vis[N];
vector<int> g[N], ans;

int Sk(int x) {
    return fa[x] == x? x : fa[x] = Sk(fa[x]);
}

void Bfs(int s) {
    static queue<int> Q;
    Q.push(s), fa[s] = Sk(s + 1);
    ans.push_back(1);
    for (int x; !Q.empty(); ) {
        x = Q.front(), Q.pop();
        for (int v : g[x]) vis[v] = x;
        for (int i = Sk(1); i <= n; i = Sk(i + 1)) {
            if (vis[i] != x) fa[i] = Sk(i + 1), Q.push(i), ++ans.back();
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y), g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) fa[i] = i;
    fa[n + 1] = n + 1;
    for (int i = 1; i <= n; i = Sk(i + 1)) Bfs(i);
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size() - 1);
    return 0;
}