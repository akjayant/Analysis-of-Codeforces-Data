#include<bits/stdc++.h>
#define ll        	long long 
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define rrep(i,a,b) for(ll int i=a;i>=b;i--)
#define all(a)      (a).begin(),(a).end()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define tr(i, cont) for(auto i=cont.begin();i!=cont.end();i++)
#define ios        	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define trace(x)                 cerr << #x << ": " << x << "\n";
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n";
#define endl "\n"
using namespace std;

const ll N=100002;
vi adj[N];
ll r[N],g[N],b[N];
ll col[N],zz;
ll ans[6];
void dfs(ll x,ll par,ll lvl){
	// trace3(x,par,lvl);
	if(lvl%3==0){
		ans[0]+=r[x];
		ans[1]+=r[x];
		ans[2]+=g[x];
		ans[3]+=g[x];
		ans[4]+=b[x];
		ans[5]+=b[x];
	}
	else if(lvl%3==1){
		ans[0]+=g[x];
		ans[1]+=b[x];
		ans[2]+=b[x];
		ans[3]+=r[x];
		ans[4]+=r[x];
		ans[5]+=g[x];
		
	}
	else {
		ans[0]+=b[x];
		ans[1]+=g[x];
		ans[2]+=r[x];
		ans[3]+=b[x];
		ans[4]+=g[x];
		ans[5]+=r[x];
		
	}
	for(auto i:adj[x]){
		if(i==par) continue;
		dfs(i,x,lvl+1);
	}
}
void dfs2(ll x,ll par,ll lvl){
	// trace3(x,par,lvl);
	if(lvl%3==0){
		if(zz==0){
			col[x]=1;
		}
		if(zz==1){
			col[x]=1;
		}
		if(zz==2){
			col[x]=2;
		}
		if(zz==3){
			col[x]=2;
		}
		if(zz==4){
			col[x]=3;
		}
		if(zz==5){
			col[x]=3;
		}
	}
	else if(lvl%3==1){
		if(zz==0){
			col[x]=2;
		}
		if(zz==1){
			col[x]=3;
		}
		if(zz==2){
			col[x]=3;
		}
		if(zz==3){
			col[x]=1;
		}
		if(zz==4){
			col[x]=1;
		}
		if(zz==5){
			col[x]=2;
		}
		
	}
	else {
		if(zz==0){
			col[x]=3;
		}
		if(zz==1){
			col[x]=2;
		}
		if(zz==2){
			col[x]=1;
		}
		if(zz==3){
			col[x]=3;
		}
		if(zz==4){
			col[x]=2;
		}
		if(zz==5){
			col[x]=1;
		}
	}
	for(auto i:adj[x]){
		if(i==par) continue;
		dfs2(i,x,lvl+1);
	}
}
int main(){
	ios;
	ll n;
	cin>>n;
	rep(i,0,n){
		cin>>r[i];
	}
	rep(i,0,n){
		cin>>g[i];
	}
	rep(i,0,n){
		cin>>b[i];
	}
	ll x,y;
	rep(i,0,n-1){
		cin>>x>>y;
		x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool notpos=0;
	ll src=0;
	rep(i,0,n){
		// trace2(i,adj[i].size());
		if(adj[i].size()>2){
			cout<<-1;
			notpos=1;
			break;
		}
		if(adj[i].size()==1) src=i;
	}
	if(!notpos){
		dfs(src,-1,0);
		ll sol=LLONG_MAX;
		rep(i,0,6){
			if(sol>ans[i]){
				sol=ans[i];
				zz=i;
			}
			// sol=min(sol,ans[i]);
			// cout<<ans[i]<<" ";
		}
		cout<<sol<<endl;
		dfs2(src,-1,0);
		rep(i,0,n){
			cout<<col[i]<<" ";
		}
	}
}
