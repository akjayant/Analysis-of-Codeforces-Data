// qdd on Oct 20, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sq(ll x) { return x * x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int p = n / 2;
    cout << sq(accumulate(a.begin(), a.begin() + p, 0)) + sq(accumulate(a.begin() + p, a.end(), 0)) << '\n';
    return 0;
}