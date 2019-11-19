#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define M 1005000
#define MOD 1000000007
#define ii pair<ll, ll>
#define iii pair<ll, ii>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

ll n, m, ans, dp[M][2][3], f[M][2][3];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    dp[1][0][1] = dp[1][1][1] = 1;
    for (int i = 2; i <= m; i++){
        dp[i][0][1] = (dp[i-1][1][1] + dp[i-1][1][2]) % MOD;
        dp[i][0][2] = dp[i-1][0][1];
        dp[i][1][1] = (dp[i-1][0][1] + dp[i-1][0][2]) % MOD;
        dp[i][1][2] = dp[i-1][1][1];
    }
    ans = (dp[m][0][1] + dp[m][0][2] + dp[m][1][1] + dp[m][1][2]) % MOD;
    f[1][0][1] = 1;
    for (int i = 2; i <= n; i++){
        f[i][0][1] = (f[i-1][1][1] + f[i-1][1][2]) % MOD;
        f[i][0][2] = f[i-1][0][1];
        f[i][1][1] = (f[i-1][0][1] + f[i-1][0][2]) % MOD;
        f[i][1][2] = f[i-1][1][1];
    }
    ans += 2*(f[n][0][1] + f[n][0][2] + f[n][1][1] + f[n][1][2]) - 2;
    ans = (ans + MOD) % MOD;
    cout << ans;
    return 0;
}
