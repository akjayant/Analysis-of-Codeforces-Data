#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ordered_set tree<ll int, null_type,less<ll int>, rb_tree_tag,tree_order_statistics_node_update> 
ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll int t=1;
	//cin >> t;
	// ll int u=0;
	while(t--)
	{
		ll int n,m;
		cin >> n >> m;
		ll int dp[100001][4];
		dp[1][0]=1;
		dp[1][1]=0;
		dp[1][2]=1;
		dp[1][3]=0;
		rep(i,2,100001)
		{
			dp[i][0]=(dp[i-1][2]+dp[i-1][3])%hell;
			dp[i][1]=dp[i-1][0];
			dp[i][2]=(dp[i-1][0]+dp[i-1][1])%hell;
			dp[i][3]=dp[i-1][2];
		}
		ll int x=(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%hell;
		ll int y=(dp[m][0]+dp[m][1]+dp[m][2]+dp[m][3])%hell;
		cout << (hell+x+y-2)%hell << endl;
	}
}