#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define MOD 1000000007
#define printclock cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";

ll m(ll a) {
    return ((a%MOD)+MOD)%MOD;
}

ll p(ll a, ll b) {
    if (b==0) return 1ll;
    ll x = p(a, b>>1);
    if (b & 1) return m(x*m(a*x));
    return m(x*x);
}

ll dp[100005][5];

int main() {
    ll n, md;
    scanf("%lld %lld", &n, &md);
    if (n==1 && md==1) {
        printf("2\n");
        return 0;
    }
    if (n>md) swap(md, n);
    dp[2][0] = dp[2][1] = dp[2][2] = dp[2][3] = 1;
    for (int i=3; i<=md; i++) {
        dp[i][0] = dp[i-1][2];
        dp[i][1] = m(dp[i-1][2]+dp[i-1][0]);
        dp[i][2] = m(dp[i-1][1]+dp[i-1][3]);
        dp[i][3] = dp[i-1][1];
    }
    

    ll sm = 0;
    for (int i=0; i<4; i++) {
        sm = m(sm+dp[md][i]);
    }

    ll temp1 = 0;
    for (int i=0; i<4; i++) {
        temp1 = m(temp1+dp[n][i]);
    }

    // printf("sm = %lld\n", sm);

    if (n==1) {
        printf("%lld\n", sm);
    } else {
        printf("%lld\n", m(temp1+sm-2));
    }


}