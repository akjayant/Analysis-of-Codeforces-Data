#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using namespace std;

const int inf = 1e18;
const double eps = 1e-6;
const int maxn = 1e5 + 1;

int c[maxn][3];
vector<int> g[maxn];

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> c[i][0];
    for (int i = 0; i < n; ++i) cin >> c[i][1];
    for (int i = 0; i < n; ++i) cin >> c[i][2];
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int s = -1;
    for (int i = 0; i < n; ++i)
    {
        if (sz(g[i]) == 1) s = i;
        if (sz(g[i]) > 2)
        {
            cout << -1;
            return 0;
        }
    }

    vector<int> p;
    p.pb(s);
    int pr = -1;
    while (sz(p) < n)
    {
        for (int u : g[s])
        {
            if (u == pr) continue;
            p.pb(u);
        }
        pr = s;
        s = p.back();
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3, inf)));
    vector<vector<vector<pair<int, int>>>> fr(n, vector<vector<pair<int, int>>>(3, vector<pair<int, int>>(3, {-1, -1})));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dp[1][i][j] = c[p[0]][i] + c[p[1]][j];
        }
    }
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                for (int h = 0; h < 3; ++h)
                {
                    if (j == k || j == h || k == h) continue;
                    int val = dp[i - 1][h][k] + c[p[i]][j];
                    if (val < dp[i][k][j])
                    {
                        dp[i][k][j] = val;
                        fr[i][k][j] = {h, k};
                    }
                }
            }
        }
    }
    vector<int> ans(n, -1);
    int res = inf, cx = -1, cy = -1;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (dp[n - 1][i][j] < res)
            {
                res = dp[n - 1][i][j];
                cx = i;
                cy = j;
            }
        }
    }
    int pos = n - 1;
    while (pos >= 1)
    {
        ans[p[pos]] = cy;
        ans[p[pos - 1]] = cx;
        tie(cx, cy) = fr[pos][cx][cy];
        --pos;
    }
    cout << res << "\n";
    for (int x : ans) cout << x + 1 << " ";
    return 0;
}