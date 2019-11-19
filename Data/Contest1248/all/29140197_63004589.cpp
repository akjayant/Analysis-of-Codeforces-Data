#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int MAXN = 1e6+10;
const double EPS = 1e-12;
const int mod = 1e9+7;

ll n,m;
ll dp[MAXN][2];

void init(){
    for(int i=0;i<1e6;i++)dp[i][1]=dp[i][0]=0;
    dp[0][0]=1;
    for(int i=1;i<1e6;i++){
        dp[i][1]=dp[i-1][0];
        dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
    }
}

int main()
{
    scanf("%lld %lld",&n,&m);
    init();
    ll ans=(dp[n-1][1]+dp[n-1][0]+dp[m-1][1]+dp[m-1][0]-1)%mod*2%mod;
    printf("%lld\n",ans);
}
