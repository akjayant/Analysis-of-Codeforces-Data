#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define st string
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define endl '\n'

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen ("monotony.in", "r", stdin); freopen ("monotony.out", "w", stdout);
}

const ll N = 2e5 + 7;
const ll MOD = 1e9 + 7;

ll n, m, a[N], x, y, dp[5][N];

int main() {
    file();
    cin >> n >> m;
    if (n < m) swap(n, m);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        dp[1][i + 1] += dp[0][i];
        dp[0][i + 1] += dp[1][i] + dp[0][i];
        dp[0][i + 1] %= MOD;
        dp[1][i + 1] %= MOD;
//        cout << i << ": " << dp[0][i] << " " << dp[1][i] << endl;
    }
    ll ans = (dp[0][n - 1] + dp[1][n - 1] + dp[0][m - 1] + dp[1][m - 1]) * 2;
    cout << (ans - 2) % MOD;
}


/**
1 1 - 2
2 1 - 4
3 1 - 8
4 1 - 16
....
2 2 - 6
2 3 - 8
2 4 - ?

*/
