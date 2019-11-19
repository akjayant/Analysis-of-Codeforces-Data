#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define FER(i,a,b) for(ll i = ll(a); i < ll(b); ++ i)
#define IFR(i,a,b) for(ll i = ll(a); i >= ll(b); -- i)
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define ff first
#define ss second
#define tm1 ff
#define tm2 ss.ff
#define tm3 ss.ss
#define fill(x,v) memset(x,v,sizeof(x))
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqr(x) (x)*(x)
#define bas 987625403
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)

template<typename t> void fff(const char *x, t&& val1){
	cout << x << " : " << val1 << endl;
}

template<typename t1, typename... t2> void fff(const char *x, t1&& val1, t2&&... val2){
	const char *xd = strchr(x + 1, ',');
	cout.write(x, xd -x) << " : " << val1 << " | ";
	fff(xd + 1, val2...);
}

const int N = 1e5 + 2;

set<int> unv;
set<int> adj[N];

void go(int u){
	unv.erase(u);
	vector<int> toer;
	for(int v: unv){
		if(!adj[u].count(v)) toer.pb(v);
	}
	for(int v: toer) unv.erase(v);
	for(int v: toer) go(v);
}

int main(){
	fastio;
	int n, m; cin >> n >> m;
	FER(i, 1, n + 1) unv.insert(i);
	FER(i, 0, m){
		int a, b; cin >> a >> b;
		adj[a].insert(b); adj[b].insert(a);
	}
	int ans = 0;
	FER(i, 1, n + 1){
		if(unv.count(i)){
			go(i);
			ans ++;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
