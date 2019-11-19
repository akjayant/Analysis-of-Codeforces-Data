// TY Swistakk 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
typedef long double ld;
 
const ll N = 100050;
const ll N1 = 100500;
const ll mod = 1000000007;
 
using namespace std;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif
struct Edge {
    ll u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
ll p[N];
vector <pair <ll, ll>> xd;
vector <ll> c, k;
ll mat[2050][2050];
ll n;
vector <Edge> lados;
vector <pair <ll, ll>> gg;
vector <ll> posi;

ll fin(ll u){
	if(u == p[u]) return u;
	else return p[u] = fin(p[u]);
}
void unio(ll a, ll b){
	ll x = fin(a);
	ll y = fin(b);

	if(x != y) p[x] = y;  
}

ll abso(ll a){
	if(a < 0) return -a;
	else return a;
}
void wea(){
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(i != j) {mat[i][j] = (k[i - 1] + k[j - 1]) * (abso(xd[i - 1].ff - xd[j - 1].ff) + abso(xd[i - 1].ss - xd[j - 1].ss));}
		}
	}

	for(ll i = 1; i <= n; i++){
		mat[i][0] = c[i - 1];
		mat[0][i] = c[i - 1];
	}
}

int main(){
    fastio;
    cin >> n;
    for(ll i = 0; i < N; i++) p[i] = i;
    for(ll i = 0; i < n; i++){
    	ll a, b;
    	cin >> a >> b;

    	xd.push_back({a, b});
    }

    for(ll i = 0; i < n; i++){
    	ll a;
    	cin >> a;
    	c.push_back(a);
    }
    for(ll i = 0; i < n; i++){
    	ll a;
    	cin >> a;
    	k.push_back(a);
    }

    wea();

   

    ll answer = 0;

    for(ll i = 0; i <= n; i++){
    	for(ll j = 0; j <= n; j++){
    		if(i != j) {
    			Edge aea;
    			aea.u = i; aea.v = j; aea.weight = mat[i][j];
    			lados.push_back(aea);
    		}
    	}
    }

    sort(lados.begin(), lados.end());
    ll l = lados.size();
    ll contador = 0;
    for(ll i = 0; i < l; i++){
    	Edge tmr = lados[i];
    	if(fin(tmr.u) != fin(tmr.v)){
    		contador++;
    		answer += tmr.weight;
    		gg.push_back({tmr.u, tmr.v});
    		unio(tmr.u, tmr.v);
    	}
    	if(contador == n) break;
    }

    for(ll i = 0; i < n; i++){
    	if(gg[i].ff == 0 or gg[i].ss == 0) posi.push_back(gg[i].ff + gg[i].ss);
    }
    sort(posi.begin(), posi.end());
    l = posi.size();
    cout << answer << endl;
    cout << l << endl;
    for(ll i = 0; i < l; i++) cout << posi[i] << " ";
    	cout << endl;
    cout << n - l << endl;
    for(ll i = 0; i < n ; i++){
    	if(gg[i].ff == 0 or gg[i].ss == 0) continue;
		cout << gg[i].ff << " " << gg[i].ss << endl;
 
    }

}