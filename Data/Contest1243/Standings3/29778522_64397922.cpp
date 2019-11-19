#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

using namespace std;


vector<ll> dividers(ll x) {
    vector<ll> arr;
    for (ll d = 2; d <= round(sqrt(x)); d++) {
        if (x % d == 0) {
            arr.push_back(d);
            arr.push_back(x / d);
        }
    }
    return arr;
}


ll gcd(ll a, ll b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> arr = dividers(n);
    if (arr.size() == 0) {
        cout << n;
        return 0;
    }
    ll ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
        ans = gcd(ans, arr[i]);
    cout << ans;
}
