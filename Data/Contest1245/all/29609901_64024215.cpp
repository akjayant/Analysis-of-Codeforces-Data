#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
#define pli pair<ll, int>
using namespace std;
const int N=4e3+1;
struct city
{
    int x, y, c, k;
} a[N];
struct edge
{
    int u, v;
    ll w;
};
vector<edge> e;
vector<pli> e1;
vector<int> e2;
vector<pii> ve2;
vector<int> ve1;
int n, root[N];
ll ans=0;
ll dist(int i, int j)
{
    return (ll)(a[i].k+a[j].k)*(ll)(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
}
int get_root(int x)
{
    while(x!=root[x]) x=root[x];
    return x;
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("sol.inp", "r", stdin);
    //freopen("sol.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1; i<=n; i++){
        cin>>a[i].c;
        e.pb({i, n+i, (ll)a[i].c});
    }
    for(int i=1; i<=n; i++){
        cin>>a[i].k;
    }
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            e.pb({i, j, dist(i, j)});
        }
    }
    for(int i=1; i<=n; i++) root[i]=i;
    for(int i=n+1; i<=2*n; i++) root[i]=n+1;
    for(int i=0; i<e.size(); i++){
        e1.pb({e[i].w, i});
    }
    sort(e1.begin(), e1.end());
    int id, u, v;
    for(int i=0; i<e1.size(); i++){
        id=e1[i].se;
        u=e[id].u;
        v=e[id].v;
        root[u]=get_root(root[u]);
        root[v]=get_root(root[v]);
        if(root[u]!=root[v]){
            e2.pb(id);
            root[root[v]]=root[u];
            root[v]=root[u];
            ans+=e[id].w;
        }
    }
    for(int i=0; i<e2.size(); i++){
        id=e2[i];
        if(e[id].u+n==e[id].v){
            ve1.pb(e[id].u);
        }
        else{
            ve2.pb({e[id].u, e[id].v});
        }
    }
    cout<<ans<<'\n';
    cout<<ve1.size()<<'\n';
    for(int i=0; i<ve1.size(); i++) cout<<ve1[i]<<" "; cout<<'\n';
    cout<<ve2.size()<<'\n';
    for(int i=0; i<ve2.size(); i++) cout<<ve2[i].fi<<" "<<ve2[i].se<<'\n';
}
