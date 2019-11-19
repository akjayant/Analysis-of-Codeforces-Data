#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    int a = 0, b = 0;
    int mx = n / 2;
    for (int i = 0; i < mx; i++)
        a += v[i];
    for (int i = mx; i < n; i++)
        b += v[i];
    cout << a * a + b * b;

}