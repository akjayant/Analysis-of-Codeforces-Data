#include <bits/stdc++.h>
using namespace std;
#define maxn 4000005
#define ll long long

typedef pair<int, int> P;
struct edge
{
    int u, v;
    ll w;
} E[maxn];
int sz = 0;

bool cmp(edge e1, edge e2) { return e1.w < e2.w; }

int n;
ll x[maxn], y[maxn];
ll c[maxn], k[maxn];
int f[maxn];
vector<int> e;
vector<P> v;

int getf(int x) { return (f[x] == x) ? x : f[x] = getf(f[x]); }
void unite(int x, int y)
{
    x = getf(x);
    y = getf(y);
    if (x != y)
        f[y] = x;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        scanf("%lld%lld", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &c[i]);
        E[sz++] = edge{0, i, c[i]};
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld", &k[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            E[sz++] = edge{i, j, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
        }
    }
    sort(E, E + sz, cmp);
    ll ans = 0;
    for (int i = 0; i < sz; i++)
    {
        int x = E[i].u;
        int y = E[i].v;
        if (getf(x) != getf(y))
        {
            if (x == 0)
                e.push_back(y);
            else
                v.push_back(P(x, y));
            unite(x, y);
            ans += E[i].w;
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", e.size());
    for (int x : e)
        printf("%d ", x);
    printf("\n%d\n", v.size());
    for (P p : v)
        printf("%d %d\n", p.first, p.second);

    return 0;
}