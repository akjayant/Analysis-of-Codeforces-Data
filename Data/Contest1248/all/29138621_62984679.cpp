// qdd on Oct 20, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 7;
const ll MOD = 1e9 + 7;

ll F[MAXN];

void init() {
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        F[i] = (F[i - 1] + F[i - 2]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    init();
    cout << ((F[n] + MOD - 1) * 2 % MOD + F[m] * 2 % MOD) % MOD << '\n';
    return 0;
}