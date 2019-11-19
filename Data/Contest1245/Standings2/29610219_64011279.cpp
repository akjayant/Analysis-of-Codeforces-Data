#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2000;

int N;
ll X[MAXN+10], Y[MAXN+10], C[MAXN+10], K[MAXN+10], ans;

struct Edge
{
    int u, v;
    ll w;
    bool operator < (const Edge &p) { return w<p.w; }
};
vector<Edge> edge;

struct UF
{
    int par[MAXN+10];
    UF() { for(int i=0; i<=MAXN; i++) par[i]=i; }
    int Find(int x) { return x==par[x] ? x : par[x]=Find(par[x]); }
    void Union(int x, int y) { x=Find(x); y=Find(y); par[x]=y; }
}uf;

vector<int> V;
vector<pii> E;

int main()
{
    int i, j;

    scanf("%d", &N);
    for(i=1; i<=N; i++) scanf("%lld%lld", &X[i], &Y[i]);
    for(i=1; i<=N; i++) scanf("%lld", &C[i]);
    for(i=1; i<=N; i++) scanf("%lld", &K[i]);

    for(i=1; i<=N; i++) for(j=i+1; j<=N; j++) edge.push_back({i, j, (K[i]+K[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j]))});
    for(i=1; i<=N; i++) edge.push_back({0, i, C[i]});
    sort(edge.begin(), edge.end());

    for(i=0; i<edge.size(); i++)
    {
        if(uf.Find(edge[i].u)==uf.Find(edge[i].v)) continue;
        uf.Union(edge[i].u, edge[i].v);
        if(edge[i].u==0) V.push_back(edge[i].v);
        else if(edge[i].v==0) V.push_back(edge[i].u);
        else E.push_back({edge[i].u, edge[i].v});
        ans+=edge[i].w;
    }
    printf("%lld\n", ans);
    printf("%d\n", V.size());
    for(auto it : V) printf("%d ", it); printf("\n");

    printf("%d\n", E.size());
    for(auto it : E) printf("%d %d\n", it.first, it.second);
}
