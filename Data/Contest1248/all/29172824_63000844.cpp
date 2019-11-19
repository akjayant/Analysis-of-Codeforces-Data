#include<bits/stdc++.h>
using namespace std;
#define maxn 100008
#define int long long
int n,m;
const int mod=1e9+7;
int dp[maxn];
signed main(){
    scanf("%lld%lld",&n,&m);
    dp[1]=2;dp[2]=4;
    for(int i=3;i<=max(m,n);i++){
        (dp[i]=dp[i-1]+dp[i-2])%=mod;
    }
    cout<<(dp[n]+dp[m]-2+mod)%mod<<endl;
    return 0;
}