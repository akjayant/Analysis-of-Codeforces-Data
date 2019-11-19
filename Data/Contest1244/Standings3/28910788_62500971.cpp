#include <bits/stdc++.h>
#define int long long
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

const int N = 1e5 + 228;

vector<int> g[N];
int a[3][N];
vector<int> kek;
void build(int v, int pr) {
    kek.push_back(v);
    for (auto i : g[v]) {
        if (i != pr) {
            build(i, v);
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int root = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[0][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[1][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[2][i];
    }
    for (int i = 1; i < n; i++) {
        int u, b;
        cin >> u >> b;
        g[u].push_back(b);
        g[b].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() >= 3) {
            cout << -1;
            return 0;
        }
        if (g[i].size() == 1) {
            root = i;
        }
    }
    build(root, -1);
    vector<int> cur = {0, 1, 2};
    vector<int> clr_ans(n);
    int ans = 1e18;
    do {
        int cur_ans = 0;
        vector<int> cur_clr(n);
        for (int i = 0; i < n; ++i) {
            cur_clr[i] = cur[i % 3];
            cur_ans += a[cur_clr[i]][kek[i]];
        }
        if (ans > cur_ans) {
            clr_ans = cur_clr;
            ans = cur_ans;
        }
    }while(next_permutation(all(cur)));

    cout << ans << '\n';
    vector<int> color(n + 1);
    for (int i = 0; i < n; ++i) {
        color[kek[i]] = clr_ans[i] + 1;
    }
    for ( int i = 1; i <= n; ++i) {
        cout << color[i] << " ";
    }
}