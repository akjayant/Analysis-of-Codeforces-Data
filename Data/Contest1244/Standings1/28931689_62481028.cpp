#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define r1 rt<<1
#define r2 rt<<1|1
#define ri register int
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define rep2(i,a,b,c) for(ri i=(a);i<=(b);i+=(c))
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
#define REP2(i,a,b,c) for(ri i=(a);i>=(b);i-=(c))
using namespace std;

const int N=1e5+5;
ll a[4][N],f[N][4][4];
int d[N],g[N][4][4];
vector<int> gv[N];
inline void upd(ll &x,ll y,ri u,ri j,ri k,ri l){if(y<x)x=y,g[u][j][k]=l;}
int lj,lk,res[N];
inline void dfs(ri u,ri fa,ri dep){
	if(dep==1){
		rep(j,1,3) f[u][j][0]=a[j][u];
	}
	else if(dep==2){
		rep(j,1,3)rep(k,1,3)if(j!=k){
			upd(f[u][j][k],f[fa][k][0]+a[j][u],u,j,k,0);
		}
	}
	else{
		rep(j,1,3)rep(k,1,3)if(j!=k){
			upd(f[u][6-j-k][j],f[fa][j][k]+a[6-j-k][u],u,6-j-k,j,k);
		}
	}
	rep(i,0,(int)gv[u].size()-1){
		ri v=gv[u][i];if(v==fa) continue;
		dfs(v,u,dep+1);
	}
	if(fa&&d[u]==1){
		ll ans=1e16;ri cj;
		rep(j,1,3)rep(k,1,3)if(k!=j){
			if(f[u][j][k]<ans){
				ans=f[u][j][k];
				lj=k;lk=g[u][j][k];cj=j;
			}
		}
		cout<<ans<<endl;res[u]=cj;
	}
	else res[u]=lj,lj=lk,lk=g[u][res[u]][lj];
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	ri n;cin>>n;
	rep(i,1,3)rep(j,1,n)cin>>a[i][j];
	rep(i,1,n-1){
		ri u,v;cin>>u>>v;
		gv[u].pb(v);gv[v].pb(u);
		++d[u];++d[v];
	}
	rep(i,1,n)if(d[i]>2){
		cout<<-1;return 0;
	}
	ri rt;
	rep(i,1,n)if(d[i]==1){
		rt=i;break;
	}
	rep(i,1,n)rep(j,1,3)rep(k,1,3)f[i][j][k]=1e16;
	dfs(rt,0,1);
	rep(i,1,n) cout<<res[i]<<' ';
	return 0;
}
