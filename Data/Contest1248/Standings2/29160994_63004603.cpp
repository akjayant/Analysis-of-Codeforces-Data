#include <bits/stdc++.h>

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define int long long
#define endl '\n'

using namespace std;

int dp[100004][2][2];
const int mod = 1e9 + 7;

signed main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n, m, i;
    cin >> n >> m;
    dp[1][0][0] = 2;
    for (i = 2; i <= m; i++){
        dp[i][1][1] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % mod;
        dp[i][0][0] = (dp[i - 1][0][0]) % mod;
        dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1]) % mod;
    }
    int ans1_0 = dp[m][0][0], ans1_1 = 0, ans2 = (dp[m][0][1] + dp[m][1][1]) % mod;
    for (i = 1; i < n; i++){
        int new_ans1_0 = (ans1_0 + ans1_1) % mod;
        int new_ans1_1 = (ans1_0) % mod;
        ans1_0 = new_ans1_0;
        ans1_1 = new_ans1_1;
    }
    cout << (ans1_0 + ans1_1 + ans2) % mod << endl;
    return 0;
}
