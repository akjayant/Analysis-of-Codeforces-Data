#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef  long long  int ll;
typedef  long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll n,c[4][100004];
vll g[100004];
vll path;
ll mark[100004];
void dfs(ll st){
	mark[st] = 1;
	path.pb(st);
	for(ll v : g[st]) if(!mark[v]) {
		dfs(v);
	}
}
ll clr[100004];ll fin[100005];

ll get(ll c1,ll c2) {
	if(c1  > c2) swap(c1,c2);
	sll tem;tem.insert(c1);tem.insert(c2);
	rep(i,1,3) {
		if(tem.find(i) == tem.end())
			return i;
	}
}
int main() {
    ios :: sync_with_stdio(false); cin.tie(0);
    cin>>n;
    rep(i,1,3) rep(j,1,n) cin>>c[i][j];
    rep(i,1,n-1) {
    	ll u,v;cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    rep(i,1,n) {
    	if(g[i].size() >= 3) {
    		cout<<-1<<'\n';
    		return 0;
    	}
    }

    rep(i,1,n) if(g[i].size() == 1) {
    	dfs(i);
    	break;
    }
    ll ans = 1e17,c0f,c1f;
    rep(c0,1,3) rep(c1,1,3) {
    	if(c0 == c1) continue;
    	clr[0] = c0;clr[1] = c1;
    	rep(i,2,n-1) {
    		clr[i] = get(clr[i-1],clr[i-2]);
    	}
    	ll tt = 0;
    	rep(i,0,n-1) tt += c[clr[i]][path[i]];
    	if(tt <= ans) {
    		ans = tt;
    		c0f = c0;c1f=c1;
    	}
    }
    cout<<ans<<'\n';
    clr[0] = c0f;clr[1] = c1f;
	rep(i,2,n-1) {
		clr[i] = get(clr[i-1],clr[i-2]);
	}
	rep(i,0,n-1) {
		fin[path[i]] = clr[i];
	}
	rep(i,1,n) cout<<fin[i]<<" ";
	cout<<'\n';
}
