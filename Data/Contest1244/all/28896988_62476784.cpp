#include<bits/stdc++.h>
#define REP(i,j,k) for(int i=j;i<k;++i)
#define RREP(i,j,k) for(int i=(int)j-1;i>=k;--i)
#define int long long
#define pb emplace_back
#define P pair<int,int>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define sz(a) (int)(a).size()
#define MX 100005
#define oo 1e18
#define L d*2
#define R (d*2+1)
#define mid (l+r>>1)
#define Ls l,mid,d*2
#define Rs mid+1,r,d*2+1
#define MIN(x,y) (x=min(x,(y)))
#define MAX(x,y) (x=max(x,(y)))
#define mo (int)(1e9+7)
#define IOS cin.tie(0) ,cout.tie(0), cout.sync_with_stdio(0)
using namespace std;
int n,c[3][MX],a,b,s,p[3]={0,1,2},ans = oo,ap[3],aa[MX];
vector<int> G[MX],co[3];
void dfs(int v,int p,int d){
	co[d].pb(v);
	for(auto u:G[v]) if(u!=p) dfs(u,v,(d+1)%3);
}
main(){
	IOS;
	cin>>n;
	REP(j,0,3) REP(i,1,n+1) cin>>c[j][i];
	REP(i,1,n) cin>>a>>b,G[a].pb(b),G[b].pb(a);
	REP(i,1,n+1){
		if(sz(G[i])>2) return cout<<-1,0;
		if(sz(G[i])==1) s = i;
	}
	dfs(s,s,0);
	do{
		int cnt = 0;
		REP(i,0,3) for(auto u:co[i]) cnt += c[p[i]][u];
		if(cnt<ans){
			ans = cnt;
			REP(i,0,3) ap[i] = p[i];
		}
	}while(next_permutation(p,p+3));
	cout<<ans<<"\n";
	REP(i,0,3) for(auto u:co[i]) aa[u] = ap[i]+1;
	REP(i,1,n+1) cout<<aa[i]<<" ";
}


