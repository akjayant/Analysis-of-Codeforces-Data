#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10;
int c[N][3], d[N], a[N], per[3], pp[3];
vector <int> g[N], vec;

void dfs(int v, int p = 0)
{
    vec.push_back(v);
    for (int u : g[v]) if (u != p) dfs(u, v);
    return ;
}

int32_t main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> c[i][0];
    for (int i = 1; i <= n; i ++) cin >> c[i][1];
    for (int i = 1; i <= n; i ++) cin >> c[i][2];
    for (int i = 0; i < n - 1; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u]++, d[v]++;
    }
    for (int i = 1; i <= n; i ++) if (d[i] > 2) return cout << -1, 0;
    for (int i = 1; i <= n; i ++) if (d[i] == 1) {dfs(i); break;}
    for (int i = 0; i < 3; i ++) per[i] = i;
    int ans = 1e18;
    do {
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += c[vec[i]][per[i % 3]];
        }
        if (sum < ans) {
            ans = sum;
            for (int j = 0; j < 3; j ++) pp[j] = per[j];
        }
    } while(next_permutation(per, per + 3));
    for (int i = 0; i < n; i ++) a[vec[i]] = pp[i % 3];
    cout << ans << "\n";
    for (int i = 1; i <= n; i ++) cout << a[i] + 1 << " ";
}
