#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>  
#define ll long long
#define ff first 
#define ss second
#define pb push_back
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
const ll N = 1e5 + 5;
const ll N1 = 3e5 + 5;
const ll LOGN = 17;
const ll mod = 1e9 + 7;

ll power(ll a, ll b, ll c) {
	ll ret = 1;
	while(b > 0) {
		if(b%2 == 1)
			ret = (ret * a)%c;
		b /= 2;
		a = (a * a)%c;
	}
	return ret;
}

struct DSU{
	ll par[2099];
	ll size[2099];

	void init(){
		for(ll i=0;i<2099;i++){
			par[i] = i;
			size[i] = 1;
		}
	}

	ll parent(ll n){
		while(n != par[n]){
			n = par[n];
			par[n] = par[par[n]];
		}
		return n;
	}

	void add(ll x, ll y){
		ll parx = parent(x);
		ll pary = parent(y);

		if(parx == pary) return;

		if(size[parx] < size[pary]){
			size[pary] += size[parx];
			par[parx] = pary;
		}
		else{
			size[parx] += size[pary];
			par[pary] = parx;
		}
	}

	bool isConnected(ll x,ll y){
		return (parent(x) == parent(y));
	}
}dsu;

int main() {
	ll n;
	cin >> n;

	vector < pair < ll,ll > > v(n+1);

	for(ll i=1;i<=n;i++){
		cin >> v[i].ff >> v[i].ss;
	}

	vector < ll > c(n+1),k(n+1);

	for(ll i=1;i<=n;i++){
		cin >> c[i];
	}

	for(ll i=1;i<=n;i++){
		cin >> k[i];
	}

	vector < pair < ll, pair < ll,ll > > > adj;

	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			ll pairwise = abs(v[i].ff-v[j].ff)+abs(v[i].ss-v[j].ss);
			ll dist = pairwise*(k[i]+k[j]);
			adj.pb({dist,{i,j}});
		}
	}

	for(ll i=1;i<=n;i++){
		adj.pb({c[i],{n+1,i}});
	}

	dsu.init();
	sort(all(adj));

	ll ans = 0;

	vector < ll > treeAdj[2009];
	vector <pair<ll, ll> > var;

	for(auto it : adj){
		if(dsu.isConnected(it.ss.ff,it.ss.ss)){
			continue;
		}
		dsu.add(it.ss.ff,it.ss.ss);
		treeAdj[it.ss.ff].pb(it.ss.ss);
		treeAdj[it.ss.ss].pb(it.ss.ff);
		ans += it.ff;
		if(max(it.ss.ff, it.ss.ss) != n + 1) {
			var.pb({it.ss.ff, it.ss.ss});
		}
	}
	
	cout << ans << endl;

	cout << treeAdj[n + 1].size() << endl;

	for(auto it : treeAdj[n + 1]) {
		cout << it << " ";
	}
	cout << endl;

	cout << var.size() << endl;

	for(auto it : var) {
		cout << it.ff << " " << it.ss << endl;
	}


	return 0;
}
