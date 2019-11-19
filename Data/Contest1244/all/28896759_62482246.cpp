#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define go_precise cout << fixed << setprecision(15);
mt19937 rnd;

const int N = 1e5 + 10;
int n;
vector<int> g[N];
ll c[4][N];
vector<int> path;
bool used[N];

void dfs(int v) {
    used[v] = 1;
    path.pb(v);
    for (int to : g[v]) {
        if (used[to]) continue;
        dfs(to);
    }
}

int col[7][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i=1; i<=n-1; i++) {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i=1; i<=n; i++) {
        if (g[i].size() > 2) {
            cout << -1;
            return 0;
        }
    }

    int root = -1;
    for (int i=1; i<=n; i++) {
        if (g[i].size()==1) {
            root = i;
            break;
        }
    }
    dfs(root);
    ll ans = 1e18, pos = -1, cur = 0;
    //123
    cur = 0;
    for (int i=0; i<n; i++) {
        int color;
        if (i%3==0) color = 1;
        if (i%3==1) color = 2;
        if (i%3==2) color = 3;
        col[1][path[i]] = color;
        cur += c[color][path[i]];
    }
    if (cur < ans) {
        ans = cur;
        pos = 1;
    }
    //132
    cur = 0;
    for (int i=0; i<n; i++) {
        int color=0;
        if (i%3==0) color = 1;
        if (i%3==1) color = 3;
        if (i%3==2) color = 2;
        col[2][path[i]] = color;
        cur += c[color][path[i]];
    }
    if (cur < ans) {
        ans = cur;
        pos = 2;
    }
    //213
    cur = 0;
    for (int i=0; i<n; i++) {
        int color = 0;
        if (i%3==0) color = 2;
        if (i%3==1) color = 1;
        if (i%3==2) color = 3;
        col[3][path[i]] = color;
        cur += c[color][path[i]];
    }
    if (cur < ans) {
        ans = cur;
        pos = 3;
    }
    //231
    cur = 0;
    for (int i=0; i<n; i++) {
        int color;
        if (i%3==0) color = 2;
        if (i%3==1) color = 3;
        if (i%3==2) color = 1;
        col[4][path[i]] = color;
        cur += c[color][path[i]];
    }
    if (cur < ans) {
        ans = cur;
        pos = 4;
    }
    //312
    cur = 0;
    for (int i=0; i<n; i++) {
        int color;
        if (i%3==0) color = 3;
        if (i%3==1) color = 1;
        if (i%3==2) color = 2;
        col[5][path[i]] = color;
        cur += c[color][path[i]];
    }
    if (cur < ans) {
        ans = cur;
        pos = 5;
    }
    //321
    cur = 0;
    for (int i=0; i<n; i++) {
        int color;
        if (i%3==0) color = 3;
        if (i%3==1) color = 2;
        if (i%3==2) color = 1;
        col[6][path[i]] = color;
        cur += c[color][path[i]];
    }
    if (cur < ans) {
        ans = cur;
        pos = 6;
    }

    cout << ans << "\n";
    for (int i=1; i<=n; i++) cout << col[pos][i] << ' ' ;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
