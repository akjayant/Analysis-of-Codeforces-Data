#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e5 + 5;
const long long INF = 1e18 + 5;
const int base = 1e4;

typedef long long ll;

const ll mod = 1e9 + 7;

#define int ll

int n;
int c[5][N], color[N];
vector <int> g[N];
int dp[5][5][N];
pair <int, int> p[4][4][N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[1][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[2][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[3][i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 2) {
            cout << "-1";
            return 0;
        }
        if (g[i].size() == 1) {
            st = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int c1 = 1; c1 <= 3; c1++) {
            for (int c2 = 1; c2 <= 3; c2++) {
                dp[c1][c2][i] = INF;
            }
        }
    }
    int prev = 0;
    for (int i = st; ; ) {
        for (int c1 = 1; c1 <= 3; c1++) {
            for (int c2 = 1; c2 <= 3; c2++) {
                if (c1 == c2)
                    continue;
                for (int c3 = 1; c3 <= 3; c3++) {
                    if (c1 == c3 || c3 == c2)
                        continue;
                    if (dp[c1][c2][i] > dp[c2][c3][prev] + c[c1][i]) {
                        dp[c1][c2][i] = dp[c2][c3][prev] + c[c1][i];
                        p[c1][c2][i] = {c3, prev};
                    }
                }
            }
        }
        int pr = prev;
        prev = i;
        for (int to : g[i]) {
            if (to != pr)
                i = to;
        }
        if (i == prev)
            break;
    }
    int ans = INF, cr1 = 0, cr2 = 0;
    for (int c1 = 1; c1 <= 3; c1++) {
        for (int c2 = 1; c2 <= 3; c2++) {
            if (ans > dp[c1][c2][prev]) {
                ans = dp[c1][c2][prev];
                cr1 = c1;
                cr2 = c2;
            }
        }
    }
    cout << ans << "\n";
    while (prev != 0) {
        color[prev] = cr1;
        int pr = p[cr1][cr2][prev].second,
        cr3 = p[cr1][cr2][prev].first;
        cr1 = cr2;
        cr2 = cr3;
        prev = pr;
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
}
