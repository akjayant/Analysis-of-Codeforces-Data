//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 2020;
const ll mod = 1e9+7;

ll n;
ll x[maxn], y[maxn];
ll c[maxn], k[maxn];

ll par[maxn], siz[maxn], minn[maxn];
vector<pair<ll,ll>> edg_ans;
ll cost;

ll get_par(ll v)
{
    while(v != par[v])
        v = par[v];
    return v;
}

void dsu(ll u, ll v, ll w)
{
    ll u1 = u, v1 = v;

    u = get_par(u);
    v = get_par(v);

    if(u == v) return;
    if(siz[u] > siz[v]) swap(u,v);

    if(c[minn[u]]+c[minn[v]] > min(c[minn[v]],c[minn[u]]) + w)
    {
        par[u] = v;
        siz[v] += siz[u];
        if(c[minn[u]] < c[minn[v]])
            minn[v] = minn[u];
        edg_ans.push_back({u1,v1});
        cost += w;
    }
}

vector<pair<ll,pair<ll,ll>>> edge;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(ll i = 1; i <= n; i++){
        cin>> x[i] >> y[i];
        par[i] = i;
        siz[i] = 1;
    }
    for(ll i = 1; i <= n; i++){cin>> c[i]; minn[i] = i;}
    for(ll i = 1; i <= n; i++) cin>> k[i];

    for(ll i = 1; i <= n; i++)
        for(ll j = i+1; j <= n; j++)
            edge.push_back({((k[i]+k[j])*(fabs(x[i]-x[j]) + fabs(y[i]-y[j]))), {i,j}});
    sort(edge.begin(), edge.end());

    for(ll i = 0; i < edge.size(); i++)
        dsu(edge[i].second.first, edge[i].second.second, edge[i].first);

    vector<ll> no_ans;
    for(ll v = 1; v <= n; v++)
        if(par[v] == v)
        {
            cost += c[minn[v]];
            no_ans.push_back(minn[v]);
        }

    cout<< cost <<"\n";
    cout<< no_ans.size() <<"\n";
    for(auto v : no_ans)
        cout<< v <<" ";
    cout<<"\n";
    cout<< edg_ans.size() <<"\n";
    for(auto e : edg_ans)
        cout<< e.first <<" "<< e.second <<"\n";
}