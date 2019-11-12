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
		ll ar[26]={};
		for(int i=0;i<n;i++){
			ar[a[i]-'a']++;
			ar[b[i]-'a']++;
		}
		bool yeah=true;
		
		for(int i=0;i<26;i++){
			if(ar[i]&1){
				yeah=false;
				break;
			}
		}
		if(!yeah){
			cout<<"No"<<endl;
			continue;
		}
		
		vector<pll>res;
		string na="",nb="";
		mll ma,mb;
		for(int i=0;i<n;i++){
			//~ if(a[i]!=b[i]){
				
				na+=a[i];
				ma[na.length()-1]=i;
				nb+=b[i];
				mb[nb.length()-1]=i;
			//~ }
		}
		a=na;
		b=nb;
		//ll k=2*n;
		n=a.length();
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				yeah=false;
				for(int j=i+1;j<n;j++){
					if(a[i]==a[j]){
						swap(a[j],b[i]);
						yeah=true;
						res.push_back({ma[j]+1,mb[i]+1});
						//k--;
						break;
					}else if(b[i]==b[j]){
						swap(a[i],b[j]);
						yeah=true;
						res.push_back({ma[i]+1,mb[j]+1});
						//k--;
						break;
					}
				}
				if(!yeah){
					for(int j=i+1;j<n;j++){
						if(a[i]==b[j]){
							res.push_back({ma[i]+2,mb[j]+1});
							swap(a[i+1],b[j]);
							res.push_back({ma[i]+2,mb[i]+1});
							swap(a[i+1],b[i]);
							break;
						}else if(b[i]==a[j]){
							res.push_back({ma[j]+1,mb[i+1]+1});
							swap(a[j],b[i+1]);
							res.push_back({ma[i]+1,mb[i+1]+1});
							swap(a[i],b[i+1]);
							break;
						}
					}
				}
			}
			//~ cout<<a<<" "<<b<<endl;
		}
		//~ if(a==b){
			cout<<"Yes"<<endl;
			cout<<res.size()<<endl;
			for(auto it: res){
				cout<<it.xx<<" "<<it.yy<<endl;
			}
		//~ }
		
	}
    return 0;
}
