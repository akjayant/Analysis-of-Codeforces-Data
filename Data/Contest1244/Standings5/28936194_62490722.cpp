#include<bits/stdc++.h>

#define hell                         1000000007
#define lcm(a,b)                     ((a*b)/__gcd(a,b))
#define ll                           long long
#define vll                          vector<ll>
#define vi                           vector<int>
#define pll                          vector< pair<ll,ll> >
#define pb                           push_back
#define mp                           make_pair
#define all(v)                       v.begin(),v.end()
#define lbnd                         lower_bound
#define ubnd                         upper_bound
#define bs                           binary_search
#define F                            first
#define S                            second
#define rep(i,a,b)                   for(i=a;i<b;i++)
#define parr(a,n)                    for(ll it=0;it<n;it++) cout<<a[it]<<" ";cout<<endl;
#define pcont(a)                     for(auto it:a) cout<<it<<" ";cout<<endl;
#define ret(x)                       return cout<<x,0;
#define endl                           '\n'

/*constants*/
#define MAXN                         100005
#define PI                           3.14159265358979323846

/*debug*/
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>void __f(const char* name, Arg1&& arg1){ std::cout << name << " : " << arg1 << '\n';}
    template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ','); std::cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);}
#else
#define trace(...)
#endif

using namespace std;
vll adj[MAXN],v;
ll c[MAXN][3],vis[MAXN],deg[MAXN];
void dfs(ll u){
	vis[u]=1;
	v.pb(u);
	for(auto it:adj[u]){
		if(!vis[it]) dfs(it);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll i,j,n,m,k,cnt=0,ans=0,t=1;
	cin>>n;
	rep(j,0,3){
		rep(i,1,n+1) cin>>c[i][j];
	}
	rep(i,0,n-1){
		cin>>j>>k;
		adj[j].pb(k);
		adj[k].pb(j);
		deg[j]++,deg[k]++;
	}
	ll st,st1,st2;
	rep(i,1,n+1){
		if(deg[i]>2) ret(-1)
		if(deg[i]==1) st=i;
	}
	ans=LLONG_MAX;
	dfs(st);
	// pcont(v)
	rep(i,0,3){
		rep(j,0,3){
			ll val=c[v[0]][i]+c[v[1]][j];
			ll pr=j,ppr=i;
			rep(k,2,n){
				ll nc;
				rep(m,0,3){
					if(m!=pr && m!=ppr) val+=c[v[k]][m],nc=m;
				}
				ppr=pr,pr=nc;
			}
			if(val<ans){
				ans=val;
				// trace(ans,v[0],v[1],i,j);
				st1=i;
				st2=j;
			}
		}
	}
	ll out[n+1];
	out[v[0]]=st1,out[v[1]]=st2;
	ll pr=st2,ppr=st1;
	// trace(st1,st2);
	rep(i,2,n){
		// trace(i,pr,ppr);
		rep(j,0,3){
			if(j!=pr && j!=ppr){
				out[v[i]]=j;
				ppr=pr;
				pr=j;
				break;
			}
		}
		// trace(i,pr,ppr);
	}
	cout<<ans<<endl;
	rep(i,1,n+1) cout<<out[i]+1<<" ";
	return 0;
}