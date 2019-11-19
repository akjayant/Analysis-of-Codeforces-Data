#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool chk(ll x) {
    for (ll d = 2; d * d <= x; d++) if (x % d == 0) return false;
    return true;
}

vector<ll> calc(ll n) {
    vector<ll> fact;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            fact.push_back(d);
            n /= d;
        }
    }
    if (n > 1) fact.push_back(n);
    return fact;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> v = calc(n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() == 1) cout << (chk(n) ? n : v[0]) << '\n';
    else cout << "1\n";
    return 0;
}