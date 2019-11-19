#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1 << 17;
const ll MOD = 1000000007ll;

ll dp[MAXN];

ll f(int n) {
    if (n == 0)
        return 2;
    if (n == 1)
        return 4;
    ll &ret = dp[n];
    if (ret != -1)
        return ret;
    return ret = (f(n - 1) + f(n - 2)) % MOD;
}

int main() {
    fill(dp, dp + MAXN, -1ll);
    int n, m;
    cin >> n >> m;
    cout << (f(n - 1) + f(m - 1) - 2ll + MOD) % MOD << endl;
    return 0;
}