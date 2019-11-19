#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll x[2020], y[2020];
ll c[2020];
ll k[2020];
struct item
{
    ll cst;
    int type;
    int a, b;
    bool operator <(const item &it2) const
    {
        if (cst < it2.cst) return 1;
        if (cst > it2.cst) return 0;
        return type < it2.type;
    }
};
vector < item> items, ans;
ll dst(const int &i, const int &j)
{
    return (abs(x[i] - x[j]) + abs(y[i] - y[j])) * 1ll * (k[i] + k[j]);
}

int par[2020];
int light[2020];
int fi(int u)
{
    if (u == par[u])
    {
        return u;
    }
    par[u] = fi(par[u]);
    return par[u];
}
int fili(int u)
{
    int li = light[u];
    if (u == par[u])
    {
        return light[u];
    }
    par[u] = fi(par[u]);
    light[u] = li || light[par[u]];
    light[par[u]] = light[u];
    return light[u];
}
bool un(int u, int v)
{
    int li = light[v] || light[u];
    u = fi(u); v = fi(v);
    li = li || light[u] || light[v];
    if (u == v)
        return 0;
    par[u] = v;
    light[v] = li;
    light[u] = li;
    return 1;
}
vector < item> ligh, pat;
int main()
{
    iota(par, par + 2020, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    for (int i = 0; i < n; ++i)
        scanf("%lld", &c[i]);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &k[i]);
    for (int i = 0; i < n; ++i)
        items.push_back({c[i], 0, i, i});
    for (int i = 0; i < n ; ++i)
        for (int j = i+1; j < n; ++j)
            items.push_back({dst(i, j), 1, i, j});
    sort(items.begin(), items.end());
    ll sum = 0;
    for (auto it : items)
    {
        if (it.type == 0)
        {
            int li = fili(it.a);
            if (li) continue;
            else
            {
                light[it.a] = 1;
                light[fi(it.a)] = 1;
                ligh.push_back(it);
                sum += it.cst;
            }
        }
        else
        {
            int a = it.a;
            int b = it.b;
            a = fi(a);
            b = fi(b);
            if (a == b) continue;
            a = fili(it.a);
            b = fili(it.b);
            if (a && b) continue;
            pat.push_back(it);
            un(it.a, it.b);
            sum += it.cst;
        }
    }
    printf("%lld\n", sum);
    printf("%d\n", ligh.size());
    for (int i = 0; i < ligh.size(); ++i)
    {
        if (i) printf(" ");
        printf("%d", ligh[i].a + 1);
    }
    if (ligh.size()) puts("");

    printf("%d\n", pat.size());
    for (int i = 0; i < pat.size(); ++i)
    {
        printf("%d %d\n", pat[i].a+1 , pat[i].b+1);
    }

    return 0;
}
