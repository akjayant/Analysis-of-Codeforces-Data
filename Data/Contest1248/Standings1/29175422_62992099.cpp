#include <iostream>
#include <vector>

using namespace std;

#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;

typedef long long ll;

int mod = 1e9 + 7;

ll f(int n) {
    if (n == 1) return 2;

    vector <ll> a00(n), a01(n), a10(n), a11(n);
    a00[1] = 1, a01[1] = 1, a10[1] = 1, a11[1] = 1;
    for (int i = 2; i < n; ++i) {
        a00[i] = a10[i - 1] % mod;
        a10[i] = (a11[i - 1] + a01[i - 1]) % mod;
        a01[i] = (a00[i - 1] + a10[i - 1]) % mod;
        a11[i] = a01[i - 1] % mod;
    }

    ll ans = a00[n - 1] + a01[n - 1] + a10[n - 1] + a11[n - 1];
    return ans % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    ll ans = (f(n) + f(m) - 2) % mod;
    cout << ans;
}
