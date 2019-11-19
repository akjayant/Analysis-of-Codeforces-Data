#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> i3;

ll pai[5005];
ll x[2005], y[2005], c[2005], k[2005];

ll findpai(ll u){ return pai[u] == u ? u : pai[u] = findpai(pai[u]); }
void unionset(ll x, ll y){ x = findpai(x); y = findpai(y); pai[x] = y;}

int main(){
	ll n; cin >> n;
    for(ll i = 1; i <= 2*n; i++)
        pai[i] = i;
    for(ll i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for(ll i = 1; i <= n; i++)
        cin >> c[i];
    for(ll i = 1; i <= n; i++)
        cin >> k[i];
    vector<i3> edges;
    for(ll i = 1; i <= n; i++)
        for(ll j = i+1; j <= n; j++){
            ll difx = abs(x[i] - x[j]);
            ll dify = abs(y[i] - y[j]);
            ll w = (k[i] + k[j])*(difx + dify);
            edges.emplace_back(w, i, j);
        }
    for(ll i = 1; i <= n; i++)
        edges.emplace_back(c[i], n+5, i);
    
    sort(edges.begin(), edges.end());
    vector<ll> power;
    vector<ii> connection;
    ll res = 0;
    for(auto e : edges){
        ll w, u, v; tie(w, u, v) = e;
        if(findpai(u) != findpai(v)){
            res += w;
            if(u == n+5)
                power.push_back(v);
            else
                connection.push_back({u, v});
            unionset(u, v);
        }
    }
    cout << res << endl;
    cout << power.size() << endl;
    for(ll v : power) cout << v << " "; cout << endl;
    cout << connection.size() << endl;
    for(ii p : connection) cout << p.first << " " << p.second << endl;
    
	return 0;
}
