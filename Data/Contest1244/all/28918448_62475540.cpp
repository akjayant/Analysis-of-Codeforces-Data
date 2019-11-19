#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second 
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rep(i,a,b) for( ll i = a ; i < b ; i+=1 )
#define pp pair<ll,ll> 
#define sz(v) (ll)(v.size())
#define hell (ll)1000000007
#define slld(x) scanf("%lld",&x)
const ll N = 100005 ;
vector<ll> adj[N] ;
vector<vector<ll> > cost(3,vector<ll>(N,0)) ;
ll t = 1 ;
vector<ll> v ;
void dfs(ll node,ll par){
    v.pb(node);
    for(auto i : adj[node] )
        if(i!=par)
            dfs(i,node);
}
void solve() 
{
    ll n , x , y ;
    cin >> n ;
    rep( j,0,3){
        rep(i,1,n+1){
            cin>>cost[j][i];
        }
    }
    rep( i , 1 , n ){
        cin >> x >> y ;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll root ;
    rep( i , 1 , n + 1 ){
        if(sz(adj[i])>2){
            cout << "-1\n";return;
        }
        if(sz(adj[i])==1)root=i;
    }
    dfs(root,0);
    vector<ll> a ;
    a.pb(0);
    a.pb(1);
    a.pb(2);
    ll ans = 1e18 ;
    do
    {
        ll cur = 0 ;
        rep(i,0,n){
            cur+=cost[a[i%3]][v[i]];
        }
        ans=min(ans,cur);
    }while(next_permutation(all(a)));
    a[0]=0;
    a[1]=1;
    a[2]=2;
    do
    {
		ll cur = 0 ;
		map<ll,ll> mapa ;
		rep(i,0,n){
			cur+=cost[a[i%3]][v[i]];
			mapa[v[i]]=a[i%3]+1;
		}
		if(cur==ans){
			cout << ans << "\n" ;
			rep(j,1,n+1)
				cout << mapa[j] << " " ;
			return;
		}
	}while(next_permutation(all(a)));
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    cin >> t ;
    while(t--){
        solve();
    }
    return 0 ;
}
