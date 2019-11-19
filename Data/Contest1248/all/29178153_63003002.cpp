#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long dp[1000007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    long long ans=0;
    dp[0]=2;
    dp[1]=2;
    for(int i=2;i<=1000005;++i){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }
    cin>>n>>m;
    cout<<(dp[n]+dp[m]-2+mod)%mod;
    return 0;
}
