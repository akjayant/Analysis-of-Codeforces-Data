#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());

    ll ans = 0;
    for(int i=n-1;i>=0;i--) {
        ll a = min(1LL*n-i,v[i]);
        ans = max(a,ans);
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }


    return 0;
}