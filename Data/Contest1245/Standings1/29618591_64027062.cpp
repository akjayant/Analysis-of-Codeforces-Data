#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define M 2005

struct edge
{
    int u, v;
    ll cost;

    bool operator<(const edge& rhs) { return cost < rhs.cost; }

} edges[M*M];

int par[M];
int xx[M], yy[M];
int cc[M], kk[M];

int rep(int x) { return par[x] == x? x: par[x] = rep(par[x]); }
void mf(int a, int b) { par[rep(a)] = rep(b); }

int main()
{
    for(int i = 0; i < M; i++) par[i] = i;

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%d %d", xx+i, yy+i);
    for(int i = 1; i <= n; i++) scanf("%d", cc+i);
    for(int i = 1; i <= n; i++) scanf("%d", kk+i);

    int tot = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            ++tot;

            ll cost = 1LL*(kk[i]+kk[j])*(abs(xx[i]-xx[j])+abs(yy[i]-yy[j]));
            edges[tot].u = i, edges[tot].v = j, edges[tot].cost = cost;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        ++tot;
        edges[tot].u = i, edges[tot].v = n+1, edges[tot].cost = cc[i];
    }

    sort(edges+1, edges+tot+1);

    vector<int> v1;
    vector<pii> v2;

    ll mot = 0;
    for(int i = 1; i <= tot; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        ll cost = edges[i].cost;

        if(rep(u) == rep(v)) continue;

        if(v == n+1) v1.push_back(u);
        else v2.push_back({u, v});

        mot += cost;
        mf(u, v);
    }

    printf("%I64d\n", mot);
    printf("%d\n", v1.size());
    for(int u: v1) printf("%d ", u);
    printf("\n%d\n", v2.size());
    for(pii p: v2) printf("%d %d\n", p.first, p.second);

    return 0;
}
