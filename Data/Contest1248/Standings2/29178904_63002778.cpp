#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long ll;
const ll mod = 1e9+7;
ll a[maxn];
ll dp[4];
void init()
{
    a[1] = 2;
    a[2] = 4;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    int tmp[4];
    for(int i = 3;i<maxn;i++)
    {
        // cout<<" i "<<i<<endl;
        tmp[0] = dp[2];
        tmp[1] = (dp[0] + dp[2])%mod;
        tmp[2] = (dp[1] + dp[3])%mod;
        tmp[3] = dp[1];
        for(int j =0;j<4;j++)dp[j] = tmp[j];
        a[i] = (dp[0] + dp[1] + dp[2] + dp[3])%mod;
    }
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    // cout<<" an = "<<a[n]<<endl;
    ll ans = (a[n] + a[m] - 2+mod)%mod;
    ans = (ans + mod)%mod;
    printf("%I64d\n",ans);
}