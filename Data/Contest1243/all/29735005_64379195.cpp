#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)

#define xx first
#define yy second
#define mp make_pair
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define vll vector<ll>
#define pdd pair<double,double>
#define ALL(v) (v).begin(), (v).end()

const ll MOD=1e9+7;
const ll inf=1e10;

#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define put(x) cout<<#x<<" = "<<x<<endl;

ll power(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a);
        n>>=1;
        a=(a*a);
    }
    return ans;
}


ll powerMod(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%MOD;
        n/=2;
        a=(a*a)%MOD;
    }
    return ans;
}

ll powerMod1(ll a,ll n,ll mod){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

ll lcm(ll a,ll b){
    return a*(b/__gcd(a,b));
}

ll sumdigit(ll n){
    ll sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}

ll countSetBit(ll a){
    return __builtin_popcount(a);
}
ll countBit(ll a){
    ll sum=0;
    while(a){
        sum++;
        a>>=1;
    }
    return sum;
}

ll length(ll a){
    ll ans=0;
    while(a){
        ans++;
        a=a/10;
    }
    return ans;
}
//~ const int sz=1e5+10;
//~ vector<ll>tr[sz];
//~ ll depth[sz];
//~ ll n,x,y;
//~ void dfs(ll start, ll par){
	//~ depth[start]=depth[par]+1;
	//~ for(auto it: tr[start]){
		//~ if(it==par)
			//~ continue;
		//~ dfs(it,start);
	//~ }
//~ }


int main()
{
    fast;
    ll t;
    cin>>t;
	//~ t=1;
    while(t--){
		ll n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		ll count=0;
		vll v;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				count++;
				v.eb(i);
			}
		}
		if(count!=0 and count!=2){
			cout<<"No"<<endl;
		}else{
			if(count==2){
				if((a[v[0]]!=a[v[1]]) or (b[v[0]]!=b[v[1]])){
					cout<<"No"<<endl;
					continue;
				}
				cout<<"Yes"<<endl;
			}
		}
			
	}
    return 0;
}
