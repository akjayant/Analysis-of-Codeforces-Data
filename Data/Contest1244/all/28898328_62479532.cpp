#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const ll INF = 1e17;

vector <int> g[N];
ll c[N][3];
ll dp[N][3][3];
ll ans = 0, ans1 = -1, ans2 = -1;
int b[N];

void dfs(int v, int p = -1) {
    for (auto to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
    ans = INF;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            dp[v][i][j] = c[v][i];
            for (auto to : g[v]) {
                if (to == p) continue;
                dp[v][i][j] += dp[to][j][3 - i - j];
            }
            if (dp[v][i][j] < ans) {
                ans = dp[v][i][j];
                ans1 = i;
                ans2 = j;
            }
        }
    }
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i][2];
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        g[x].pb(y);
        g[y].pb(x);
    }
    int st = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 2) {
            cout << "-1" << endl;
            return 0;
        }
        if (g[i].size() == 1) st = i;
    }
    dfs(st);
    cout << ans << endl;
    queue <pair <int, pair <int, int> > > q;
    q.push({st, {ans1 + 1, ans2 + 1}});
    while (!q.empty()) {
        int v = q.front().F, c1 = q.front().S.F, c2 = q.front().S.S;
        q.pop();
        b[v] = c1;
        for (auto to : g[v]) {
            if (b[to] != 0) continue;
            q.push({to, {c2, 6 - c1 - c2}});
        }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}
