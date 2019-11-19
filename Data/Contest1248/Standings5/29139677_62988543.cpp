#include <bits/stdc++.h>

#define ll long long

using namespace std;
const int MX = 100'000 + 5; // check bounds!

int n;
ll c, b;

int main() {
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int i;
    for (i = 0; i < n / 2; ++i) {
        b += a[i];
    }
    for (; i < n; ++i) {
        c += a[i];
    }

    cout << c * c + b * b;
    return 0;
}
