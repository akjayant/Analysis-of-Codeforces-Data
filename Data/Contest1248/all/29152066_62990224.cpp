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
//	cin>>TESTS;
	while(TESTS--)
	{
		ll n,m;
		cin>>n>>m;
		if(n<m) swap(n,m);
		ll dp[n][4];
		dp[0][0]=1;
		dp[0][2]=1;
		dp[0][1]=0;
		dp[0][3]=0;
		rep(i,1,n){
			dp[i][0]=(dp[i-1][2]+dp[i-1][3])%hell;
			dp[i][2]=(dp[i-1][1]+dp[i-1][0])%hell;
			dp[i][1]=dp[i-1][0];
			dp[i][3]=dp[i-1][2];
		}
		ll x=0;
		rep(i,0,4) x=(x+dp[n-1][i])%hell;
		cout<<((((dp[m-1][0]+dp[m-1][1]+dp[m-1][2]+dp[m-1][3])%hell))+x-2)%hell; 
	}
	return 0;
}