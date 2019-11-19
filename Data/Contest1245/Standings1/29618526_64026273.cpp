#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll par[Maxn];
ll get(ll u){
	if(par[u] == u) return u;
	return par[u] = get(par[u]);
}
bool merge(ll u, ll v){
	u = get(u);
	v = get(v);
	if(u == v) return false;
	par[u] = v;
	return true;
}
ll c[Maxn], k[Maxn], x[Maxn], y[ Maxn];
vector<pll> G[Maxn];
vector< pair<ll, pll> > E;
ll dp1[Maxn], dp2[Maxn] ,pp[Maxn];;

vector<ll> V;
vector<pll> E2;

void DFS(ll u, ll p){
	dp1[u] = 0;
	dp2[u] = c[u];
	pp[u] = -1;
	for(auto ed : G[u]){
		if(ed.F == p) continue;
		DFS(ed.F, u);
		ll adj = ed.F;
		ll v = dp1[u] + dp2[adj] + ed.S;
		dp2[u] = min(dp2[u] + dp2[ed.F], ed.S + min(dp1[adj] + dp2[u], dp1[u] + dp2[adj]) );
		if(dp2[u] == v) pp[u] = adj;
		dp1[u] = min(dp1[u] + dp2[adj], dp1[u] + ed.S + dp1[adj]);
		//dp2[u] = min(dp2[u] + dp2[ed.F], ed.S + min(dp1[adj] + dp2[u], dp1[u] + dp2[adj]) );
	}
	
}

void solve2(ll u, ll p);

void solve1(ll u, ll p){
	
	for(auto ed : G[u]){
		if(ed.F == p) continue;
		ll adj = ed.F;
		if(dp2[adj] < ed.S + dp1[adj]) solve2(adj, u);
		else {
			E2.pb({u, adj});
			solve1(adj, u);
		}
	}
}
void solve2(ll u, ll p){
	if(pp[u] == -1) V.pb(u);
	
	for(auto ed : G[u]){
		if(ed.F == p) continue;
		if(ed.F == pp[u]) {
			solve2(ed.F, u);
			E2.pb({u, ed.F});
			continue;
		}
		ll adj = ed.F;
		if(dp2[adj] < ed.S + dp1[adj]) solve2(adj, u);
		else {
			E2.pb({u, adj});
			solve1(adj, u);
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	iota(par, par + Maxn, 0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> k[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			E.pb({(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}});
			
	sort(all(E));
	for(auto x : E){
		if(merge(x.S.F, x.S.S)){
			G[x.S.F].pb({x.S.S, x.F});
			G[x.S.S].pb({x.S.F, x.F});
		}
	}
	memset(dp1, 31, sizeof dp1);
	memset(dp2, 31, sizeof dp2);
	DFS(1, -1);
	solve2(1,-1);
	cout << dp2[1] << '\n';
	cout << V.size() << '\n';
	for(auto x : V) cout << x << ' '; cout << '\n';
	cout << E2.size() << '\n';
	for(auto x : E2) cout << x.F << ' ' << x.S << '\n';
	return 0;
}
