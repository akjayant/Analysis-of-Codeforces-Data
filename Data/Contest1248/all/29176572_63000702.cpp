#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const mod = pow(10,9)+7;

ll func(ll m,ll i,ll c,ll p,ll dp[][2][3])
{
    if(i==m)
        return 1;
    
    ll ans=0;
    if(dp[i][p][c]!=-1)
       return dp[i][p][c]%mod;
    ll oldc=c;
    if(p==0)
    {
       // ll oldc=c;
        c++;
        if(c==2)
            ans=(ans+func(m,i+1,0,1,dp))%mod;
        else
        {
            ans=(ans+(func(m,i+1,c,0,dp)+func(m,i+1,0,1,dp))%mod)%mod;
        }
        dp[i][p][c-1]=ans%mod;
    }
    else
    {
     //   ll old c=c;
        c++;
        if(c==2)
            ans=(ans+func(m,i+1,0,0,dp))%mod;
        else
        {
            ans=(ans+(func(m,i+1,c,1,dp)+func(m,i+1,0,0,dp))%mod)%mod;
        }
        dp[i][p][c-1]=ans%mod;
    }
    return dp[i][p][c-1]%mod;
}

int main()
{
    ll t;
    //cin>>t;
   // while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll dp[100001][2][3];
        memset(dp,-1,sizeof(dp));
        ll ans1=(func(m,1,0,0,dp)+func(m,1,0,1,dp))%mod;
        memset(dp,-1,sizeof(dp));
        ll ans2=(func(n,1,0,0,dp)+func(n,1,0,1,dp))%mod;
       // cout<<ans1<<" "<<ans2<<endl;
        cout<<(ans1+ans2-2+mod)%mod<<endl;
        
    }
    return 0;
}
