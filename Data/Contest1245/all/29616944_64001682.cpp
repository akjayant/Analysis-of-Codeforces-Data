#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
char s[100005];
int dp[100005];
int main() {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < 100005; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    scanf("%s", s);
    int n = strlen(s);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            printf("0");
            return 0;
        }
        if (s[i] == 'u' || s[i] == 'n') {
            int cnt = 1;
            for (; i + 1 < n; i++) {
                if (s[i] != s[i + 1]) break;
                cnt++;
            }
            ans = ans * dp[cnt] % mod;
        }
    }
    printf("%lld", ans);
}