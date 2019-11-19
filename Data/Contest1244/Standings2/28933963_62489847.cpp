#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 100005
#define M 100005
#define INF 0x3f3f3f3f
#define mk(x) (1<<x) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') fg = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }

/** graph **/
int tot = 0;
int head[N], nxt[M<<1], ver[M<<1];
int deg[N];
void addEdge(int u, int v) {
    nxt[++tot] = head[u], ver[tot] = v, head[u] = tot;
    deg[u]++;
}

int n;
ll c[N][4];

void input() {
    read(n);
    memset(head, -1, sizeof head);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            read(c[j][i]);
        }
    }
    for (int i = 1; i <= n-1; i++) {
        int u, v;
        read(u, v);
        addEdge(u, v);
        addEdge(v, u);
    }
}

bool vis[N];
vector <int> nodes;
void dfs(int u) {
    vis[u] = true;
    nodes.push_back(u);
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = ver[i];
        if (vis[v])
            continue;
        dfs(v);
    }
}
ll f[N][4][4];//i-th node choose j-th color's and previous node is k-th color tot cost
int pre[N][4][4];
int ans[N];
ll dp() {
    ll res = 1e18;
    vector <int> vs;
    for (int i = 1; i <= 3; i++)
        vs.push_back(i);
    do {
        ll tmpres = 0;
        for (int i = 0; i < sz(nodes); i++) {
            int u = nodes[i];
            tmpres += c[u][vs[i%3]];
        }
        if (res > tmpres) {
            res = tmpres;
            for (int i = 0; i < sz(nodes); i++) {
                int u = nodes[i];
                ans[u] = vs[i%3];
            }
        }
    }while (next_permutation(vs.begin(), vs.end()));
    return res;
}
int main()
{
    input();
    bool ok = true;
    int st = 1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            st = i;
        }
        if (deg[i] >= 3) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        puts("-1");
    }
    else {
        memset(vis, false, sizeof vis);
        dfs(st);
        ll res = dp();
        cout << res << endl;
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }

    return 0;
}
