#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1e9+7;
const int MX = 1e5+7;

int n, m;
ll sol, norep;
ll a[MX][4];

int main() {
    cin >> n >> m;

    // case 1: repetitions
    // 2 = 00 3 = 11
    a[1][1] = a[1][0] = 1;
    for (int i = 2; i <= m; i++) {
        a[i][0] = (a[i - 1][1] + a[i - 1][3]) % MOD;
        a[i][1] = (a[i - 1][0] + a[i - 1][2]) % MOD;
        a[i][2] = a[i - 1][0];
        a[i][3] = a[i - 1][1];
    }
    for (int i = 0; i < 4; ++i)
        sol = (sol + a[m][i]) % MOD;

    if (n == 1) {
        cout << sol << endl;
        return 0;
    }
    // delete the simple cases
    sol = (sol - 2) % MOD;

    // case 2: no repetitions
    ll c = 0, inv = 1;
    for (int i = 2; i <= n; ++i) {
        ll saveinv = inv;
        inv = (inv + c) % MOD;
        c = saveinv;
    }

    norep = (((c + inv) % MOD) * 2) % MOD;
    sol = (sol + norep) % MOD;
    cout << sol << endl;
    return 0;
}
