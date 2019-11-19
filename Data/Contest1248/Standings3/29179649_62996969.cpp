#include<bits/stdc++.h>
using namespace std;
long long int dp[1000010];
long long int mod = 1e9 +7;
long long int recur(long long int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(dp[n]){
        return dp[n] % mod;
    }
    dp[n] = dp[n] % mod +  recur(n - 1) % mod;
    dp[n] = dp[n] % mod ;
    dp[n] = dp[n] % mod + recur(n - 2) % mod;
    dp[n] = dp[n] % mod ;
    return dp[n] % mod;
}
int main(){
    long long int n , m , ans , ans1 , ans2;
    cin >> n >> m ;
    ans1 = recur(n);
    ans1 = ans1 * 2;
    ans1 = ans1 % mod;
    memset(dp , 0 , sizeof(dp));
    ans2 = recur(m);
    ans2 = ans2 * 2;
    ans2 = ans2 % mod;
    ans = ans1 + ans2 - 2;
    ans = ans + mod;
    ans = ans % mod;
    cout << ans ;
    return 0;
}