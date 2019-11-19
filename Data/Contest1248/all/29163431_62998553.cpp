#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define double long double
#define fi first
#define se second
#define INF 1e9
#define N 100005

ll dp[N][2];

int main(){
    int n , m;
    cin >> n >> m;
    ll ans = 0;

    if(n == 1){
        ans += 2;
    }
    else{
        memset(dp , -1 , sizeof dp);
        dp[n - 1][1] = dp[n - 1][0] = 2;
        dp[n - 2][1] = dp[n - 2][0] = 3;

        for(int i = n - 3 ; i >= 1 ; i --){
            dp[i][1] = dp[i + 1][0] + dp[i + 2][0];
            dp[i][0] = dp[i + 1][1] + dp[i + 2][1];
            dp[i][1] %= mod;
            dp[i][0] %= mod;
        }

        ans += dp[1][0] + dp[1][1];
        ans %= mod;
    }

    if(m == 1){
        ans += 2;
    }
    else{
        memset(dp , -1 , sizeof dp);
        dp[m - 1][1] = dp[m - 1][0] = 2;
        dp[m - 2][1] = dp[m - 2][0] = 3;

        for(int i = m - 3 ; i >= 1 ; i --){
            dp[i][1] = dp[i + 1][0] + dp[i + 2][0];
            dp[i][0] = dp[i + 1][1] + dp[i + 2][1];
            dp[i][1] %= mod;
            dp[i][0] %= mod;
        }

        ans += dp[1][0] + dp[1][1];
        ans %= mod;
    }

    ans -= 2;
    if(ans < 0)
        ans += mod;
    cout << ans << endl;
    return 0;
}
