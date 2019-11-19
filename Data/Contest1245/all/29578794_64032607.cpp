#include <bits/stdc++.h>
  
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   
typedef long long ll;
typedef long double ld;
    
using namespace std;

struct h{
	ll x, y, c, k, it;
};

bool operator<(h a, h b){
	return a.c < b.c;
}

bool comp(h a, h b){
	return a < b;
}

const ll min_inf = 1e18 + 7;

vector<ll> hram;
set<pair<ll, ll>> reb;
vector<ll> par;
vector<h> v;
ll ans = 0;

ll get(ll a){
	if (a == par[a]) return a;
	return par[a] = get(par[a]);
}

void union_sets(pair<ll, pair<ll, ll>> a){
	if (get(a.snd.fst) != get(a.snd.snd)){
		ll fst = get(a.snd.fst);
		ll snd = get(a.snd.snd);
		if (v[fst].c > v[snd].c)
			swap(fst, snd);
		if (v[snd].c > a.fst){
			ans -= v[snd].c;
			ans += a.fst;
			hram[snd] = 0;
			par[snd] = fst;
			reb.insert(a.snd);	
		}
	}
}

signed main(){
    ios;
    ll n;
    cin >> n;
    v.resize(n);
    hram.resize(n);
    for (int i = 0; i < n; i++)
    	hram[i] = 1;
    for (ll i = 0; i < n; i++){
    	cin >> v[i].x >> v[i].y;
    	v[i].it = i + 1;
    }
    for (ll i = 0; i < n; i++){
    	cin >> v[i].c;
    }
    for (ll i = 0; i < n; i++){
    	cin >> v[i].k;
    }
    sort(v.begin(), v.end());
    par.resize(n);
    for (int i = 0; i < n; i++)
    	par[i] = i;
    ll dist[n];
    for (ll i = 0; i < n; i++){
    	dist[i] = v[i].c; 
    	ans += dist[i];
    }
    vector<pair<ll, pair<ll, ll>>> e;
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++){
    		if (i == j){
    			continue;
    		}
    		e.pb({(v[i].k + v[j].k) * (abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y)), {i, j}});
    	}
    }
    sort(e.begin(), e.end());
    for (auto u : e){
    	union_sets(u);
    }
    cout << ans << endl;
    ll cnt = 0;
    for (ll i = 0; i < n; i++){
    	if (hram[i]){
    		cnt++;
    	}
    }
    cout << cnt << endl;
    for(ll i = 0; i < n; i++){
    	if (hram[i])
    		cout << v[i].it << ' ';
    }
    cout << endl;
    cout << reb.size() << endl;
    for (auto u : reb){
    	cout << v[u.fst].it << ' ' << v[u.snd].it << endl;
    }
}