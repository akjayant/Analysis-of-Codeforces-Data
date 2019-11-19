#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=1e9+7;
ll dp[maxn][3][3];//1:前面同色 0:前面无同色
int main(){
    int n,m;
    cin>>n>>m;
    if(n<m)swap(n,m);
    dp[1][0][0]=dp[1][1][0]=1;
    dp[1][0][1]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++){
        dp[i][0][0]=(dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][0][1]=dp[i-1][0][0]%mod;
        dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][0][1])%mod;
        dp[i][1][1]=dp[i-1][1][0]%mod;
    }
    ll ans1=(dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1])%mod;
    ll ans2=(dp[m][0][0]+dp[m][0][1]+dp[m][1][0]+dp[m][1][1])%mod;
    ll ans=(ans1+ans2-2)%mod;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
}





