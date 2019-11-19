#include <bits/stdc++.h>    
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb  push_back
#define show(x) cout<<(#x)<<" : "<<x<<endl;
#define ll  long long
#define ld  long double
#define fill(a,val) memset(a,val,sizeof(a))
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ll N 	     = 501010;
const ll N2      = 1000*1000;
const ld PI  = 3.14159265;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 

signed main()
{
	//CHECK for LONG LONG and LONG DOUBLE
	//*comment for all except cc/cf	
	#ifndef ONLINE_JUDGE
	   	freopen("input.txt","r",stdin);
	   	freopen("output.txt","w",stdout);
	#endif//*/
	fastio();	
	ll n,k;
	cin>>n>>k;
	map<ll,ll> m;
	std::vector<ll> v;
	for (ll i = 0; i < n; ++i)
	{
		ll dum;
		cin>>dum;
		m[dum]++;
	}
	if(m.size()==1)
	{
		cout<<0<<endl;
		exit(0);
	}
	for(auto x : m)
	{
		//cout<<x.ff<<" "<<x.ss<<endl;
		v.pb(x.ff);
	}
	ll l = 0 , r = v.size()-1;
	while(k>0&&l!=r)
	{
		//cout<<k<<endl;
		if(m[v[l]]<m[v[r]])
		{
			ll req = v[l+1]-v[l];
			req*=m[v[l]];
			//cout<<req<<endl;
			if(k>=req)
			{
				k-=req;
				m[v[l+1]]+=m[v[l]];
				l++;
			}
			else
			{
				k/=m[v[l]];
				ll ans = v[r] - v[l] - k;
				cout<<ans<<endl;
				return 0;
			}
		}
		else
		{
			ll req = v[r]-v[r-1];
			req*=m[v[r]];

			//cout<<req<<"r"<<endl;
			if(k>=req)
			{
				k-=req;
				m[v[r-1]]+=m[v[r]];
				r--;
			}
			else
			{
				k/=m[v[r]];
				ll ans = v[r] - v[l] - k;
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	cout<<v[r]-v[l];
	return 0;
}