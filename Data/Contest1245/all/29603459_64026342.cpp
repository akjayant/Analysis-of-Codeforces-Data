#include <bits/stdc++.h>
#define N 2020
#define M 5000040

using namespace std;

int n, m, cnt;
int k[M], x[M], y[M], root[M];
long long res;
vector < int > ans;
vector < pair <int, int> > ans1;

struct data {
    int u, v;
    long long w;
} a[M];

bool cmp(data x, data y) {
    return x.w < y.w;
}

int get_root(int u) {
    return root[u] ? root[u] = get_root(root[u]) : u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ///freopen("main.inp", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) {
        int w; cin >> w;
        a[++m] = {i, n + 1, w};
    }
    for (int i = 1; i <= n; i++) cin >> k[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            long long cost = 1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            a[++m] = {i, j, cost};
        }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v;
        int p = get_root(u), q = get_root(a[i].v);
        if ( p != q ) {
            if ( v < u ) swap(u, v);
            if ( v == n + 1 ) ans.push_back(u);
            else ans1.push_back(make_pair(u, v));
            root[p] = q;
            res += a[i].w;
            cnt ++;
        }
        if ( cnt == n ) break;
    }
    cout << res << "\n" << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n" << ans1.size() << "\n";
    for (int i = 0; i < ans1.size(); i++)
        cout << ans1[i].first << " " << ans1[i].second << "\n";

    return 0;
}
