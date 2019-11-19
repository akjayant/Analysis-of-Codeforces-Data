#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

ll mod = 1e9+7;

ll poww( ll x, ll y )
{
    if(y==0) return 1;
    ll a = poww( x,y/2 );
    ll ans=(a*a)%mod;
    if(y%2==1) ans*=x;
    ans%=mod;
    return ans;
}

    ll dp[100010][5];

int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            ll n,m;
            cin>>n>>m;

            dp[1][1]=dp[1][2]=0;
            for(int i=2;i<=max(n,m);i++){
                dp[i][1]=(dp[i-1][1]+dp[i-1][2])%mod;
                dp[i][2]=(2+dp[i-1][1])%mod;
            }

            ll nn = dp[n][1]+dp[n][2];
            nn%=mod;
            ll mm = dp[m][1]+dp[m][2];
            mm%=mod;
            ll res=(nn+mm+2)%mod;
            cout<<res<<endl;

            return 0;
}


















