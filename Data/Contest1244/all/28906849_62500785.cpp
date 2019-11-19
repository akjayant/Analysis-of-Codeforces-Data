#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cout<<#x<<": "<<x<<endl;
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int lli;
typedef lli ll;
typedef long double ld;
typedef pair<lli, lli> pii;
typedef pair<lli, lli> plli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef vector<pair<lli, lli> > vpii;
typedef vector<pair<lli, lli> > vplli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define mod (lli)(1000*1000*1000+7)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }
template<typename T> void tracev(vector<T> &a) { for(auto &i:a) { cout<<i<<' '; } cout<<'\n'; }
template<typename T> void tracevv(vector<T> &a) { for(auto &i:a) { tracev(i); } }
template<typename T> void tracevp(vector<T> &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }


void make(vi &chain, vvi &g, int st, int par){
	chain.pb(st);
	for(int i = 0 ; i < g[st].size() ; i++){
		if(g[st][i] != par) make(chain, g, g[st][i], st);
	}
}
lli solve(vvi &c, vi &ii, vi &chain){
	lli ans = 0;
	for(lli i = 0 ; i < c[0].size() ; i++){
		ans += c[ii[i%3]][chain[i]];
	}
	return ans;
}

int main(){
	lli n;
	cin>>n;
	vvi c(3, vi(n));
	for(lli i = 0 ; i < 3 ; i++){
		for(lli j = 0 ; j < n ; j++){
			cin>>c[i][j];
		}
	}
	vvi g(n);
	for(lli i = 0 ; i < n-1 ; i++){
		lli u,v;
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}

	bool f = true;
	vlli sz(2, 0);
	ll st;
	for(lli i = 0 ; i  < n ; i++){
		if(g[i].size() > 2){
			f = false;
			break;
		}
		if(g[i].size() == 1) st = i;
		sz[g[i].size()-1]++;
	}
	if(f && sz[0] == 2 && sz[1] == n-2){
		
		lli ans = LLONG_MAX;
		vi ord = {0,1,2};
		vi sol(3);
		vi chain;
		make(chain, g, st, -1);
		do{
			lli a = solve(c, ord, chain);
			if(a <= ans){
				ans = a;
				sol = ord;
			}
		}
		while(next_permutation(ord.begin(), ord.end()));
		vpii ss(n);
		for(int i = 0 ; i < n ; i++){
			ss[i].ff = i;
			ss[chain[i]].ss = sol[i%3];
		}
		sort(ss.begin(), ss.end());
		cout<<ans<<'\n';
		for(lli i = 0 ; i < n ; i++){
			cout<<ss[i].ss+1<<' ';
		}
	}
	else{
		cout<<"-1";
	}

	return 0;
}