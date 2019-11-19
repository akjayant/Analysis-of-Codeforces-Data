#include<bits/stdc++.h>
const int Mx=1e6+10;
const long long Mod=1e9+7;
int n,m;
long long dp[Mx];
int main(){
    scanf("%d%d",&n,&m);
    int mx=std::max(n,m);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=mx;i++)
        dp[i]=(dp[i-1]+dp[i-2])%Mod;
    printf("%lld",(dp[n]*2+dp[m]*2-2)%Mod);
}