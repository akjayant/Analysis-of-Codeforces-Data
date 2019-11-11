#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

char str[N];
ll dp[N];

int main() {
    dp[0] = dp[1] = 1;
    for(int i = 2; i < N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    ll ans = 1;
    scanf("%s", str);
    int n = strlen(str);
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        if(str[i - 1] == 'm' || str[i - 1] == 'w') ans = 0;
        if(str[i] == str[i - 1]) {
            cnt++;
        }
        else {
            if(str[i - 1] == 'u' || str[i - 1] == 'n') ans = ans * dp[cnt] % MOD;
            cnt = 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
