#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int a[N][4], b[N], c[N];
vector <int> adj[N];
int idx = 1;

void dfs(int u, int p){
    b[idx] = u;
    idx++;
    for (auto v: adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int j = 1; j <= 3; j++) {
        for (int i = 1; i <= n; i++) cin >> a[i][j];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 2) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            dfs(i, i);
            break;
        }
    }
    int ans = 1000000000000000000ll, t;
    vector <int> tans, vans;
    t = 0ll;
    tans = {1, 2, 3};
    for (int i = 1; i <= n; i++) t += a[b[i]][tans[i % 3]];
    if (ans > t){
        ans = t;
        vans = tans;
    }
    t = 0ll;
    tans = {1, 3, 2};
    for (int i = 1; i <= n; i++) t += a[b[i]][tans[i % 3]];
    if (ans > t){
        ans = t;
        vans = tans;
    }
    t = 0ll;
    tans = {2, 1, 3};
    for (int i = 1; i <= n; i++) t += a[b[i]][tans[i % 3]];
    if (ans > t){
        ans = t;
        vans = tans;
    }
    t = 0ll;
    tans = {2, 3, 1};
    for (int i = 1; i <= n; i++) t += a[b[i]][tans[i % 3]];
    if (ans > t){
        ans = t;
        vans = tans;
    }
    t = 0ll;
    tans = {3, 1, 2};
    for (int i = 1; i <= n; i++) t += a[b[i]][tans[i % 3]];
    if (ans > t){
        ans = t;
        vans = tans;
    }
    t = 0ll;
    tans = {3, 2, 1};
    for (int i = 1; i <= n; i++) t += a[b[i]][tans[i % 3]];
    if (ans > t){
        ans = t;
        vans = tans;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        c[b[i]] = vans[i % 3];
    }
    for (int i = 1; i <= n; i++) cout << c[i] << " ";
}