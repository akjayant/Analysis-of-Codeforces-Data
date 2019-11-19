#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    if(n > m) swap(n, m);
    long long k = max(n, m);
    vector<int> dp(k+1);
    dp[0] = 2;
    dp[1] = 2;
    for(int i = 2; i <= k; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    cout << ((dp[m] - 2 + mod) % mod + (dp[n])) % mod << endl;
    return 0;
}
