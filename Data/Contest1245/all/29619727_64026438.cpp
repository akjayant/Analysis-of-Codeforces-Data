#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

struct connect
{
    int u, v;
    long long w;
} c[N * N];

bool operator< (connect i, connect j) {return i.w < j.w;}

int x[N], y[N], K[N], par[N], C[N], U[N], V[N];

int root(int k)
{
    return par[k] < 0 ? k : (par[k] = root(par[k]));
}

bool _merge(int u, int v)
{
    if ((u = root(u)) == (v = root(v))) return false;
    if (par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i)
    {
        cin >> c[cnt].w;
        c[cnt++].v = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> K[i];
        for (int j = 1; j < i; ++j)
        {
            c[cnt].u = j;
            c[cnt].v = i;
            c[cnt++].w = 1LL * (K[i] + K[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    }
    sort(c, c + cnt);
    memset(par, -1, sizeof(par));
    long long ans = 0;
    int p = 0, q = 0;
    for (int i = 0; i < cnt; ++i)
        if (_merge(c[i].u, c[i].v))
        {
            ans += c[i].w;
            if (!c[i].u)
            {
                C[p++] = c[i].v;
                continue;
            }
            U[q] = c[i].u;
            V[q++] = c[i].v;
        }
    cout << ans << '\n' << p << '\n';
    for (int i = 0; i < p; ++i) cout << C[i] << ' ';
    cout << '\n' << q << '\n';
    for (int i = 0; i < q; ++i)
        cout << U[i] << ' ' << V[i] << '\n';
    return 0;
}
