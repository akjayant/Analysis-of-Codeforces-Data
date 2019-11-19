//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>


#define ll long long
#define ull unsigned long long
#define int ll
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}

using namespace std;

mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

typedef pair < int , int > pii ;
typedef pair < long long  , long long > pll ;
const int N = 2e5 + 123;
int n , m, k;
vector < int > gr[N];
int t[N] , val[N];

bool was[N];
int flex(int u){
	int ans = 0;
	was[u] = 1;
	set < int > st;
	for(int i = 1 ; i <= n; i++)
		if(!was[i])
			st.insert(i);

    for(int i = 1 ; i < n ; i++){
    	int uu = u;
		for(auto to : gr[uu])
			if(!was[to])
				st.erase(to);

		if(sz(st) != 0)
				u = *st.begin(),st.erase(u);
		else for(auto to : gr[uu])
					if(!was[to]){u = to,ans++;break;}
		was[u] = 1;
		for(auto to : gr[uu])
			if(!was[to])
				st.insert(to);
    }
    for(int i = 1; i <= n; i++)
    	was[i] = 0;
    return ans;
}
namespace my{
    int g[3000][3000];
	void work(){                              	
		const int INF = 1000000000;
		vector<bool> used (3000);
		vector<int> min_e (3000, INF), sel_e (3000, -1);
    	int ans = 0;
		for(int i = 1; i <= m ; i++){
			int u , v;
			cin >> u >> v;
			u--,v--;
			g[u][v] = g[v][u] = 1;
		}
		min_e[0] = 0;
		for (int i=0; i<n; ++i) {
			int v = -1;
			for (int j=0; j<n; ++j)
				if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
					v = j;
			if (min_e[v] == INF) {
				cout << "No MST!";
				exit(0);
			}
    		used[v] = true;
			if (sel_e[v] != -1)
				ans += g[v][sel_e[v]];
                
			for (int to=0; to<n; ++to)
				if (g[v][to] < min_e[to]) {
					min_e[to] = g[v][to];
					sel_e[to] = v;
			}
		}
		cout << ans;
	}
}
main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> n >> m;
	if(n <= 2500){
		my::work();
		return 0;
	}
	for(int i = 1; i <= m ; i++){
		int x , y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);				
    }
    int ans = flex(1);
    vector < pii > vc;
	for(int i = 2; i <= n ; i++){
		vc.pb({sz(gr[i]) , i});
	}    
	sort(all(vc));
	for(int i = 0 ; i < min(sz(vc) , 5ll);i++)
		ans = min(ans , flex(vc[i].se));
	cout << ans ;
}
