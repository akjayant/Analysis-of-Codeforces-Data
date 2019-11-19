#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define pb                      push_back
#define rep(i,a,b,c)            for(ll i=(a);i<=(b);i+=(c))
#define repb(i,a,b,c)           for(ll i=(a);i>=(b);i-=(c))
#define MOD                     1000000007
#define inf                     1e18
#define ld                      long double
#define mp                      make_pair
#define vpll                    vector<pair<ll,ll>>
#define vll                     vector<ll>
#define vld                     vector<ld>
#define vvll                    vector<vector<ll>>
#define vvld                    vector<vector<ld>>
#define pll                     pair<ll,ll>
#define vvpll                   vector<vector<pair<ll,ll>>>
#define pqll                    priority_queue<ll>
#define mll                     map<ll,ll>
#define mlc                     map<ll,char>
#define um                      unordered_map
#define umll                    um<ll,ll>
#define umlc                    um<ll,char>
#define all(x)                  x.begin(),x.end()
#define fi                      first
#define se                      second
#define ln                      cout<<"\n";
#define endl                    "\n"
#define test                    ll T;cin>>T;while(T--)
#define isvowel(a)              (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define fastIO                  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define show(w,size)            for(ll i=0;i<size;i++) cout<<w[i]<<" ";
#define print(a)                cout<<a<<"\n";
#define mset(dp,no)             memset(dp,no,sizeof(dp))
#define input(a,n)              rep(i,0,n-1,1) cin>>a[i];
#define countbit                __builtin_popcount                                           //Number of setbits in decimal notation
#define lb(v,val)               lower_bound(all(v),val)-v.begin()
#define ub(v,val)               upper_bound(all(v),val)-v.begin()
#define SS                      stringstream
#define db(...)                 __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

int main()
{
	fastIO
	ll n,k;
	cin>>n>>k;
	ll a[n];
	input(a,n);
	sort(a,a+n);
	umll mp,greater,smaller;
	rep(i,0,n-1,1)
	mp[a[i]]++;
	rep(i,1,n-1,1)
	if(a[i]!=a[i-1])
	greater[a[i-1]]=a[i];
	repb(i,n-2,0,1)
	if(a[i]!=a[i+1])
	smaller[a[i+1]]=a[i];
	
	ll sm=a[0],lg=a[n-1];
	while(k>0)
	{
		if(sm>=lg)
		break;
		if(mp[sm]<mp[lg])
		{
			if((greater[sm]-sm)*mp[sm]<=k)
			{
			k-=(greater[sm]-sm)*mp[sm];
			mp[greater[sm]]+=mp[sm];
			sm=greater[sm];
			}
			else
			{
			sm=(k/mp[sm])+sm;	
			k=0;	
			}
		}
		else
		{
			if((lg-smaller[lg])*mp[lg]<=k)
			{
				k-=(lg-smaller[lg])*mp[lg];
				mp[smaller[lg]]+=mp[lg];
				lg=smaller[lg];
			}
			else
			{
				lg=lg-(k/mp[lg]);
				k=0;
			}
		}
		
	}
	cout<<lg-sm;
	
	return 0;
}
