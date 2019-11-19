#include<bits/stdc++.h>
#define ll long long
#define N 100050
using namespace std;
ll mod =1e9 + 7;
ll dp[N][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    dp[1][0]=1;
    for(int i=2;i<=max(n,m);i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        if(dp[i][0]>=mod)dp[i][0]-=mod;
        dp[i][1]=dp[i-1][0];
    }
    ll ans=dp[m][0]+dp[m][1];
    if(ans>=mod)ans-=mod;
    ans--;
    if(ans<0)ans+=mod;
    ans+=dp[n][0]+dp[n][1];
    ans%=mod;
    ans--;
    if(ans<0)ans+=mod;
    ans+=ans;
    ans%=mod;
    ans+=2LL;
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<ans;
}
