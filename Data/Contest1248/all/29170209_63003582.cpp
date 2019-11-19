#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 6e5+5;
const ll mod = 1e9+7;

int n, m;
ll dp[maxn];
int main(){
    scanf("%d%d", &n, &m);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= max(n, m); i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    printf("%lld\n", (dp[n] + dp[m] - 1)*2ll % mod);
    return 0;
}
