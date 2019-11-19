#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

typedef long long LL;
typedef pair <LL, LL> PLL;

const LL maxn = 100010;
const LL mod = 1000000007;
const LL inf = 2000000000;
const LL inf64 = inf*inf;

LL cost[3][maxn], seq[] = {0, 1, 2}, res[maxn];
bool vis[maxn];
vector <LL> graph[maxn];


LL dfs(LL u, LL cnt) {
    LL ans = cost[seq[cnt%3]][u];
    res[u] = seq[cnt%3] + 1;
    vis[u] = true;

    for (auto v : graph[u]) {
        if (not vis[v]) ans += dfs(v, cnt+1);
    }

    return ans;
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL n, u, v;
    cin >> n;

    for (LL i = 0; i < 3; i++)
        for (LL j = 1; j <= n; j++)
            cin >> cost[i][j];

    for (LL i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    LL root = -1;
    for (LL i = 1; i <= n; i++) {
        if (graph[i].size() == 1) root = i;
        else if (graph[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    LL ans = inf64;
    do {
        memset(vis, false, sizeof vis);
        ans = min(ans, dfs(root, 0));
    } while (next_permutation(seq, seq+3));

    cout << ans << endl;
    sort(seq, seq+3);
    do {
        memset(vis, false, sizeof vis);
        if (dfs(root, 0) == ans) {
            for (LL i = 1; i <= n; i++)
                cout << res[i] << " ";
            return 0;
        }
    } while (next_permutation(seq, seq+3));


    return 0;
}
