/* ****revpro**** */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl	   '\n'
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)    
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mii	    map<ll,ll>
using namespace std;

#define N  100005
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;  
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 
ll add(ll x,ll y,ll mod) { x += y; if(x >= mod) x -= mod; return x;}
ll sub(ll x,ll y,ll mod=hell) { x -= y; if(x < 0) x += mod; return x;}
ll mul(ll x,ll y,ll mod) { return (x * 1ll * y) % mod;}
ll expo(ll base, ll exponent, ll mod=hell) {								//return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	while(TESTS--)
	{
		ll n,m;
		cin>>n>>m;
		cout<<expo(sub(expo(2,m),1),n);
	}
	return 0;
}