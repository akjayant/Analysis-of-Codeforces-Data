#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long 
#define mod 1000000007

using namespace std;

int n;
string s;
ll dp[100100];

int main() {
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;
    n = s.size();
    s = '+' + s;

    for (int i = 1; i <= n; i++)
        if (s[i] == 'm' || s[i] == 'w')
            return cout << 0, 0;

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] != 'u' && s[i] != 'n') {
            dp[i] = dp[i - 1];
            continue;
        }

        if (s[i] == 'u') {
            dp[i] = dp[i - 1];
            if (i > 1 && s[i - 1] == 'u')
                dp[i] += dp[i - 2];

            dp[i] %= mod;
        } 

        if (s[i] == 'n') {
            dp[i] = dp[i - 1];
            if (i > 1 && s[i - 1] == 'n')
                dp[i] += dp[i - 2];
            
            dp[i] %= mod;
        }
    }

    cout << dp[n];

    return 0;
}