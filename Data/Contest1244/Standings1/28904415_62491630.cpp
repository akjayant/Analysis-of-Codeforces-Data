#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> e[N];
int a[3][N], cnt, id[N], res[N];
bool tr[N];

void dfs(int u)
{
    tr[id[cnt++] = u] = true;
    for (int v: e[u])
        if (!tr[v]) dfs(v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	int n, s;
    cin >> n;
	for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (e[i].size() > 2)
        {
            cout << -1;
            return 0;
        }
        if (e[i].size() == 1) s = i;
    }
    dfs(s);
    long long ans = 1e15, cur;
    for (int k = 0; k < 3; ++k)
    {
        cur = 0;
        for (int j = 0, i = k; j < n; ++j, i = (i + 1) % 3) cur += a[i][id[j]];
        if (cur > ans) continue;
        ans = cur;
        res[0] = k;
    }
    for (int k = 0; k < 3; ++k)
    {
        cur = 0;
        for (int j = 0, i = k; j < n; ++j, i = (i + 1) % 3) cur += a[2 - i][id[j]];
        if (cur > ans) continue;
        ans = cur;
        res[0] = -k - 1;
    }
    cout << ans << '\n';
    if (res[0] >= 0)
        for (int i = 0, k = res[0]; i < n; ++i, k = (k + 1) % 3)
            res[id[i]] = k + 1;
    else
        for (int i = 0, k = -res[0] - 1; i < n; ++i, k = (k + 1) % 3)
            res[id[i]] = 3 - k;
    for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
    return 0;
}
