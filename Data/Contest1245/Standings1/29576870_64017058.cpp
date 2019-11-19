#include <bits/stdc++.h>

using namespace std;

#define MAX 2005
#define ll long long
int n;
ll dist[MAX][MAX];
ll x[MAX], y[MAX];
ll c[MAX], k[MAX];
vector<pair<ll, pair<ll, ll> > > edge;
vector<int> city;
vector<pair<int, int> > path;
int par[MAX];
ll ans = 0;

int findParent(int u)
{
    if(u == par[u]) return u;
    return par[u] = findParent(par[u]);
}

void unions(int u, int v, ll cost)
{
    int x = findParent(u);
    int y = findParent(v);
    if(x == y) return;
    ans += cost;
    if(u == 0 || v == 0){
        int mx = max(u, v);
        city.push_back(mx);
    }
    else path.push_back(make_pair(u, v));
    par[x] = y;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &x[i], &y[i]);
    }
    for(int i=1; i<=n; i++) scanf("%lld", &c[i]);
    for(int i=1; i<=n; i++){
        edge.push_back(make_pair(c[i], make_pair(0, i)));
    }
    for(int i=1; i<=n; i++) scanf("%lld", &k[i]);
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ll d = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            dist[i][j] = (k[i]+k[j])*d;
            edge.push_back(make_pair(dist[i][j], make_pair(i, j)));
        }
    }
    sort(edge.begin(), edge.end());
    for(int i=0; i<=n; i++) par[i] = i;
    for(int i=0; i<edge.size(); i++){
        ll w = edge[i].first;
        ll u = edge[i].second.first, v = edge[i].second.second;
        unions(u, v, w);
    }
    cout << ans << endl;
    cout << city.size() << endl;
    for(int i=0; i<city.size(); i++) cout << city[i] << " ";
    cout << endl;
    cout << path.size() << endl;
    for(int i=0; i<path.size(); i++) cout << path[i].first << " " << path[i].second << endl;
}