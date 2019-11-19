#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int powz(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*1ll*a)%mod;
		b/=2;
		a=(a*1ll*a)%mod;
	}
	return res;
}
void add(int &a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
}

int mul(int a,int b){
	return (a*1ll*b)%mod;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
	input>>x.F>>x.S;
	return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
	for(auto& i:x)
		input>>i;
	return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
	for(auto& i:x)
		output<<i<<' ';
	return output;
}

const int N=500002;

int deg[N];
vi adj[N];
vi a,b,c;
vector<int>col;
vi zz;
vi tour;
int fl=1;

ll dfs(int u,int p,int col){
	if(fl){
		tour.pb(u);
	}
	ll ans=0;
	if(zz[col%3]==0){
		ans+=a[u];
	}
	else if(zz[col%3]==1){
		ans+=b[u];
	}
	else{
		ans+=c[u];
	}
	for(auto i:adj[u]){
		if(i!=p){
			ans+=dfs(i,u,col+1);
		}
	}
	return ans;
}

void solve(){
	int n;
	cin>>n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	col.resize(n);
	cin>>a>>b>>c;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	for(int i=0;i<n;i++){
		if(deg[i]>=3){
			cout<<-1;
			return;
		}
	}
	int z=-1;
	for(int i=0;i<n;i++){
		if(adj[i].size()==1){
			z=i;
			break;
		}
	}
	ll ans=1e18;
	zz={0,1,2};
	vi azz;
	do{
		//~ ans=min(ans,dfs(z,-1,0));
		ll val=dfs(z,-1,0);
		debug(zz,val);
		if(ans>val){
			azz=zz;
			ans=val;
		}
		fl=0;
	}while(next_permutation(all(zz)));
	cout<<ans<<"\n";
	debug(tour,azz);
	for(int i=0;i<tour.size();i++){
		col[tour[i]]=azz[i%3];
	}
	for(int i=0;i<n;i++){
		cout<<col[i]+1<<' ';
	}
		
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
