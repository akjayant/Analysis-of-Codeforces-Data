#include <bits/stdc++.h>

using namespace std;

#define int long long

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

const int mod = 1e9 + 7;

int pw(int a, int n) {
    if (!n) return 1;
    if (n % 2)
        return (pw(a, n - 1) * a) % mod;
    int y = pw(a, n / 2);
    return (y * y) % mod;
}

int32_t main() {
    #ifdef THERE
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        //freopen("common.in", "r", stdin);
        //freopen("common.out", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    cout << pw(pw(2, m) - 1, n);
    return 0;
}
