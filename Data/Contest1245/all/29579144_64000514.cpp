#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define sz(x) (int)x.size()
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (__gcd(a, b) == 1)
        cout << "Finite\n";
    else
        cout << "Infinite\n";
}

signed main() {
    using namespace std;
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
