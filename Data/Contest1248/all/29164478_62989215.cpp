#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#define int long long
using namespace std;

using ll = long long;

const int MAXN = 100005;
const ll MOD = (ll)1e9 + 7;
ll dp[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i] = (dp[i-2] + dp[i-1]) % MOD;
    }
    ll n, m;
    cin >> n >> m;
    cout << (2 * dp[n] % MOD + 2 * dp[m] % MOD - 2 + MOD) % MOD << endl;
}
