//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int & i : a)
        cin >> i;

    sort(a.rbegin(), a.rend());

    ll s1 = 0, s2 = 0;

    for (int i = 0; i <= (n - 1) / 2; ++i)
        s1 += a[i];
    
    for (int i = (n - 1) / 2 + 1; i < n; ++i)
        s2 += a[i];

    cout << sqr(s1) + sqr(s2) << '\n';;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}