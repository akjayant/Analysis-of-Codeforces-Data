//be name khoda
#include<bits/stdc++.h>

typedef int ll;
typedef long double ld;

using namespace std;

//const ll INF = 1e18;
const ll maxn = 100 * 1001;
const ll mod = 1e9+7;

ll n , m , k;
ll a[maxn], deg[maxn];
vector<ll> g[maxn], g1[maxn], v1, v2;
ll mark[maxn], mark1[maxn];

void dfs(ll u)
{
    mark[u] = 1;
    for(auto v : g[u])
        if(!mark[v])
            dfs(v);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>> n >> m;
    for(ll i = 0; i < m; i++)
    {
        ll u, v; cin>> u >> v;
        deg[u]++; deg[v]++;
        g1[v].push_back(u);
        g1[u].push_back(v);
    }

    ll root = 1;
    for(ll i = 1; i <= n; i++)
        if(deg[i] < deg[root])
            root = i;

    for(auto v : g1[root])
        mark1[v] = 1;
    for(ll i = 1; i <= n; i++)
    {
        if(mark1[i]) v1.push_back(i);
        else v2.push_back(i);
        mark1[i] = 0;
    }

    for(auto u : v1)
    {
        for(auto v : g1[u]) mark1[v] = 1;
        for(auto v : v1)
            if(!mark1[v])
            {
                g[v].push_back(u);
                g[u].push_back(v);
            }
        for(auto v : g1[u]) mark1[v] = 0;
    }

    for(auto v : v2)
    {
        for(auto u : g1[v]) mark1[u] = 1;

        g[root].push_back(v);
        g[v].push_back(root);
        for(auto u : v1)
            if(!mark1[u])
            {
                g[v].push_back(u);
                g[u].push_back(v);
            }
        for(auto u : g1[v]) mark1[u] = 0;
    }

    for(ll i = 1; i <= n; i++)
        if(!mark[i])
        {
            k++;
            dfs(i);
        }

    cout<< k-1;
}
