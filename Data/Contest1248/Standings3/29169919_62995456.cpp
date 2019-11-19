#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
ll dp[MAXN];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    dp[1]=2;
    dp[2]=4;
    for(int i=3;i<=100000;++i)
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    printf("%lld\n",(dp[n]+dp[m]-2)%MOD);
    return 0;
}