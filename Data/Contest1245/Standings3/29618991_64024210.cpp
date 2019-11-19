// dile a la jardinera que traigo flores
// corner cases // int vs ll // cin vs scanf // clear structures
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define FER(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define N 2048
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct UF{
	int p[N],power[N];
	UF(){ FER(i,0,N) power[i] = 0, p[i] = i; }
	int find(int i){ return (p[i] == i) ? i : (p[i] = find(p[i])); }
	void join(int i, int j){	
		int x = find(i), y = find(j);
		if(power[x]) power[y] = 1;
		if(power[y]) power[x] = 1;
		p[x] = y; 
	}
};

UF uf;

ll x[N],y[N],c[N],k[N];
vector<int> stat;
vector<ii> conn;
vector< pair<ll,ii> > edges;

ll getCost(int i, int j){
	long long dx = (long long) x[i] - (long long) x[j];
	long long dy = (long long) y[i] - (long long) y[j];
	return (k[i]+k[j])*(abs(dx)+abs(dy));
}

ll kruskal(int n){
	sort(edges.begin(),edges.end());
	ll ans = 0;
	for(pair<ll,ii> tup : edges){
		ll cost = tup.first;
		int u = tup.second.first, v = tup.second.second;
		int a = uf.find(u), b = uf.find(v);
		if(uf.power[a] and uf.power[b]) continue;
		if(u == v){
			stat.pb(u);
			ans += cost;
			uf.power[a] = 1;
		}else if(a != b){
			conn.pb(ii(u,v));
			ans += cost;
			uf.join(u,v);
		}
	}
	for(int i = 1; i <= n; ++i) assert(uf.power[uf.find(i)]);
	return ans;
}

int main(){

	fastio;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
		edges.pb(mp(c[i],ii(i,i)));
	}

	for(int i = 1; i <= n; ++i)
		cin >> k[i];

	for(int i = 1; i <= n; ++i){
		for(int j = i+1; j <= n; ++j){
			edges.pb(mp(getCost(i,j),ii(i,j)));
		}
	}

	cout << kruskal(n) << endl;
	cout << sz(stat) << endl;
	for(int x : stat) cout << x << " "; cout << endl;
	cout << sz(conn) << endl;
	for(ii par : conn) cout << par.first << " " << par.second << endl;

	return 0;
}
