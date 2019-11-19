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
	test
	{
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll idx1=-1,idx2=inf;
		rep(i,0,n-1,1)
		if(s[i]=='1')
		{
		idx1=i;
		idx2=min(i,idx2);
		}
		//db(idx1,idx2);
		if(idx1==-1)
		cout<<n<<"\n";
		else
		{
			ll ans1,ans2;
			idx1++;
			ans1=idx1*2;
			idx2=n-idx2;
			ans2=idx2*2;
			cout<<max(ans1,ans2)<<"\n";
			
		}
	}
	return 0;
}
