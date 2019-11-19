#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define int ll
#define endl '\n'
#define TIME 1.0*clock()/CLOCKS_PER_SEC

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e6 + 7;
const int M = 1e9 + 7;
const int FFTM = 998244353;

int n, m, x, y, T, c[N], c2[N], cnt = 0;
vector<int> g[N], r[N], top;

void dfs(int v){
    c[v] = 1;
    for (auto to : g[v])
        if (!c[to]) dfs(to);
    top.pb(v);
}

void dfs2(int v){
    c2[v] = 1;
    cnt++;
    for (auto to : r[v])
        if (!c2[to]) dfs2(to);
}

void solve(){
    cin >> n >> m;cnt = 0;top.clear();
    for (int i = 0; i < n; i++) g[i].clear(), r[i].clear(), c[i] = 0, c2[i] = 0;
    for (int i = 0; i < m; i++){
        cin >> x >> y;x--;y--;
        g[x].pb(y);
        r[y].pb(x);
    }
    for (int i = 0; i < n; i++) if (!c[i]) dfs(i);
    reverse(top.begin(), top.end());
    dfs2(top[0]);
    if (cnt != n){
        cout << "Yes" << endl;
        cout << n - cnt << ' ' << cnt << endl;
        for (int i = 0; i < n; i++) if (!c2[i]) cout << i + 1 << ' ';
        cout << endl;
        for (int i = 0; i < n; i++) if (c2[i]) cout << i + 1 << ' ';
        cout << endl;
    }
    else cout << "No" << endl;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("drone.in", "r", stdin);
//    freopen("drone.out", "w", stdout);
#endif
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
