#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e5+7;
const int mod = 1e9+7;
ll n,m,ans;
ll dp[N];
int main()
{
    scanf("%lld%lld",&n,&m);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=5;
    for(int i=5;i<=max(n,m);i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    ans=(dp[n]-1+dp[m]-1+mod+mod)%mod*2%mod;
    ans=(ans+2)%mod;
    printf("%lld\n",ans);
}
