#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll f[100005][2][2];
ll dp[100005];
int main() {
    f[1][1][0] = 1; f[1][0][1] = 1;
    dp[1] = 2;
    for(int i = 2; i <= 100000; i++) {
        f[i][1][1] = f[i - 1][1][0];
        f[i][1][0] = (f[i - 1][0][0] + f[i - 1][0][1]) % mod;
        f[i][0][1] = (f[i - 1][1][0] + f[i - 1][1][1]) % mod;
        f[i][0][0] = f[i - 1][0][1];
        dp[i] = f[i][1][0] + f[i][1][1] + f[i][0][1] + f[i][0][0];
        dp[i] %= mod;
        //cout << f[i][1][0] + f[i][1][1] << " " << f[i][0][1] + f[i][0][0] << endl;
        //cout << dp[i] << endl;
    }
    int n, m;
    cin>>n>>m;
    ll ans = (dp[n] + dp[m] - 2 + mod) % mod;
    //ans = ans * 2 % mod;
    cout << ans << endl;
    return 0;
}
