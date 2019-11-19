#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
typedef long long ll;
const int maxn=(int)2e5+100;
const int mod=(int)1e9+7;
int n,m;
ll dp[maxn];
void precal(){
    dp[1]=2;dp[2]=2;
    rep(i,3,(int)1e5) dp[i]=(dp[i-1]+dp[i-2])%mod;
    rep(i,2,(int)1e5) dp[i]=(dp[i]+dp[i-1])%mod;
}
int main(){
    precal();
    scanf("%d%d",&n,&m);
    printf("%lld\n",(dp[n-1]+dp[m-1]+2)%mod);
}