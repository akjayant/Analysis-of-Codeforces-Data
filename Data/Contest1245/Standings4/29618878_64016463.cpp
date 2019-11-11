#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const ll MAXN = 2e5;
ll d[MAXN];

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll M = 1e9 + 7;
ll f[MAXN];

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll i = 0;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (ll i = 3; i < MAXN; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= M;
    }
    ll res = 1;
    while (i < s.size()) {
        ll u = 0, n = 0;
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
        if (s[i] != 'u' && s[i] != 'n') {
            i++;
            continue;
        }
        while (i < s.size() && s[i] == 'u') {
            i++;
            u++;
        }
        while (i < s.size() && s[i] == 'n') {
            n++;
            i++;
        }
        res *= f[n];
        res %= M;
        res *= f[u];
        res %= M;
    }
    cout << res;
}