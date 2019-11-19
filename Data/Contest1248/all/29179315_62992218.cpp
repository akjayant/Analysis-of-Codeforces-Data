#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;


const int inf = (int) 1e9;
const int mod = 1e9 + 7;
const int max_n = 1e5;

#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()

ll dp[max_n][2];
ll first[max_n][2];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    first[0][1] = 1;
    for (int i = 1; i < m; ++i) {
        first[i][0] = first[i - 1][1];
        first[i][1] = first[i - 1][0] + first[i - 1][1];
        first[i][1] %= mod;
    }
    ll ans = first[m - 1][0] * 2 + first[m - 1][1] * 2 - 2;
    ans %= mod;
    dp[0][1] = 2;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1] + ans) % mod;
    return 0;
}