// Do you knOW what it feels like?
 
		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.
 
// I BeG you to KILL me, pleASE...
 
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define SZ(x) (long long)(x.size())
#define all(x) x.begin(),x.end()

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

const ll maxn=2e3+10, LG=18, mod=1e9+7, inf=1e18;

ll x[maxn],y[maxn];
ll n,c[maxn],k[maxn];

ll par[maxn];
ll gpar(ll v){ return (par[v]==v ? v:par[v]=gpar(par[v])); }
void mrg(ll v,ll u){
	v=gpar(v), u=gpar(u);
	if(c[v]>c[u]) swap(v,u);
	par[u]=v;
}

bool is[maxn];

int main(){
	//ios_base::sync_with_stdio(0);cin.tie(0);
	
	for(int i=0;i<maxn;i++) par[i]=i;

	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]), is[i]=1;
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]), ans+=c[i];
	for(int i=1;i<=n;i++) scanf("%lld",&k[i]);
	vector<pair<ll,pll>> s;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
		s.pb({(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]),{i,j}});
	
	sort(all(s));

	vector<pll> e;
	for(auto X:s){
		ll tool=X.F, v=gpar(X.S.F), u=gpar(X.S.S);
		if(c[v]>c[u]) swap(v,u);
		if(v==u || ans<ans-c[u]+tool) continue;
		is[u]=0; /// oskol ahmagh bishoor kesafat palasht
		e.pb({X.S.F,X.S.S});
		ans=ans-c[u]+tool;
		mrg(v,u);
	}
	printf("%lld\n",ans);
	printf("%lld\n",n-SZ(e));
	for(int i=1;i<=n;i++) if(is[i]) printf("%lld ",i); 
	printf("\n");
	printf("%lld\n",SZ(e));
	for(auto X:e) printf("%lld %lld\n",X.F,X.S);
	

	return 0;
}































