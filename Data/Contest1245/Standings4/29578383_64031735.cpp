#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define endd '\n'
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test ll t;cin>>t;while(t--)
#define input freopen("inp.txt","r",stdin)
#define output freopen("out1.txt","w",stdout)
#define loop(i,n) for(ll i=0;i<n;i++)
#define rloop(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n) for(ll i=1;i<=n;i++)
#define RFOR(i,n) for(ll i=n;i>0;i--)
#define cloop(i,x,y) for(ll i=(x);i<=(y);++i)
#define bug(a) cout << #a << " = " << a << endl;
#define fbug(a, x, y) { cout << #a << ": "; cloop(i, x, y) cout << a[i] << ' '; cout << endl; }
#define sz size()
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define pi 3.14159265358979323846264338
#define mset(x,t) memset(x,t,sizeof x);
#define spa cout<<endd
#define com(x)#x
#define inf 2000
ll power(ll a , ll b,ll modi)
{
    ll res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a) % modi ;
        }
        b/=2 ;
        a = (a*a) % modi ;
    }
    return res ;
}
ll dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
ll diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
ll dx[]= {-1,1,0,0};
ll dy[]= {0,0,-1,1};
 
//*******************************TEMPLATE ENDS HERE *******************//
 
#define N 2005
ll n, m, res;
ll x[N], y[N], c[N],k[N];
vector<pll> adj[N];
vector<pair<ll,pll>> p;
ll par[N],rnk[N];
 
ll find(ll x) {
    return par[x] = (par[x] == x ? x : find(par[x]));
}
 
bool unite(ll p, ll q) {
    p = find(p);
    q = find(q);
    if(p==q)
        return false;
        
    if(rnk[p] < rnk[q]) 
        par[p] = q;
    else 
        par[q] = p;
        
    if(rnk[p] == rnk[q]) 
        rnk[p]++;
        
    return true;
}
 
map<ll, vector<ll>> um;
vector<pll> ans;
vector<ll> idx;
 
int main() { 
    fast;
	cin>>n;
	for(int i=0 ; i<n ; i++)
		cin>>x[i]>>y[i];
	for(int i=0 ; i<n ; i++)
		cin>>c[i];
	for(int i=0 ; i<n ; i++)
		cin>>k[i];
	for(int i=0 ; i<=n ; i++)
		par[i]=i;
	for(int i=0 ; i<n ; i++)
		p.pb(mp(c[i], mp(n,i)));
		
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			ll weight = (k[i]+k[j])*(abs(x[i]-x[j]) + abs(y[i]-y[j]));{
				p.pb(mp(weight, mp(i,j)));
			}
		}
	}
	
	sort(all(p));
	m = p.size();
	for(ll i=0 ; i<m ; ++i) {
        ll u = p[i].second.first;
        ll v = p[i].second.second;
        ll cur = p[i].first;
        if(unite(u,v)) {
        	if(u==n)
				idx.pb(v+1);
			else
        		ans.pb({u+1, v+1});
            res += cur;
		}  
		
    }
    
	cout<<res<<endd;
	cout<<idx.size()<<endd;
	for(auto x:idx)
		cout<<x<<" ";
	cout<<endd;
	
	cout<<ans.size()<<endd;
	for(auto x: ans){
		cout<<x.ff<<" "<<x.ss<<endd;
	}
    return 0; 
} 