#include <bits/stdc++.h>
using namespace std;

void run();

signed main(){
    cout.setf(ios::fixed);
    cout.precision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

const int MAXN = 1e5 + 10, mod = 1e9 + 7;
long long dp[MAXN][2];

void run(){
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    for (int len = 2; len < MAXN; len++){
        dp[len][0] = dp[len - 1][0] + dp[len - 1][1];
        dp[len][1] = dp[len - 1][0];
        dp[len][0] %= mod;
        dp[len][1] %= mod;
    }
    string s;
    cin >> s;
    long long ans = 1;
    int n = s.size(), len = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'w' || s[i] == 'm')
            ans = 0;
        if (i){
            if (s[i] == 'n' || s[i] == 'u'){
                if (s[i - 1] != s[i]){
                    ans *= (dp[len][0] + dp[len][1]);
                    ans %= mod;
                    len = 0;
                }
                len++;
            }
        } else{
            if (s[i] == 'n' || s[i] == 'u')
                len++;
        }
    }
    ans *= (dp[len][0] + dp[len][1]);
    ans %= mod;
    cout << ans;
}




