#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005],mo=1e9+7;
ll solve(ll n){
    dp[1]=1;dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=(dp[i-1]+dp[i-2])%mo;
    return dp[n]*2%mo;
}
int main(void){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    printf("%lld",(solve(n)+solve(m)-2)%mo);
    return 0;
}
