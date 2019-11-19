//BADBUOY//
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ll    long long
#define ld    long double
#define sz(s) (ll)s.size() 
#define vl    vector < ll >
#define pll   pair < ll, ll >
#define ml    map < ll, ll >
#define MOD   1000000007
#define MAXN  50005 
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define inv(i,a,b)  for(ll i=a;i>=b;i--)
#define all(a)  (a).begin(),(a).end()
using namespace std;

ll t,n,m,k,x,y,z,a[500005][3],b[100005][3][3],p,q,r,deg[100005],ans=1e17,val,s,co[100005];
vector<ll> v[100005];

void dfs(ll node,ll ch){
	t=node;
	if(ch!=-1){
		rep(i,0,3)
			rep(j,0,3){
				if(i==j) b[node][i][j]=1e18;
				else b[node][i][j]=b[ch][j][3-i-j]+a[node][i];
			}
	}
   for(auto i:v[node]){
   		if(i==ch) continue;
        dfs(i,node);
   }

}

void dfs2(ll node,ll par,ll rr,ll ss){
	co[node]=rr;
   for(auto i:v[node]){
   		if(i==par) continue;
        dfs2(i,node,ss,(3-rr-ss));
   }
}

int main(){
	IOS;
	cin>>n;
	rep(i,0,n) cin>>a[i][0];
	rep(i,0,n) cin>>a[i][1];
	rep(i,0,n) cin>>a[i][2];
	rep(i,0,n-1){
		cin>>x>>y;
		x--,y--;
		deg[x]++,deg[y]++;
		if(deg[x]>2||deg[y]>2) z=1;
		v[x].pb(y);
		v[y].pb(x);
	}
	if(z) cout<<-1,exit(0);
	rep(i,0,n){
		if(deg[i]==1) val=i;
	}
	rep(i,0,3){
		rep(j,0,3){
			if(i==j) b[val][i][j]=1e18;
			else b[val][i][j]=a[val][i];
		}
	}
	dfs(val,-1);
	rep(i,0,3){
		rep(j,0,3){
		 if(ans>b[t][i][j]) ans=b[t][i][j],r=i,s=j;
		}
	}
	dfs2(t,-1,r,s);
	cout<<ans<<"\n";
	rep(i,0,n) cout<<co[i]+1<<" ";

	return 0;
}