#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

const int maxn = 2002;
const ll inf = 1e18 + 7;

int p[maxn];
int rnk[maxn];
ll x[maxn], y[maxn], c[maxn], k[maxn];
set <int> g[maxn];
bool used[maxn];

int find_set (int v)
{
	if (v == p[v])
		return v;
	return p[v] = find_set (p[v]);
}

void union_sets (int a, int b)
{
    if (rnk[a] < rnk[b])
        swap (a, b);
    p[b] = a;
    rnk[a] += rnk[b];
}

ll mn;
int vert;
bool f;

void dfs(int v, int pr)
{
    if (used[v])
    {
        f = true;
    }
    if (c[v] < mn)
    {
        mn = c[v];
        vert = v;
    }
    for(int to : g[v])
        if (to != pr) dfs(to, v);
}

ll ans = 0;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
        p[i] = i;
    }
    {
        ll minimum = inf;
        int v;
        for(int i = 0; i < n; ++i)
        {
            cin >> c[i];
            if (c[i] < minimum)
            {
                minimum = c[i];
                v = i;
            }
        }
        ans += minimum;
        used[v] = true;
    }
    for(int i = 0; i < n; ++i)
        cin >> k[i];


    vector <pair <ll, pair <int, int>>> e;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < i; ++j)
    {
        ll kek = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
        e.pb({kek, {i, j}});
    }

    sort(e.begin(), e.end());
    vector <pair <ll, pair <int, int>>> edges;
    for(auto kek : e)
    {
        ll val = kek.F;
        int vv = kek.S.F;
        int uu = kek.S.S;
        int v = find_set(vv);
        int u = find_set(uu);
        if (v == u) continue;
        ans += val;
        union_sets(v, u);
        edges.pb({val, {vv, uu}});
        g[vv].insert(uu);
        g[uu].insert(vv);
    }
    sort(edges.rbegin(), edges.rend());
    for(auto kek : edges)
    {
        ll val = kek.F;
        int v = kek.S.F;
        int u = kek.S.S;
        g[v].erase(u);
        g[u].erase(v);
        mn = inf;
        vert = -1;
        f = false;
        dfs(v, v);
        if (!f)
        {
            if (mn <= val) //?
            {
                ans = ans - val + mn;
                used[vert] = true;
            }
            else
            {
                g[v].insert(u);
                g[u].insert(v);
            }
            continue;
        }

        mn = inf;
        vert = -1;
        f = false;
        dfs(u, u);
        if (mn <= val) //?
        {
            ans = ans - val + mn;
            used[vert] = true;
        }
        else
        {
            g[v].insert(u);
            g[u].insert(v);
        }
    }

    cout << ans << '\n';
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if (used[i]) ++cnt;
    cout << cnt << '\n';
    for(int i = 0; i < n; ++i)
        if (used[i]) cout << i + 1 << ' ';
    set <pair <int, int>> st;
    for(int i = 0; i < n; ++i)
        for(int j : g[i])
        {
            int v = i + 1;
            int u = j + 1;
            if (u > v) swap(u, v);
            st.insert({v, u});
        }
    cout << '\n' << int(st.size()) << '\n';
    for(pair <int, int> i : st)
        cout << i.F << ' ' << i.S << '\n';
    return 0;
}
