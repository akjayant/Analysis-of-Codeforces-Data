/*************************************************************************
	> File Name: 2019_10_20_3.cpp
	> Author: z472421519
	> Mail: 
	> Created Time: 2019年10月20日 星期日 17时45分14秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define MAXN 100003
#define LL long long 
const LL mod = 1e9 + 7;
using namespace std;

LL mul(LL a,LL b)
{
    LL ans=0;
    while(b)
    {
        if(b&1) ans=(ans+a)%mod;
        b>>=1;
        a=(a%mod+a%mod)%mod;
    }
    return ans;
}
LL dp[MAXN][3][3];
LL sum[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dp[1][1][1] = dp[1][0][1] = 1ll;
    dp[1][1][2] = dp[1][0][2] = 0ll;
    sum[1] = 2ll;
    for(int i = 2;i <= 100000;i++)
    {
        dp[i][1][1] = (dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
        dp[i][0][1] = (dp[i - 1][1][1] + dp[i - 1][1][2]) % mod;
        dp[i][1][2] = dp[i - 1][1][1] % mod;
        dp[i][0][2] = dp[i - 1][0][1] % mod;
        sum[i] = (dp[i][1][1] + dp[i][1][2] + dp[i][0][1] + dp[i][0][2]) % mod;
    }
    //printf("%lld\n",sum[3]);
    cout << ((sum[n] - 2 + mod) + sum[m]) % mod;

}
